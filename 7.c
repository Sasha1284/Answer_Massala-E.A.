#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    printf("Мой PID: %d\n", getpid());
    printf("Заменяю себя на ls -la...\n\n");
    execlp("ls", "ls", "-la", NULL);
    perror("exec ошибка");
    return 1;

    pid_t pid = fork();
    if (pid == -1) return 1;
    
    if (pid == 0) {
        printf("Ребенок PID: %d запустил sleep...\n", getpid());
        execlp("sleep", "sleep", "3", NULL);
        perror("exec ошибка");
        exit(1);
    } else {
        printf("Родитель PID: %d создал ребенка PID: %d\n", getpid(), pid);
        printf("Родитель ждет...\n");
        int status;
        wait(&status);
        printf("Ребенок завершился с кодом: %d\n", WEXITSTATUS(status));
    }

    pid_t pid1 = fork();
    if (pid1 == -1) { perror("fork ошибка"); exit(EXIT_FAILURE); }
    
    if (pid1 == 0) {
        printf("Дочерний PID: %d выполняет ls -l\n", getpid());
        execlp("ls", "ls", "-l", NULL);
        perror("exec ls ошибка");
        exit(EXIT_FAILURE);
    } else {
        printf("Родитель (PID=%d) ждёт завершения дочернего процесса (PID=%d)\n", getpid(), pid1);
        int status;
        waitpid(pid1, &status, 0);
        if (WIFEXITED(status)) {
            int code = WEXITSTATUS(status);
            printf("Процесс завершился %s (код = %d)\n", code == 0 ? "успешно" : "с ошибкой", code);
        } else if (WIFSIGNALED(status)) {
            printf("Процесс был убит сигналом: %d\n", WTERMSIG(status));
        }
    }

    pid_t pid2 = fork();
    if (pid2 == -1) { perror("fork ошибка"); exit(EXIT_FAILURE); }
    
    if (pid2 == 0) {
        printf("Дочерний PID: %d выполняет ps aux\n", getpid());
        execlp("ps", "ps", "aux", NULL);
        perror("exec ps ошибка");
        exit(EXIT_FAILURE);
    } else {
        printf("Родитель (PID=%d) ждёт завершения дочернего процесса (PID=%d)\n", getpid(), pid2);
        int status;
        waitpid(pid2, &status, 0);
        if (WIFEXITED(status)) {
            int code = WEXITSTATUS(status);
            printf("Процесс завершился %s (код = %d)\n", code == 0 ? "успешно" : "с ошибкой", code);
        } else if (WIFSIGNALED(status)) {
            printf("Процесс был убит сигналом: %d\n", WTERMSIG(status));
        }
    }

    return 0;
}
