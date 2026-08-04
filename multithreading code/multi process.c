#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>

void *m(void *a) {
    printf("%s\n", (char *)a);
    return NULL;
}

int main() {
    char *job[][2] = {
        {"Temperature", "Humidity"},
        {"Rainfall", "Wind Speed"},
        {"Pressure", "Alert"}
    };

    for (int i = 0; i < 3; i++) {
        if (fork() == 0) {
            pthread_t t[2];
            for (int j = 0; j < 2; j++)
                pthread_create(&t[j], NULL, m, job[i][j]);
            for (int j = 0; j < 2; j++)
                pthread_join(t[j], NULL);
            return 0;
        }
    }

    while (wait(NULL) > 0);
    printf("Monitoring Completed\n");
    return 0;
}
