#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
    printf("No me puedes cerrar...pero mid pid es %d\n", getpid());
}

int main() {
    signal(SIGINT, handle_sigint);

    while (1) {
        printf("Holaaa...\n");
        sleep(1);
    }
    return 0;
}

