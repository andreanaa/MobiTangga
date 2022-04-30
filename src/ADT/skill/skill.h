#include "../boolean.h"
#include "../player/player.h"

#ifndef skill_H
#define skill_H

#define Nil NULL


boolean isSkillEmpty(SkillMu S);
/* Mengembalikan true jika S = Nil. */

int jumlahSkill(SkillMu S);
/* Mengembalikan jumlah skill yang ada pada S. */

address newSkillDong();
/* Fungsi mereturn sebuah address dari Skill (list skill dong) 
Jika fungsi gagal mengalokasi Skill maka akan mereturn Nil */

void CreateEmptySkill(SkillMu *s);
/* I.S: *s sembarang
   F.S: *s = Nil */

void insertSkill (SkillMu *S, address aS);
/* Menambahkan Skill dengan alamat aS ke SkillMu */

address Search (SkillMu *s, int skillOrder);
/* Mencari apakah ada elemen list dengan urutan = skillOrder pada s */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

int randomize(int X);
/* Generate dan balikin salah satu elemen index ke-X dari array of integer hasil randomize. */

int randomSkill(int X);
/* Mengembalikan Id skill sesuai X. */

void constructSkill(address aS, int id);
/* Mengisi atribut-atribut skill sesuai id. */

void printSkill(Player *P, int currentPlayer);
/* Menampilkan skill apa saja yang dimiliki oleh pemain. */

void draw(Player *P, int currentPlayer, int randomizer);
/* Menambahkan 1 Skill secara random ke SkillMu Player yang sedang bermain di giliran ini. */

void discard(SkillMu *s, int skillOrder);
/* Membuang Skill dengan nomor urut skillOrder dari SkillMu suatu pemain. */

void Activate(Player *P, SkillMu *S, int skillOrder, int currentPlayer);
/* Mengaktifkan efek dari Skill yang sedang dipakai. */

void printOneSkill(SkillMu *S, int skillOrder);
/* Menampilkan skill pada urutan skillOrder. */

//Skill 

void pintuGaks(Player *P, int currentPlayer);
/* Player mendapat buff imunitas dari teleporter */
/* tidak mendapat ekstra ketika diaktifkan berulang kali */

void cerminPengganda(Player *P, int currentPlayer);
/* Menjalankan prosedur draw sebanyak 2 kali dan menambahkan skill yang didapat ke pemain */

void senterPembesarHoki(Player *P, int currentPlayer);
/* Pada giliran ini, dadu akan menghasilkan angka antara floor(roll/2) dan roll. */
/* Tidak dapat digunakan berulang atau bersamaan dengan senter lain. */

void senterPengecilHoki(Player *P, int currentPlayer);
/* Pada giliran ini, dadu akan menghasilkan angka antara 1 dan floor(roll/2). */
/* Tidak dapat digunakan berulang atau bersamaan dengan senter lain. */

void mesinPenukarPosisi(Player *P, int currentPlayer);
/* Menukarkan posisi dua pemain pada map. */
/* tidak mengaktifkan teleporter. */

//External 

void copySkill(SkillMu origin, SkillMu *copy);

#endif
