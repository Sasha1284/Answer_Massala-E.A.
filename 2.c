#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    double num1, num2;
    char op;
    printf("Введите первое число: ");
    scanf("%lf", &num1);
    printf("Введите операцию (+, -, *, /): ");
    scanf(" %c", &op);
    printf("Введите второе число: ");
    scanf("%lf", &num2);

    switch(op) {
        case '+': printf("Результат: %.2lf\n", num1 + num2); break;
        case '-': printf("Результат: %.2lf\n", num1 - num2); break;
        case '*': printf("Результат: %.2lf\n", num1 * num2); break;
        case '/': 
            if (num2 != 0) printf("Результат: %.2lf\n", num1 / num2);
            else printf("Ошибка: деление на ноль\n");
            break;
        default: printf("Неверная операция\n");
    }
    printf("\n");

    int sum = 0, n;
    printf("Введите число (0 для выхода): ");
    scanf("%d", &n);
    while (n != 0) {
        sum += n;
        printf("Введите число: ");
        scanf("%d", &n);
    }
    printf("Сумма: %d\n\n", sum);

    int size;
    printf("Введите размер: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    int num, is_prime = 1;
    printf("Введите число: ");
    scanf("%d", &num);
    if (num <= 1) is_prime = 0;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            is_prime = 0;
            break;
        }
    }
    printf(is_prime ? "Простое\n\n" : "Не простое\n\n");

    srand(time(NULL));
    int secret = rand() % 5 + 1;
    int guess;
    printf("Я загадал число от 1 до 5. Угадай: ");
    scanf("%d", &guess);
    if (guess == secret) printf("Угадал!\n");
    else printf("Не угадал! Это было число %d\n", secret);

    return 0;
}
