/* File : player.c */
/* Implementasi ADT Player */


#include "player.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* NEW PLAYER */

void CreatePlayer (Player *P)
/* I.S. P terdefinisi
   F.S. Sebuah player P terbentuk */
{
    (*P).Neff = 0;
}

void addPlayer(Player *P, int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("Masukkan Username pemain %d: ", i);
        scanf("%s", (userName(*P)[i]));
        int u = 1;
        while (u <= n)
        {
            if (strcmp(userName(*P)[i], userName(*P)[u]) == 0 && u != i)
            {
                printf("Username %s tidak tersedia!\n", userName(*P)[i]);
                printf("Masukkan Username lain untuk pemain %d: ", i);
                scanf("%s", (userName(*P)[i]));
            }
            else
            {
                u++;
            }
        }
        pos(*P)[i] = 1;
        isTeleported(*P)[i] = false;
        isImmune(*P)[i] = false;
        isSenterPembesar(*P)[i] = false;
        isSenterPengecil(*P)[i] = false;
        isCermin(*P)[i] = false;
        isSudahRoll(*P)[i] = false;
        skills(*P)[i] = Nil;
    }
    Neff(*P) = n;
}

int getPlayerIdx(Player P, char *nameSearch)
{
    int i = IdxMinPlayer;
    int idxP = IdxUndef;
    while (i <= IdxMaxPlayer)
    {
        if (strcmp(nameSearch, P.userName[i]) != 0)
        {
            i++;
        }
        else
        {
            idxP = i;
            break;
        }
    }
    return idxP;
}

boolean isPlayerTeleported(Player P, char *userName)
{
    int idx = getPlayerIdx(P, userName);
    if (idx != IdxUndef)
    {
        return (isTeleported(P)[idx]);
    } else {
        return false;
    }
}

boolean isPlayerImmune(Player P, char *userName)
{
    int idx = getPlayerIdx(P, userName);
    if (idx != IdxUndef)
    {
        return (isImmune(P)[idx]);
    } else {
        return false;
    }
}

boolean isPlayerSenterPembesar(Player P, char *userName)
{
    int idx = getPlayerIdx(P, userName);
    if (idx != IdxUndef)
    {
        return (isSenterPembesar(P)[idx]);
    } else {
        return false;
    }
}

boolean isPlayerSenterPengecil(Player P, char *userName)
{
    int idx = getPlayerIdx(P, userName);
    if (idx != IdxUndef)
    {
        return (isSenterPengecil(P)[idx]);
    } else {
        return false;
    }
}

boolean isPlayerCerminPengganda(Player P, char *userName)
{
    int idx = getPlayerIdx(P, userName);
    if (idx != IdxUndef)
    {
        return (isCermin(P)[idx]);
    } else {
        return false;
    }
}

int getPlayerPosition(Player P, char *userName)
{
    int idx = getPlayerIdx(P, userName);
    if (idx != IdxUndef)
    {
        return (pos(P)[idx]);
    } else {
        return false;
    }
}
