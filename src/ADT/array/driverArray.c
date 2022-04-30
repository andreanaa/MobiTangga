#include "array.c"
#include <stdio.h>

int main() {
    TabChar T, Tout;
    int neff, indeks;
    char el;
    MakeEmpty(&T);
    printf("Telah dibuat TabChar T kosong.\n");
    printf("Mengecek apakah TabChar T kosong:\n");
    if (IsEmpty(T)) {
        printf("Ya. TabChar T kosong.\n");
    }
    else {
        printf("TabChar T tidak kosong.\n");
    }
    printf("Jumlah elemen TabChar T kosong : %d\n", T.Neff);
    printf("Masukkan jumlah elemen efektif TabChar yang diinginkan (1-100): ");
    scanf("%d", &neff);
    SetNeff(&T, neff);
    printf("Jumlah elemen TabChar T sekarang : %d\n", NbElmt(T));
    printf("Mengecek apakah TabChar T kosong:\n");
    if (IsEmpty(T)) {
        printf("Ya. TabChar T kosong.\n");
    }
    else {
        printf("TabChar T tidak kosong.\n");
    }
    printf("Menginisiasi seluruh elemen efektif TabChar T dengan '.'\n");
    for (int i=1; i<=T.Neff; i++) {
        SetEl(&T, i, '.');
    }
    printf("Hasil print TabChar T: \n");
    PrintTabChar(T);
    printf("\n");
    printf("Jumlah maksimal elemen TabChar T adalah sebesar maksimal panjang peta, yaitu: %d\n", MaxNbEl(T));
    printf("Indeks efektif pertama TabChar T adalah : %d\n", GetFirstIdx(T));
    printf("Indeks efektif terakhir TabChar T adalah : %d\n", GetLastIdx(T));
    printf("Mengecek apakah suatu indeks valid dan efektif.\n");
    printf("Masukkan indeks yang ingin dicek: \n");
    scanf("%d", &indeks);
    if (IsIdxValid(T, indeks)) {
        if (IsIdxEff(T, indeks)) {
            printf("Indeks %d valid dan merupakan indeks efektif pada TabChar T.\n", indeks);
        }
        else {
            printf("Indeks %d valid namun bukan merupakan indeks efektif pada TabChar T.\n", indeks);
        }
    }
    else {
        printf("Indeks %d bukan merupakan indeks efektif pada TabChar T dan tidak valid.\n", indeks);
    }
    printf("Mengirimkan elemen pada indeks tertentu.\n");
    printf("Masukkan indeks elemen yang diinginkan : \n");
    scanf("%d", &indeks);
    if (IsIdxValid(T, indeks)) {
        if (IsIdxEff(T, indeks)) {
            printf("Elemen pada indeks %d adalah : %c\n", indeks, GetElmt(T, indeks));
        }
        else {
            printf("Indeks %d valid namun bukan merupakan indeks efektif pada TabChar T sehingga elemennya tidak dapat diakses.\n", indeks);
        }
    }
    else {
        printf("Indeks %d bukan merupakan indeks efektif pada TabChar T dan tidak valid sehingga elemennya tidak dapat diakses.\n", indeks);
    }
    printf("Mengecek apakah TabChar T full :\n");
    if (IsFull(T)) {
        printf("Ya. TabChar T full.\n");
    }
    else {
        printf("Tidak. TabChar T tidak full.\n");
    }
    SetNeff(&T, 100);
    printf("Menginisiasi seluruh elemen yang valid di TabChar T dengan '.'\n");
    for (int i=1; i<=T.Neff; i++) {
        SetEl(&T, i, '.');
    }
    printf("Hasil print TabChar T sekarang: \n");
    PrintTabChar(T);
    printf("\n");
    printf("Mengecek apakah TabChar T full :\n");
    if (IsFull(T)) {
        printf("Ya. TabChar T full.\n");
    }
    else {
        printf("Tidak. TabChar T tidak full.\n");
    }
    printf("Menyalin TabChar T ke TacbChar Tout.\n");
    SetTab(T, &Tout);
    printf("Hasil print TabChar Tout: \n");
    PrintTabChar(Tout);
    printf("\n");
}
