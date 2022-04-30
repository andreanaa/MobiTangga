#ifndef BUFF_H
#define BUFF_H

#include "../player/player.h"

void activateBuffImmune(Player *P, int idx);
/*
Fungsi untuk mengaktifkan buff imunitas teleport
*/
void activateBuffSenterPembesar(Player *P, int idx);
/*
Fungsi untuk mengaktifkan buff senter pembesar hoki
*/
void activateBuffSenterPengecil(Player *P, int idx);
/*
Fungsi untuk mengaktifkan buff senter pengecil hoki
*/
void activateBuffCerminPengganda(Player *P, int idx);
/*
Fungsi untuk mengaktifkan buff Cermin pengganda
*/

void deactivateBuffImmune(Player *P, int idx);
/*
Fungsi untuk menonaktifkan buff imunitas teleport
*/
void deactivateBuffSenterPembesar(Player *P, int idx);
/*
Fungsi untuk menonaktifkan buff senter pembesar hoki
*/
void deactivateBuffSenterPengecil(Player *P, int idx);
/*
Fungsi untuk menonaktifkan buff senter pengecil hoki
*/
void deactivateBuffCerminPengganda(Player *P, int idx);
/*
Fungsi untuk menonaktifkan buff Cermin pengganda
*/


#endif