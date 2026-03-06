#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int player_money = 1000;

void* buy_sword(void* arg) {
    for(int i = 0; i < 100; i++) {
        int cost = 10;
        if(player_money >= cost) {
            player_money = player_money - cost;
            printf("Куплен меч! Денег осталось: %d\n", player_money);
        }
        sleep(1);
    }
    return NULL;
}

void* buy_potion(void* arg) {
    for(int i = 0; i < 100; i++) {
        int cost = 5;
        if(player_money >= cost) {
            player_money = player_money - cost;
            printf("Куплено зелье! Денег осталось: %d\n", player_money);
        }
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    printf("Начало игры! Денег: %d\n", player_money);
    pthread_create(&thread1, NULL, buy_sword, NULL);
    pthread_create(&thread2, NULL, buy_potion, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Итого: %d монет\n", player_money);
    return 0;
}
