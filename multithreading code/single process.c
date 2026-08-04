#include <stdio.h>
#include <pthread.h>

void *monitor(void *a) {
    printf("Monitoring: %s\n", (char *)a);
    return NULL;
}

int main() {
    pthread_t t[3];
    char *job[] = {"Temperature", "Humidity", "Rainfall"};

    for (int i = 0; i < 3; i++)
        pthread_create(&t[i], NULL, monitor, job[i]);

    for (int i = 0; i < 3; i++)
        pthread_join(t[i], NULL);

    printf("Monitoring Completed\n");
    return 0;
}
