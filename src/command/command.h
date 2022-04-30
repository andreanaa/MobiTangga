#include "../ADT/map/map.h"
#include "../ADT/skill/skill.h"
#include "../ADT/stackundo/stackundo.h"
#include <stdio.h>
#include <time.h>
#include <math.h>

#ifndef COMMAND_H
#define COMMAND_H

void insertCommand(Player *P, Stackundo *historyPlayer, int giliranPlayer, Map *M, boolean *rondeSelesai, boolean *gameSelesai, int *jumlahRonde);

#endif // COMMAND_H
