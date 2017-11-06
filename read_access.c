#include "apue.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        err_quit("Usage: ./program file");
    }

    if (access(argv[1], R_OK) < 0)
        err_ret("Access error");
    else
        printf("Read access ok\n");

    if (open(argv[1], O_RDONLY) < 0)
        err_ret("Open error for %s\n", argv[1]);
    else
        printf("Open for reading ok\n");

    exit(0);
}