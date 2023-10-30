#define _GNU_SOURCE
#include <dlfcn.h>
#include <string.h>
#include <unistd.h>

typedef int (*true_remove_t)(char*);

int true_remove(char *file_name)
{
    return ((true_remove_t) dlsym(RTLD_NEXT, "remove"))(file_name);
}

int remove(char *file_name)
{
    if (strstr(file_name, "PROTECT") != NULL)
    {
        return 10;
    }
    return true_remove(file_name);
}