#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int count = 0;

// будет писщать при нажатии CTRL^C
void signal_SIGINT() {
    printf("\a");
    // очистка буферов
    fflush(NULL);
    count++;
}

// будет завершать работу цикла
void signal_SIGQUIT() {
    printf("\nКоличество писков: %d\n", count);
    exit(0);
}


int main() {

    signal(SIGINT,  &signal_SIGINT);
    signal(SIGQUIT, &signal_SIGQUIT);

    while(1);
}
