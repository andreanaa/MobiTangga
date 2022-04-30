/* File : stackundo.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* Implementasi dalam bahasa C dengan alokasi statik */
/* Stack digunakan untuk menampung state game tiap ronde serta menyediakan fitur undo*/
/* ronde adalah elemen teratas */
#ifndef stackt_H
#define stackt_H

#include "../boolean.h"
#include "../player/player.h"
#include "../skill/skill.h"

#define Nol 0
#define MaxEl 1000

typedef int infotype;
typedef int alamat;   /* indeks tabel */
typedef struct {
    Player historyPlayer[MaxEl];
    alamat ronde;  /* alamat Ronde: elemen teratas */
} Stackundo;
/* Definisi stack S kosong : S.ronde = Nol */
/* Jika S adalah Stack maka akses elemen : */

/* Definisi akses dengan Selektor : Set dan Get */
#define ronde(S) (S).ronde
#define InfoRonde(S) (S).historyPlayer[(S).ronde]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateStackundo (Stackundo *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : ronde bernilai Nol */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStackundo (Stackundo S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStackundo (Stackundo S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stackundo * S, Player * historyPlayer);
/* Menambahkan X sebagai elemen Stackundo S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. historyPlayer menjadi elemen teratas yang baru,ronde bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stackundo * S, Player * historyPlayer, boolean * berhasilUndo);
/* Menghapus X dari Stackundo S. */
/* I.S. S tidak mungkin kosong */
/* F.S. historyPlayer adalah posisi pada ronde sebelumnya, ronde berkurang 1 */

#endif
