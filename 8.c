// Задача 1
#include <stdio.h>
#include <pthread.h>

void* thread_func(void* arg) {
    printf("Я работаю в потоке!\n");
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, NULL);
    pthread_join(thread, NULL);
    printf("Поток завершился\n");
    return 0;
}
// Задача 2
#include <stdio.h>
#include <pthread.h>

void* multiply(void* arg) {
    int* num = (int*)arg;
    int result = (*num) * 2;
    pthread_exit((void*)(long)result);
}

int main() {
    pthread_t thread;
    int value = 5;
    printf("Передано в поток: %d ", value);
    pthread_create(&thread, NULL, multiply, &value);
    void* result;
    pthread_join(thread, &result);
    printf("Получено из потока: %ld\n", (long)result);
    return 0;
}
// Задача 3
#include <stdio.h>
#include <pthread.h>

void* thread1_func(void* arg) {
    printf("Первый поток\n");
    return NULL;
}

void* thread2_func(void* arg) {
    printf("Второй поток\n");
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, thread1_func, NULL);
    pthread_create(&thread2, NULL, thread2_func, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}
// Задача 4
#include <stdio.h>
#include <pthread.h>

void* print_id(void* arg) {
    pthread_t my_id = pthread_self();
    printf("ID внутри потока: %lu ", my_id);
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, print_id, NULL);
    printf("ID созданного потока: %lu ", thread);
    pthread_join(thread, NULL);
    if(pthread_equal(thread, pthread_self()))
        printf("ID совпадают\n");
    else
        printf("ID не совпадают\n");
    return 0;
}
