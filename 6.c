#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    printf("[ПРОЦЕСС] Мой PID: %d, PID моего родителя: %d\n\n", getpid(), getppid());

    pid_t pid = fork();
    if (pid == -1) return 1;

    if (pid > 0) {
        printf("[РОДИТЕЛЬ] Мой PID: %d, PID ребенка: %d\n", getpid(), pid);
        printf("[РОДИТЕЛЬ] Завершаю работу\n\n");
        int status;
        wait(&status);
    } else {
        printf("[РЕБЕНОК] Мой PID: %d, PID родителя: %d\n", getpid(), getppid());
        printf("[РЕБЕНОК] Завершаю работу\n\n");
    }

    pid = fork();
    if (pid == -1) return 1;

    if (pid > 0) {
        for (int i = 1; i <= 3; i++) {
            printf("[РОДИТЕЛЬ] Счет: %d\n", i);
            sleep(1);
        }
        printf("\n");
        wait(NULL);
    } else {
        for (int i = 10; i <= 12; i++) {
            printf("[РЕБЕНОК] Счет: %d\n", i);
            sleep(1);
        }
        printf("\n");
    }

    pid = fork();
    if (pid == -1) return 1;

    if (pid > 0) {
        wait(NULL);
        exit(0);
    } else {
        exit(42);
    }
}
