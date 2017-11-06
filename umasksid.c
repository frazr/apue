#include "apue.h"

int main()
{
    struct stat statbuffer;

    if (stat("foo", &statbuffer) < 0)
        err_sys("stat error for foo");

    if (chmod("foo", (statbuffer.st_mode & ~S_IXGRP) | S_ISGID) < 0)
        err_sys("chmod error for foo");

    if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
        err_sys("chmod error for bar");

    exit(0);
}