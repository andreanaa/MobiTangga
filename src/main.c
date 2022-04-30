#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "string.h"
#include "command/command.c"
#include "ADT/player/player.h"
#include "ADT/array/array.h"
#include "ADT/stackundo/stackundo.h"
#include "interface/biargemes.c"

int main () {
    welcomeText();
    printf("\n");
    char mainCommand1[20] = "NEW-GAME";
    char mainCommand2[20] = "EXIT";
    char mainCommand[20];
    printf("\n=== MAIN MENU ===\n");
    printf("1. NEW-GAME\n");
    printf("2. EXIT\n");
    printf("Masukkan command: ");
    scanf("%s", mainCommand);
    while ((strcmp(mainCommand, mainCommand1)!=0) && (strcmp(mainCommand, mainCommand2)!=0)) {
        printf("Input command tidak valid. Silakan ulangi. (Contoh input: NEW-GAME)\n");
        printf("Masukkan command: ");
        scanf("%s", mainCommand);
    }
    if (strcmp(mainCommand, mainCommand1)==0) {
        printf("=== PILIH LEVEL ===\n");
        printf("Level yang tersedia: \n");
        printf("1. LEVEL 1\n");
        printf("2. LEVEL 2\n");
        int chosenFile;
        printf("Masukkan level (Contoh: 2) : ");
        scanf("%d", &chosenFile);
        while ((chosenFile != 1) && (chosenFile != 2)) {
            printf("Input level tidak valid. Silakan ulangi.\n");
            printf("Masukkan level: ");
            scanf("%d", &chosenFile);
        }
        printf("Masukkan jumlah pemain: ");
        int jmlhpemain, giliranPlayer;
        boolean rondeSelesai;
        scanf("%d", &jmlhpemain);
        printf("\n");

        Player P;
        CreatePlayer(&P);
        Stackundo historyPlayer;
        CreateStackundo (&historyPlayer);
        addPlayer(&P, jmlhpemain);
        printf("\n");
        Map M;
        if (chosenFile == 1) {
            STARTKATA("test1.txt");
        }
        else {
            STARTKATA("test2.txt");
        }
        MakeEmptyMap(&M);
        ReadFileKonfigurasi(&M);
        boolean gameSelesai = false ;
        rondeSelesai = false;
        int jumlahRonde = 1 ;
        Push(&historyPlayer, &P);
        puts("");
        printf("\n      Starting game in...\n\n");
        sleep(1);
        printf("              3...\n\n");
        sleep(1);
        printf("                     2...\n\n");
        sleep(1);
        printf("                             1...\n");
        sleep(1);
        puts("");
        getchar();
        start();
        printf("\n");
        while (!gameSelesai) {
            rondeSelesai = false;
            printf("\n+++ RONDE KE-%d +++\n\n", jumlahRonde) ;

            // Setiap player mendapatkan turn pada sebuah ronde
            for (int i = 1; i <= P.Neff; i++) {
                if (!rondeSelesai) {
                    printf("-- Giliran %s --\n\n", P.userName[i]);
                    giliranPlayer = i;
                    draw(&P, giliranPlayer, 0);
                    // Menuliskan Map setiap awal giliran
                    for (int i = 1; i <= P.Neff; i++) {
                        printf("%s", P.userName[i]) ;
                        printf(" : ") ;
                        for (int j = 1; j <= M.PanjangPeta; j++) {
                            if (P.pos[i] == j) {
                                printf("*") ;
                            }
                            else {
                                printf("%c", M.Peta.TI[j]) ;
                            }
                        }
                        /*PrintPetaPlayer(P, i, M);*/
                        printf(" %d\n\n", P.pos[i]);
                    }
                    insertCommand(&P,&historyPlayer, giliranPlayer, &M, &rondeSelesai, &gameSelesai, &jumlahRonde);
                }
                printf("\n") ;
            }
            for (int i = 1; i <= P.Neff; i++) {
                P.isSudahRoll[i] = false ;
            }
            jumlahRonde++ ;
            printf("\n") ;
            Push(&historyPlayer, &P);
        } return 0;
    }
    else {
        printf("EXIT YEY.\n");
        bye();
        printf("\n");
    } return 0;
}
