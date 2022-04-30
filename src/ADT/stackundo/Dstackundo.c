#include "stackundo.h"
#include "../player/player.h"
#include "../skill/skill.h"
#include <stdio.h>

int main() {
    Stackundo S ;
    CreateStackundo(&S) ;

    Player P1, historyPlayer;
    P1.isSudahRoll[1] = true ;
    P1.Neff = 1 ;
    P1.pos[1] = 8 ;

    printf("Apakah Stack kosong? \n");
    if(IsEmptyStackundo(S)){
        printf("yes\n");
    }else{
        printf("no\n");
    }

    printf("Apakah Stack penuh? \n");
    if(IsFullStackundo(S)){
        printf("yes\n");
    }else{
        printf("no\n");
    }

    if (IsEmptyStackundo(S) && !IsFullStackundo(S)) {
        
        Push(&S, &P1) ;
        printf("Jumlah pemain: %d\n", S.historyPlayer[ronde(S)].Neff) ;
        printf("Posisi pemain: %d\n\n", S.historyPlayer[ronde(S)].pos[1]) ;
        printf("Apakah Stack kosong? \n");
        if(IsEmptyStackundo(S)){
            printf("yes\n");
        }else{
            printf("no\n\n");
        }
        boolean berhasilUndo ;
        Player P2 ;
        Pop(&S, &P2, &berhasilUndo) ;

        printf("Jumlah pemain: %d\n", P2.Neff) ;
        printf("Posisi pemain: %d\n", P2.pos[1]) ;
    }   
}