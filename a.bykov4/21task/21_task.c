#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int count = 0;

void sigint_handler(int sig) {
    count++;
    putchar('\a');      // Звуковой сигнал
    fflush(stdout);
}

void sigquit_handler(int sig) {
    printf("\nСигнал прозвучал %d раз(а).\n", count);
    exit(0);
}

int main() {
    signal(SIGINT, sigint_handler);
    signal(SIGQUIT, sigquit_handler);

    printf("Программа запущена. Нажмите Ctrl+C для звука, Ctrl+\\ для выхода.\n");

    while (1) {
        pause();  // Ждёт любого сигнала (эффективнее, чем sleep)
    }

    return 0;
}
