#include <stdio.h>
#include <stdlib.h>
#include "player.c"

int main () {
    printf("Masukkan jumlah pemain: ");
    int jmlhpemain, i;
    scanf("%d", &jmlhpemain);

    Player P;
    CreatePlayer(&P);

    addPlayer(&P, jmlhpemain);
    printf("Jumlah pemain saat ini: %d\n", jmlhpemain);

    for (i=1;i<=jmlhpemain;i++){
        printf("%s\n", userName(P)[i]);
    }
    return 0;
}
