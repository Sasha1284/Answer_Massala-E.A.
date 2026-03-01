#include <stdio.h>
#include <stdlib.h>

void fill_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
}

void show_array(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

int find_smallest(int arr[], int size) {
    int smallest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < smallest) smallest = arr[i];
    }
    return smallest;
}

int find_biggest(int arr[], int size) {
    int biggest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > biggest) biggest = arr[i];
    }
    return biggest;
}

void copy_array(int original[], int copy[], int size) {
    for (int i = 0; i < size; i++) {
        copy[i] = original[i];
    }
}

int main() {
    int arr[3];
    fill_array(arr, 3);
    printf("Массив: ");
    show_array(arr, 3);
    
    printf("Самый маленький: %d\n", find_smallest(arr, 3));
    printf("Самый большой: %d\n\n", find_biggest(arr, 3));
    
    int *dyn_arr = (int*)malloc(4 * sizeof(int));
    dyn_arr[0] = 10; dyn_arr[1] = 20; dyn_arr[2] = 30; dyn_arr[3] = 40;
    printf("Массив: [10, 20, 30, 40]\n");
    free(dyn_arr);
    printf("Память освобождена\n\n");
    
    int original[] = {10, 20, 30};
    int copy[3];
    copy_array(original, copy, 3);
    copy[0] = 100;
    printf("Оригинал: [10, 20, 30]\n");
    printf("Копия: [100, 20, 30]\n\n");
    
    int menu_arr[] = {5, 2, 8, 1};
    int choice;
    do {
        printf("1. Показать массив\n");
        printf("2. Найти минимум\n");
        printf("3. Выход\n");
        printf("Выберите: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("[5, 2, 8, 1]\n");
                break;
            case 2:
                printf("Минимум: %d\n", find_smallest(menu_arr, 4));
                break;
            case 3:
                printf("Выход\n");
                break;
            default:
                printf("Неверный выбор\n");
        }
        printf("\n");
    } while (choice != 3);
    
    return 0;
}
