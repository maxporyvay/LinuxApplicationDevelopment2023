#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

#define MAXGR 100
#define ERRSIZE 100

int main(int argc, char *argv[]) {
        char* regexp = argv[1];
        char* substitution = argv[2];
        char* string = argv[3];
        char new_string[strlen(string) + strlen(substitution)];

        regex_t regex;
        regmatch_t bags[MAXGR];
        char errbuf1[ERRSIZE], errbuf2[ERRSIZE];

        int regcomp_errcode = regcomp(&regex, regexp, REG_EXTENDED);
        regerror(regcomp_errcode, &regex, errbuf1, ERRSIZE);
        if (regcomp_errcode != 0) {
                printf("RegComp error: %.*s\n", ERRSIZE, errbuf1);
                return 1;
        }

        int regexec_errcode = regexec(&regex, string, MAXGR, bags, 0);
        regerror(regexec_errcode, &regex, errbuf2, ERRSIZE);

        if (regexec_errcode == REG_NOMATCH) {
                printf("%s\n", string);
                return 0;
        }
        else if (regexec_errcode != 0) {
                printf("RegExec error: %.*s\n", ERRSIZE, errbuf2);
                return 2;
        }

        int new_string_len = bags[0].rm_so;
        strncpy(new_string, string, bags[0].rm_so);

        int match_count = 0;
        for (int i = 1; bags[i].rm_so != -1; i++)
            match_count++;
        for (int i = 0; i < strlen(substitution); i++) {
            if (substitution[i] == '\\' && i < strlen(substitution) - 1 && substitution[i + 1] < '9' && substitution[i + 1] > '0') {
                int match_num = substitution[i + 1] - '0';
                if (match_num > match_count) {
                    printf("Wrong match number: %d\n", match_num);
                    return 3;
                }
                strncpy(new_string + new_string_len, string + bags[match_num].rm_so, bags[match_num].rm_eo - bags[match_num].rm_so);
                new_string_len += bags[match_num].rm_eo - bags[match_num].rm_so;
                i++;
            }
            else {
                new_string[new_string_len] = substitution[i];
                new_string_len++;
            }
            
        }
        new_string[new_string_len] = '\0';
        printf("%s%s\n", new_string, (char *) (string + bags[0].rm_eo));
        
        regfree(&regex);

        return 0;
}