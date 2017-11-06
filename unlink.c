#include "apue.h"
#include <fcntl.h>

int main()
{
    if (open("tmpfile", O_RDWR) < 0)
        err_sys("Unable to open tmpfile");
    
    if (unlink("tmpfile") < 0)
        err_sys("unable to unlink tmpfile");
    
    printf("file unlinked\n");
    sleep(15);
    printf("done\n");

    exit(0);
}