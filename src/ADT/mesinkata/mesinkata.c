#include <stdio.h>
#include "stdlib.h"
#include <math.h>
#include "../mesinkar/mesinkar.c"
#include "mesinkata.h"
#include "../array/array.c"


char CC;
boolean EndKata;
Kata CKata;

void IgnoreBlank(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

   /* Kamus Lokal */

   /* Algoritma */
   while (CC == BLANK || CC == ENTER){
       ADV();
   }
}

void SalinKata(){
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

    /* Kamus Lokal */
    int i;
    /* Algoritma */
    i = 1;
    CKata.Length = 0;
    while ((CC != BLANK) && (CC != ENTER)){
        CKata.TabKata[i] = CC;
        i++;
        ADV();
    }
    CKata.Length = i-1;
}

void STARTKATA(char *filename){
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

    /* Kamus Lokal */

    /* Algoritma */
    START(filename);
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = true;
    } else {
        EndKata = false;
        SalinKata();
    }
}

void STARTCOMMAND(){
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

    /* Kamus Lokal */

    /* Algoritma */
    STARTINPUT();
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = true;
    } else {
        EndKata = false;
        SalinKata();
    }
}

void ADVKATA(){
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

    /* Kamus Lokal */

    /* Algoritma */
    IgnoreBlank();
    if (CC == EOP){
        EndKata = true;
    } else {
        SalinKata();
    }
}

boolean isKataEqual (Kata k1, Kata k2){
 /* menghasilkan true apabila k1 = k2 */
    /*KAMUS LOKAL*/
    int i;
    boolean equal;
    /*ALGORITMA*/
    i = 0;
    equal = true;
    if (k1.Length == k2.Length){
        while (i < k1.Length && equal){
            if (k1.TabKata[i] != k2.TabKata[i]){
                equal = false;
            } else {
                i++;
            }
        }
    } else {
        equal = false;
    } return equal;
}

void PrintKata (Kata k){
/* Prosedur untuk mencetak sebuah kata ke layar
    I.S. : Kata k terdefinisi dan tidak kosong
    F.S. : Kata k tercetak pada layar.*/
    /*KAMUS LOKAL*/
    int i;
    /* ALGORITMA */
    for (i = 1; i <= k.Length; i++){
        printf("%c", k.TabKata[i]);
    }
    printf("\n");
}


int ToInt(Kata CKata){
/* untuk menerjemahkan file konfigurasi yang berupa kata menjadi integer*/
    /*KAMUS LOKAL*/
    char Kata[CKata.Length];
    /*ALGORITMA*/
    for (int i = 0; i < CKata.Length; i++){
        Kata[i] = CKata.TabKata[i+1];
    } return atoi(Kata);
}

TabChar ToChar(Kata CKata){
/* untuk menerjemahkan file konfigurasi yang berupa kata menjadi integer*/
    /*KAMUS LOKAL*/
    TabChar Petak;
    /*ALGORITMA*/
    MakeEmpty(&Petak);
    for (int i = 0; i < CKata.Length; i++){
        Petak.Neff += 1;
        Petak.TI[Petak.Neff] = CKata.TabKata[i+1];
    }
    return Petak;
}


void INPUTREADER(){
/* untuk membaca input dari user*/
    /*KAMUS LOKAL*/
    int i;
    /*ALGORITMA*/
    i=1;
	printf("\x1b[1m");
	printf("\x1b[4m");
	do {
		ADVINPUT();
		CKata.TabKata[i] = CC;
		i++;
	} while((CC != ENTER) && (i <= NMax));
	CKata.Length = i-2;
	printf("\x1b[0m");


}




