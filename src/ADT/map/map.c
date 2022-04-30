#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "../mesinkata/mesinkata.c"
#include "../player/player.c"

/*#include "../array/array.c"*/
/*#include "../player/player.c"*/
/*#include "../mesinkata/mesinkata.c"*/

void MakeEmptyMap (Map *M){
/* Inisiasi map M kosong. */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    (*M).PanjangPeta = 0;
    MakeEmpty(&((*M).Peta));
    (*M).MaxRoll = 0;
    (*M).JumlahTeleporter = 0;
    MakeEmptyTeleporter(M);
}

void MakeEmptyTeleporter (Map *M){
    /*KAMUS LOKAL*/
    int i;
    /*ALGORITMA*/
    for (i=0; i<MaxPanjangPeta; i++){
        (*M).Teleporters[i].PetakAsal = 0;
        (*M).Teleporters[i].PetakTujuan = 0;
    }
}

boolean isPetakTerlarang (int NomorPetak, Map M){
    /*KAMUS LOKAL*/
    char isiPetak;
    /*ALGORITMA*/
    isiPetak = GetElmt(M.Peta, NomorPetak);
    if (isiPetak == '.') {
        return false;
    }
    else {
        return true;
    }
}

boolean PetakMemilikiTeleporter (int NomorPetak, Map M){
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return(inspectTeleporter(NomorPetak, M) != 0);
}

int inspectTeleporter (int NomorPetak, Map M){
/* I.S. Array teleporter tidak kosong, petak terdefinisi. */
/* F.S. Dicetak status keberadaan teleporter pada petak. */
    /* KAMUS LOKAL */
    int loc, i;
    boolean found;
    /* ALGORITMA */
    i = 0;
    found = false;
    while ((i<MaxPanjangPeta) && (!found)) {
        if (M.Teleporters[i].PetakAsal == NomorPetak) {
            loc = i;
            found = true;
            return(M.Teleporters[loc].PetakTujuan);
        }
        else {
            i = i + 1;
        }
    }
    if (!found) {
        return 0;
    } return 0;
}

void KataToArrayTeleporter (Kata CKata, int MaxTel, Map *M){
    char petakIn[CKata.Length], petakOut[CKata.Length];
    int inc;
    for (int i = 0; i < MaxTel; i++) {
        inc = 0;
        while (CC != BLANK && CC != ENTER) {
            petakIn[inc] = CC;
            ADV();
            inc++;
        }
        (*M).Teleporters[i].PetakAsal = atoi(petakIn);
        IgnoreBlank();
        petakIn[1] = '\0';

        inc = 0;
        while (CC != BLANK && CC != ENTER) {
            petakOut[inc] = CC;
            ADV();
            inc++;
        }
        (*M).Teleporters[i].PetakTujuan = atoi(petakOut);
        IgnoreBlank();
        petakOut[1] = '\0';
    }
}

void ReadFileKonfigurasi(Map *M){
	int PanjangPeta, MaxRoll, JumlahTeleporter;
	TabChar Peta;
	PanjangPeta = ToInt(CKata);
    ADVKATA();
	Peta = ToChar(CKata);
	ADVKATA();
	MaxRoll = ToInt(CKata);
	ADVKATA();
	JumlahTeleporter = ToInt(CKata);
	ADV();
    (*M).PanjangPeta = PanjangPeta;
    (*M).Peta = Peta;
    (*M).MaxRoll = MaxRoll;
    (*M).JumlahTeleporter = JumlahTeleporter;
    KataToArrayTeleporter(CKata, JumlahTeleporter, M);

}

void PrintPetaPlayer(Player P, int i, Map M) {
    /*KAMUS LOKAL*/
    TabChar petaPlayer;
    /*ALGORITMA*/
    petaPlayer.Neff = M.PanjangPeta;
    SetTab(M.Peta, &petaPlayer);
    SetEl(&petaPlayer, pos(P)[i], '*');
    PrintTabChar(petaPlayer);
    printf(" %d\n", pos(P)[i]);
}

int HasilRoll(Map M, Player P, int i) {
    /*KAMUS LOKAL*/
    time_t t;
    int MaxRoll, MinRoll;
    /*ALGORITMA*/
    srand(time(0));
    MinRoll = 1;
    MaxRoll = M.MaxRoll;
    if (M.MaxRoll > 0) {
        if (isSenterPembesar(P)[i]) {
            return(rand() % (MaxRoll - (int)(floor(MaxRoll/2)) + 1) + (int)(floor(MaxRoll/2)));
        }
        else if (isSenterPengecil(P)[i]) {
            return(rand() % (int)(floor(MaxRoll/2)) + 1);
        }
        else {
            return(rand() % MaxRoll + 1);
        }
    }else return 0;

}
