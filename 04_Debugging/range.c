#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc == 1)
        printf("This is a C range program (Python-like)\n");
    else
    {
        int start = 0, step = 1, stop;
        if (argc == 2)
            stop = atoi(argv[1]);
        else if (argc == 3)
        {
            start = atoi(argv[1]);
            stop = atoi(argv[2]);
        }
        else if (argc == 4)
        {
            start = atoi(argv[1]);
            stop = atoi(argv[2]);
            step = atoi(argv[3]);
        }
        else
            return 1;
        for(int i = start; i < stop; i += step)
            printf("%d\n", i);
    }
    return 0;
}