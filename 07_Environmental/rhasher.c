#include <string.h>
#include "rhash.h"
#include "config.h"

#ifdef USE_READLINE
#include <readline/readline.h>
#endif

int main(int argc, char *argv[])
{
    char* line;
    char* msg;
    char* hash_type;
    char digest[64];
    char output[130];
    size_t len = 0;
    int nread;

    rhash_library_init();

    while (1)
    {
        #ifndef USE_READLINE
        nread = getline(&line, &len, stdin);
        #else
        line = readline(NULL);
        nread = line ? 0 : -1;
        #endif

        if (nread == -1)
            break;
        
        hash_type = strtok(line, " ");
        if (!hash_type)
        {
            printf("Bad line\n");
            continue;
        }
        else if (!(msg = strtok(NULL, " ")))
        {
            printf("Bad second arg\n");
            continue;
        }

        int msg_len = strlen(msg);
        
        if (msg[msg_len - 1] == '\n')
        {
            msg[msg_len - 1] = '\0';
        }

        if (!strcmp(hash_type, "md5"))
        {
            int res;
            if (msg[0] == '"')
            {
                msg = (char*)(msg + 1);
                res = rhash_msg(RHASH_MD5, msg, strlen(msg), digest);
            }
            else
                res = rhash_file(RHASH_MD5, msg, digest);
            if (res < 0)
            {
                fprintf(stderr, "Digest calculation error\n");
                continue;
            }

            rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_MD5), RHPR_BASE64);

            printf("%s\n", output);
        }
        else if (!strcmp(hash_type, "MD5"))
        {
            int res;
            if (msg[0] == '"')
            {
                msg = (char*)(msg + 1);
                res = rhash_msg(RHASH_MD5, msg, strlen(msg), digest);
            }
            else
                res = rhash_file(RHASH_MD5, msg, digest);
            if (res < 0)
            {
                fprintf(stderr, "Digest calculation error\n");
                continue;
            }

            rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_MD5), RHPR_HEX);

            printf("%s\n", output);
        }
        else if (!strcmp(hash_type, "sha1"))
        {
            int res;
            if (msg[0] == '"')
            {
                msg = (char*)(msg + 1);
                res = rhash_msg(RHASH_SHA1, msg, strlen(msg), digest);
            }
            else
                res = rhash_file(RHASH_SHA1, msg, digest);
            if (res < 0)
            {
                fprintf(stderr, "Digest calculation error\n");
                continue;
            }

            rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_SHA1), RHPR_BASE64);

            printf("%s\n", output);
        }
        else if (!strcmp(hash_type, "SHA1"))
        {
            int res;
            if (msg[0] == '"')
            {
                msg = (char*)(msg + 1);
                res = rhash_msg(RHASH_SHA1, msg, strlen(msg), digest);
            }
            else
                res = rhash_file(RHASH_SHA1, msg, digest);
            if (res < 0)
            {
                fprintf(stderr, "Digest calculation error\n");
                continue;
            }

            rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_SHA1), RHPR_HEX);

            printf("%s\n", output);
        }
        else if (!strcmp(hash_type, "tth"))
        {
            int res;
            if (msg[0] == '"')
            {
                msg = (char*)(msg + 1);
                res = rhash_msg(RHASH_TTH, msg, strlen(msg), digest);
            }
            else
                res = rhash_file(RHASH_TTH, msg, digest);
            if (res < 0)
            {
                fprintf(stderr, "Digest calculation error\n");
                continue;
            }

            rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_TTH), RHPR_BASE64);

            printf("%s\n", output);
        }
        else if (!strcmp(hash_type, "TTH"))
        {
            int res;
            if (msg[0] == '"')
            {
                msg = (char*)(msg + 1);
                res = rhash_msg(RHASH_TTH, msg, strlen(msg), digest);
            }
            else
                res = rhash_file(RHASH_TTH, msg, digest);
            if (res < 0)
            {
                fprintf(stderr, "Digest calculation error\n");
                continue;
            }

            rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_TTH), RHPR_HEX);

            printf("%s\n", output);
        }
        else
            printf("Bad hash_type\n");
    }

    return 0;
}