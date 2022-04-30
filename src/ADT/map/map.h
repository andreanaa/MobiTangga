#include "../boolean.h"
#include "../player/player.h"
#include "../mesinkata/mesinkata.h"
#include <math.h>
#include <time.h>

#ifndef MAP_H
#define MAP_H

/* Kamus Umum */

#define MaxPanjangPeta 100
#define IdxMin 1
#define IdxUndef -999

/* Definisi elemen dan koleksi objek */
typedef struct
{
    int PetakAsal;
    int PetakTujuan;
} Teleporter;

typedef struct
{
    int PanjangPeta;
    TabChar Peta;
    int MaxRoll;
    int JumlahTeleporter;
    Teleporter Teleporters[MaxPanjangPeta+1];
} Map;

void MakeEmptyMap (Map *M);
/* Inisiasi map M kosong. */

void MakeEmptyTeleporter (Map *M);
/* Inisiasi petak asal dan petak tujuan teleporter dengan nilai 0.*/

boolean isPetakTerlarang (int NomorPetak, Map M);
/* Mengirimkan True jika petak tersebut merupakan petak teralarang. */

boolean PetakMemilikiTeleporter (int NomorPetak, Map M);
/* Mengirimkan True jika petak tersebut memiliki teleporter. */

int inspectTeleporter (int NomorPetak, Map M);
/* I.S. Array teleporter tidak kosong, petak terdefinisi. */
/* F.S. Dicetak status keberadaan teleporter pada petak. */

void ReadFileKonfigurasi(Map *M);

void KataToArrayTeleporter (Kata CKata, int MaxTel, Map *M);

void PrintPetaPlayer(Player P, int i, Map M);
/* Mencetak peta player ke layar. */

int HasilRoll(Map M, Player P, int i);
/* Mengirimkan hasil roll dadu. */

#endif
