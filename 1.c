#include <stdio.h>
#include <math.h>

int main() {

    printf("Размеры типов данных:\n");
    printf("char: %zu байт\n", sizeof(char));
    printf("short int: %zu байт\n", sizeof(short int));
    printf("int: %zu байт\n", sizeof(int));
    printf("long int: %zu байт\n", sizeof(long int));
    printf("long long int: %zu байт\n", sizeof(long long int));
    printf("float: %zu байт\n", sizeof(float));
    printf("double: %zu байт\n", sizeof(double));
    printf("long double: %zu байт\n\n", sizeof(long double));

    int a, b;
    printf("Введите первое целое число: ");
    scanf("%d", &a);
    printf("Введите второе целое число: ");
    scanf("%d", &b);
    printf("\nРезультаты операций:\n");
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d / %d = %d (целочисленное деление)\n", a, b, a / b);
    printf("%d %% %d = %d\n\n", a, b, a % b);

    double da, db;
    printf("Введите первое число double: ");
    scanf("%lf", &da);
    printf("Введите второе число double: ");
    scanf("%lf", &db);
    printf("\nРезультаты операций с double:\n");
    printf("%.2lf + %.2lf = %.2lf\n", da, db, da + db);
    printf("%.2lf - %.2lf = %.2lf\n", da, db, da - db);
    printf("%.2lf * %.2lf = %.2lf\n", da, db, da * db);
    printf("%.2lf / %.2lf = %.2lf\n", da, db, da / db);
    printf("%.2lf в степени %.2lf = %.2lf\n\n", da, db, pow(da, db));

    double celsius;
    printf("Введите температуру в градусах Цельсия: ");
    scanf("%lf", &celsius);
    printf("%.2lf °C = %.2lf °F\n", celsius, (celsius * 9.0/5.0) + 32);
    printf("%.2lf °C = %.2lf K\n\n", celsius, celsius + 273.15);

    char ch;
    printf("Введите любой символ: ");
    scanf(" %c", &ch);
    printf("Символ: '%c'\n", ch);
    printf("Код в DEC: %d\n", ch);
    printf("Код в HEX: %X\n", ch);
    printf("Следующий символ: '%c'\n", ch + 1);
    printf("Предыдущий символ: '%c'\n\n", ch - 1);

    double n1, n2, s;
    printf("Введите начало диапазона (n1): ");
    scanf("%lf", &n1);
    printf("Введите конец диапазона (n2): ");
    scanf("%lf", &n2);
    printf("Введите шаг (s): ");
    scanf("%lf", &s);
    printf("\nТаблица значений функции y = x^2\n");
    printf("%10s %10s\n", "x", "y");
    for (double x = n1; x <= n2; x += s) {
        printf("%10.2lf %10.2lf\n", x, x * x);
    }

    return 0;
}
