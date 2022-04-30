/* File : buff.c */
/* Implementasi ADT Buff */

#include "buff.h"
#include <stdlib.h>

void activateBuffImmune(Player *P, int idx)
{
    isImmune(*P)[idx] = true;
}

void activateBuffSenterPembesar(Player *P, int idx)
{
    isSenterPembesar(*P)[idx] = true;
}

void activateBuffSenterPengecil(Player *P, int idx)
{   
    isSenterPengecil(*P)[idx] = true;
}

void activateBuffCerminPengganda(Player *P, int idx)
{   
    isCermin(*P)[idx] = true;
}

void deactivateBuffImmune(Player *P, int idx )
{
    isImmune(*P)[idx] = false;
}

void deactivateBuffSenterPembesar(Player *P, int idx)
{   
    isSenterPembesar(*P)[idx] = false;
}

void deactivateBuffSenterPengecil(Player *P, int idx)
{   
    isSenterPengecil(*P)[idx] = false;
}

void deactivateBuffCerminPengganda(Player *P, int idx)
{   
    isCermin(*P)[idx] = false;
}
