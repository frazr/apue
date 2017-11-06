#include "apue.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd;
    char buf = "?";
    size_t sz = 1;

    if (argc != 2) {
        err_quit("Usage: ./program filepath");
    }

    if ((fd = open(argv[1], O_APPEND)) < 0)
        err_sys("Unable to open file");

    lseek(fd, 0, SEEK_SET);

    if((write(fd, &buf, sz)) < 0)
        err_sys("Write error");

    close(fd);

    exit(0);
}