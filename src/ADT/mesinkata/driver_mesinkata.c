#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"

int main() {

	/* COBA BACA FILE KONFIGURASI */
	STARTKATA("coba.txt");
	int PanjangPeta, MaxRoll, JumlahTeleporter, petaki, petako;
	TabChar Peta;
	PanjangPeta = ToInt(CKata);
    ADVKATA();
	Peta = ToChar(CKata);
	ADVKATA();
	MaxRoll = ToInt(CKata);
	ADVKATA();
	JumlahTeleporter = ToInt(CKata);
	ADV();	
	printf("Panjang Map: %d\n", PanjangPeta);
	printf("Petak Peta: ");
	PrintTabChar(Peta);
    printf("Max Roll: %d\n", MaxRoll);
	printf("Banyak Teleporter: %d\n", JumlahTeleporter);
	return 0;
}

	/*COBA BACA INPUT USER*/
	/*printf("Masukkan command: ");
	INPUTREADER();
	PrintKata(CKata);
	return 0;
}*/



