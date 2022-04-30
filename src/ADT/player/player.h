/* File: player.h */
/* Definisi ADT player */

#include "../boolean.h"
#include <stdlib.h>

#ifndef PLAYER_H
#define PLAYER_H

#define Nil NULL

typedef int ElType;
#define IdxMaxPlayer 5
#define IdxMinPlayer 1
#define IdxUndef -999


typedef struct listSkillDong *address;
typedef address SkillMu;

typedef struct
{
    int Neff;
    char userName[IdxMaxPlayer - IdxMinPlayer + 1][16];
    ElType pos[IdxMaxPlayer - IdxMinPlayer + 1];

    boolean isTeleported[IdxMaxPlayer - IdxMinPlayer + 1];
    boolean isImmune[IdxMaxPlayer - IdxMinPlayer + 1];
    boolean isSenterPembesar[IdxMaxPlayer - IdxMinPlayer + 1];
    boolean isSenterPengecil[IdxMaxPlayer - IdxMinPlayer + 1];
    boolean isCermin[IdxMaxPlayer - IdxMinPlayer + 1];
    boolean isSudahRoll[IdxMaxPlayer - IdxMinPlayer + 1];

    SkillMu skills[IdxMaxPlayer - IdxMinPlayer + 1];
} Player;

typedef struct listSkillDong
{
    char Name[25];
    int Id;
    void (*effect)(Player *, int);
    address next;
} Skill;

#define Id(P) (P)->Id
#define Next(P) (P)->next
#define Effect(P) (P)->effect

#define userName(P) (P).userName
#define pos(P) (P).pos

#define isTeleported(P) (P).isTeleported
#define isImmune(P) (P).isImmune
#define isSenterPembesar(P) (P).isSenterPembesar
#define isSenterPengecil(P) (P).isSenterPengecil
#define isCermin(P) (P).isCermin
#define isSudahRoll(P) (P).isSudahRoll

#define skills(P) (P).skills
#define Neff(P) (P).Neff



/*
typedef struct {
    boolean PintuGaKemanaMana;
    boolean MesinWaktu;
    boolean BalingBalingJambu;
    boolean CerminPengganda;
    boolean SenterPembesar;
    boolean SenterPengecil;
    boolean MesinPenukarPosisi;
    boolean TeknologiGagal;
} SkillEffect;

typedef struct {
    List listSkill; //List untuk menyimpan skill yang dimiliki oleh player
    List listBuff; //List untuk menyimpan buff yang dimiliki oleh player
    SkillEffect ActiveSkill; //skill-skill pemain yang sedang aktif
    infotype PlayerLoc;
} Player;*/

/* ********* AKSES (Selektor) ********* */
// Jika P adalah player, maka akses elemen:
/*
#define Skill(P) (P).listSkill
#define Buff(P) (P).listBuff
#define AS(P) (P).ActiveSkill
#define PL(P) (P).PlayerLoc

// Jika AS adalah ActiveSkill, maka akses elemen:
#define PGKM(AS) (AS).PintuGaKemanaMana
#define BBB(AS) (AS).BalingBalingJambu
#define CP(AS) (AS).CerminPengganda
#define SPbesar(AS) (AS). SenterPembesar
#define SPkecil(AS) (AS).SenterPengecil
#define MPP(AS) (AS).MesinPenukarPosisi
#define TG(AS) (AS).TeknologiGagal
*/

/* NEW PLAYER */

void CreatePlayer(Player *P);
/* I.S. array P sembarang
   F.S. array P kosong */

/* POSISI PLAYER ADA DIMANA */
int PosisiPlayer (Player P);
/* mereturn sebuah nilai yang merepresentasikan posisi player P
 I.S. semua pemain berada pada posisi 1
 F.S. posisi akan berubah tergantung petak yang didapat oleh player */

void addPlayer(Player *P, int n);
/* Prosedur untuk membuat list player sebanyak n pemain
 I.S array Player.userName, Player.pos, Player.isTeleported,
    Player.isImmune, Player.skills kosong dan Neff berisi 0
 F.S array Player.userName, Player.pos, Player.isTeleported, Player.isImmune, Player.skills sebanyak n
    terisi inputan dan Neff menjadi n. */

int getPlayerIdx(Player P, char *name);
/* Fungsi untuk mereturn index player dalam array userName dengan userName sebagai parameter input. Apabila input tidak terdapat di list userName, maka akan mereturn IdxUndef */

boolean isPlayerTeleported(Player P, char *userName);
/* Fungsi untuk mendapatkan informasi mengenai username yang dijadikan parameter mengenai apakah player tersebut terkena portal atau tidak */

boolean isPlayerImmune(Player P, char *userName);
/* Fungsi untuk mendapatkan informasi mengenai username yang dijadikan parameter mengenai apakah player tersebut sedang imun atau tidak */

boolean isPlayerSenterPembesar(Player P, char *userName);
/* Fungsi untuk mendapatkan informasi mengenai username yang dijadikan parameter mengenai apakah player tersebut memakai senter pembesar atau tidak */

boolean isPlayerSenterPengecil(Player P, char *userName);
/* Fungsi untuk mendapatkan informasi mengenai username yang dijadikan parameter mengenai apakah player tersebut memakai senter pengecil atau tidak */

boolean isPlayerCerminPengganda(Player P, char *userName);
/* Fungsi untuk mendapatkan informasi mengenai username yang dijadikan parameter mengenai apakah player tersebut memakai cermin pengganda atau tidak */

int getPlayerPosition(Player P, char *userName);
/* Fungsi untuk mendapatkan informasi mengenai username yang dijadikan parameter mengenai posisi player */

#endif
