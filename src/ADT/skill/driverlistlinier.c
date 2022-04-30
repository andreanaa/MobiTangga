#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

int main() {
    List L;
    CreateEmpty(&L);
    if (IsEmpty(L)) {
        printf("Listnya kosongggg !!!\n");
    }
    // address p = 
    InsVFirst(&L,7);
    InsVLast(&L,9);
    InsertFirst(&L, Alokasi(6));
    InsertLast(&L, Alokasi(10));

    address p = First(L);

    p = p -> next;

    InsertAfter(&L, Alokasi(8), p);
    printf("Hasil: \n\ ");
    PrintInfo(L); printf("\n");

    DelP(&L, 10);
    DelFirst(&L, &p);
    printf("Hasil delete awal:\n ", p -> info);
    DelLast(&L, &p);
    printf("Hasil delete akhir:\n", p -> info);

    address prec = First(L);
    DelAfter(&L, &p, prec);
    printf("Hasil delete setelah elemen pertama :\n", p -> info);

    printf("Jumlah list:\n", NbElmtList(L));
    for (int i=0;i<10;i++){
        InsVFirst(&L, i);
    }
}