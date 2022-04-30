/* Deskripsi       : file stackundo.c */

#include <stdio.h>
#include "stackundo.h"
#include <stdlib.h>

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateStackundo (Stackundo *S){
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : ronde bernilai Nol */
    ronde (*S) = Nol;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStackundo (Stackundo S){
/* Mengirim true jika Stack kosong: lihat definisi di atas */
    return (ronde(S)==Nol);
}

boolean IsFullStackundo (Stackundo S){
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
    return (ronde(S)==MaxEl);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stackundo * S, Player * historyPlayer){
/* Menambahkan X sebagai elemen Stackundo S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. historyPlayer menjadi elemen teratas yang baru,ronde bertambah 1 */
    if (IsEmptyStackundo(*S)){
        ronde(*S) = 1;
    }else{
        ronde(*S)++;
    }

    InfoRonde(*S) = *historyPlayer;
    for (int x = 1; x <= (*historyPlayer).Neff; x++){
        (*S).historyPlayer[ronde(*S)].skills[x] = Nol;
        copySkill((*historyPlayer).skills[x], &(*S).historyPlayer[ronde(*S)].skills[x]);
    }
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stackundo * S, Player * historyPlayer, boolean * berhasilUndo){
/* Menghapus X dari Stackundo S. */
/* I.S. S tidak mungkin kosong */
/* F.S. historyPlayer adalah posisi pada ronde sebelumnya, ronde berkurang 1 */
    if(IsEmptyStackundo(*S)){
        printf("Undo tidak dapat dilakukan!\n");
        *berhasilUndo = false;
    }else{
        *historyPlayer = InfoRonde(*S);
        ronde(*S)--;
        *berhasilUndo = true;
    }
}
