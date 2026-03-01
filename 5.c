#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
    printf("Нажмите Enter чтобы начать...\n");
    getchar();
    time_t start = time(NULL);
    printf("Нажмите Enter чтобы остановить...\n");
    getchar();
    time_t end = time(NULL);
    printf("Прошло секунд: %.f\n", difftime(end, start));
    printf("\n");

    int seconds;
    printf("Введите время для отсчета (в секундах): ");
    scanf("%d", &seconds);
    for (int i = seconds; i > 0; i--) {
        printf("%d ", i);
        fflush(stdout);
        sleep(1);
    }
    printf("Время вышло!\n\n");

    char str[] = "Hello, World!\n";
    for (int i = 0; str[i] != '\0'; i++) {
        putchar(str[i]);
        fflush(stdout);
        usleep(100000);
    }
    return 0;
}
