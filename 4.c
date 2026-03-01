#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("hello.txt", "w");
    if (file == NULL) return 1;
    fprintf(file, "Привет, мир файлов!\n");
    fclose(file);
    printf("Файл hello.txt успешно создан и записан.\n");

    file = fopen("hello.txt", "r");
    if (file == NULL) return 1;
    char buffer[100];
    fgets(buffer, sizeof(buffer), file);
    fclose(file);
    printf("Содержимое файла hello.txt: %s\n", buffer);

    int fd = open("lowlevel.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) return 1;
    char *text = "Это низкоуровневая запись.\n";
    write(fd, text, strlen(text));
    close(fd);
    printf("Файл lowlevel.txt успешно создан и записан с помощью низкоуровневых функций.\n");

    file = fopen("numbers.bin", "wb");
    if (file == NULL) return 1;
    int numbers_write[3] = {10, 20, 30};
    fwrite(numbers_write, sizeof(int), 3, file);
    fclose(file);
    printf("Записаны числа: 10, 20, 30\n");

    file = fopen("numbers.bin", "rb");
    if (file == NULL) return 1;
    int numbers_read[3];
    fread(numbers_read, sizeof(int), 3, file);
    fclose(file);
    printf("Считаны числа: %d, %d, %d\n", numbers_read[0], numbers_read[1], numbers_read[2]);

    return 0;
}
