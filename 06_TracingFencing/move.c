#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 2048

int main(int argc, char* argv[])
{
    char buf[SIZE];
    FILE *file1;
    FILE *file2;
    char* file_name1 = argv[1];
    char* file_name2 = argv[2];

    file1 = fopen(file_name1, "r");
    if (!file1)
    {
        puts("Error: Input file not found");
        return 1;
    }

    file2 = fopen(file_name2, "wb");
    if (!file2)
    {
        puts("Error: Output file opening error");
        fclose(file1);
        return 2;
    }

    while(!feof(file1))
    {
        fgets(buf, SIZE, file1);
        fputs(buf, file2);
    }

    fclose(file2);
    fclose(file1);

    remove(file_name1);

    return 0;
}