#include "array.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (TabChar *T) {
    /* I.S. sembarang */
    /* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
    /* Kamus Lokal*/
    /* Algoritma */
    (*T).Neff = 0;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabChar T) {
    /* Mengirimkan banyaknya elemen efektif tabel */
    /* Mengirimkan nol jika tabel kosong */
    /* Kamus Lokal*/
    /* Algoritma */
    return (T.Neff);
}

/* *** Daya tampung container *** */
int MaxNbEl (TabChar T) {
    /* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    /* Kamus Lokal */
    /* Algoritma */
    return (IdxMax-IdxMin+1);
}

/* *** Selektor INDEKS *** */
IdxTabChar GetFirstIdx (TabChar T) {
    /* Prekondisi : Tabel T tidak kosong */
    /* Mengirimkan indeks elemen pertama */
    /* Kamus Lokal */
    /* Algoritma */
    return (IdxMin);
}


IdxTabChar GetLastIdx (TabChar T) {
    /* Prekondisi : Tabel T tidak kosong */
    /* Mengirimkan indeks elemen terakhir */
    /* Kamus Lokal */
    /* Algoritma */
    return (IdxMin + NbElmt(T) - 1);
}


/* *** Menghasilkan sebuah elemen *** */
ElTabChar GetElmt (TabChar T, IdxTabChar i) {
    /* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
    /* Mengirimkan elemen tabel yang ke-i */
    /* Kamus Lokal */
    /* Algoritma */
    return (T.TI[IdxMin + i - 1]);
}


/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabChar Tin, TabChar *Tout) {
    /* I.S. Tin terdefinisi, sembarang */
    /* F.S. Tout berisi salinan Tin */
    /* Assignment THsl -> Tin */
    /* Kamus Lokal */
    int i;
    /* Algoritma */
    i = IdxMin;
    (*Tout).Neff = Tin.Neff;
    while (i < (IdxMax+1)) {
        (*Tout).TI[i] = Tin.TI[i];
        i  = i + 1;
    }
}


void SetEl (TabChar *T, IdxTabChar i, ElTabChar v) {
    /* I.S. T terdefinisi, sembarang */
    /* F.S. Elemen T yang ke-i bernilai v */
    /* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
    /* Kamus Lokal */
    /* Algoritma */
    (*T).TI[IdxMin + i - 1] = v;
}


void SetNeff (TabChar *T, IdxTabChar N) {
    /* I.S. T terdefinisi, sembarang */
    /* F.S. Nilai indeks efektif T bernilai N */
    /* Mengeset nilai indeks elemen efektif sehingga bernilai N */
    /* Kamus Lokal */
    /* Algoritma */
    (*T).Neff = N;
}


/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabChar T, IdxTabChar i) {
    /* Prekondisi : i sembarang */
    /* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
    /* yaitu antara indeks yang terdefinisi utk container*/
    /* Kamus Lokal */
    /* Algoritma */
    return ((i >= 1) && (i <= 100));
}

boolean IsIdxEff (TabChar T, IdxTabChar i) {
    /* Prekondisi : i sembarang*/
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
    /* yaitu antara FirstIdx(T)..LastIdx(T) */
    /* Kamus Lokal */
    /* Algoritma */
    return ((i >= 1) && (i <= T.Neff));
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabChar T) {
    /* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
    /* Kamus Lokal */
    /* Algoritma */
    return (T.Neff == 0);
}

/* *** Test tabel penuh *** */
boolean IsFull (TabChar T) {
    /* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    /* Kamus Lokal */
    /* Algoritma */
    return (T.Neff == (IdxMax - IdxMin + 1));
}

void PrintTabChar (TabChar T) {
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    if (T.Neff != 0) {
        for(i = 1; i <= T.Neff; i++){
        printf("%c", T.TI[i]);
        }
    }
}
