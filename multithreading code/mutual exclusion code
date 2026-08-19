#include <stdio.h>

int semaphore = 1;

int main()
{
    printf("process requests printer\n");
    if (semaphore > 0)
    {
        semaphore--;
        printf("process entered critical section\n");
        printf("printing document ...\n");
        semaphore++;
        printf("process exited critical section\n");
    }
    else
        printf("printer busy\n");

    return 0;
}
