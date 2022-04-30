#include "skill.h"
#include <stdio.h>
#include <time.h>

/*
Skill
0 = Tidak ada
1 = Pintu Ga Ke Mana Mana
2 = Cermin Pengganda
3 = Senter Pembesar Hoki
4 = Senter Pengecil Hoki
5 = Mesin Penukar Posisi
6 = Teknologi Gagal
 */

/* PROGRAM */

//  Biasanya  //

boolean isSkillEmpty(SkillMu S){
    return (S == Nil);
}

address newSkillDong(){
    address aS = (address)malloc(sizeof(Skill));
    if (aS != Nil)
    {
        Id(aS) = 0;
        Next(aS) = Nil;

        return aS;
    }
    else {
        return Nil;
    }
}

void CreateEmptySkill(SkillMu *S) {
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */
    *S = Nil;
}

int jumlahSkill(SkillMu S){
    if (isSkillEmpty(S))
    {
        return 0;
    } else
    {
        int count = 0;
        address P = S;
        while (P != Nil)
        {
            count += 1;
            P = Next(P);
        }
        return count;
    }

}

void insertSkill (SkillMu *S, address aS){
    address last;

    if (*S == Nil)
    {
        *S = aS;
    } else
    {
        last = *S;
        while (Next(last) != Nil)
        {
            last = Next(last);
        }
        Next(last) = aS;
    }

}

address Search (SkillMu *s, int skillOrder) {
    boolean found;
    found = false;
    address p = *s;
    int order = 1;
    while ((!found) && (p != Nil))
    {
        if (order == skillOrder)
        {
            found = true;
        } else
        {
            p = Next(p);
            order += 1;
        }
    }

    return p;

}

int randomize(int X)
{
    /* seed untuk randomizer */
    srand ( time(NULL) );
    int arr[2];

    arr[0] = rand() % 80;
    arr[1] = rand() % 80;

    return arr[X];
}

int randomSkill(int X){
    if (X>=1 && X<=10)
    {
        return 1;
    }
    else if (X>10 && X<=16)
    {
        return 2;
    }
    else if (X>16 && X<=31)
    {
        return 3;
    }
    else if (X>31 && X<=46)
    {
        return 4;
    }
    else if (X>46 && X<=50)
    {
        return 5;
    }
    else
    {
        return 6;
    }

}

void draw(Player *P, int currentPlayer, int randomizer){
    address aS;
    aS = newSkillDong();
    int identifier = randomSkill(randomize(randomizer));
    Id(aS) = identifier;
    constructSkill(aS, Id(aS));
    if (jumlahSkill(skills(*P)[currentPlayer]) < 10) {
        insertSkill(&skills(*P)[currentPlayer], aS);
    }
}

void discard(SkillMu *S, int skillOrder){
    int order = 1;
    address P = *S;
    if (skillOrder == 1)
    {
        if (Next(P) == Nil)
        {
            *S = Nil;
        } else
        {
            *S = Next(P);
        }
    } else
    {
        address Prec = *S;
        P = Search(S, skillOrder);
        while (Next(Prec) != P)
        {
            Prec = Next(Prec);
        }
        Next(Prec) = Next(P);

    }
}

void Activate(Player *P, SkillMu *S, int skillOrder, int currentPlayer){
    int order = 1;
    address aS = *S;
    while (order < skillOrder)
    {
        aS = Next(aS);
        order += 1;
    }
    if (Effect(aS) != Nil)
    {
        Effect(aS)(P, currentPlayer);
    }
    discard(S, skillOrder);
}

void printOneSkill(SkillMu *S, int skillOrder){
    address aS = *S;
    int count = 1;
    while (count<skillOrder)
    {
        aS = Next(aS);
        count += 1;
    }

    if (Id(aS) == 1)
    {
        printf("Pintu ga Kemana-mana\n");
    }
    else if (Id(aS) == 2)
    {
        printf("Cermin Pengganda\n");
    }
    else if (Id(aS) == 3)
    {
        printf("Senter Pembesar Hoki\n");
    }
    else if (Id(aS) == 4)
    {
        printf("Senter Pengecil Hoki\n");
    }
    else if (Id(aS) == 5)
    {
        printf("Mesin Penukar Posisi\n");
    }
    else if (Id(aS) == 6)
    {
        printf("Teknologi Gagal\n");
    }
}

void printSkill(Player *P, int currentPlayer){
    address aS = P->skills[currentPlayer];
    int count = 1;
    while (aS != Nil)
    {
        if (Id(aS) == 1)
        {
            printf("%d. Pintu ga Kemana-mana\n", count);
        }
        else if (Id(aS) == 2)
        {
            printf("%d. Cermin Pengganda\n", count);
        }
        else if (Id(aS) == 3)
        {
            printf("%d. Senter Pembesar Hoki\n", count);
        }
        else if (Id(aS) == 4)
        {
            printf("%d. Senter Pengecil Hoki\n", count);
        }
        else if (Id(aS) == 5)
        {
            printf("%d. Mesin Penukar Posisi\n", count);
        }
        else if (Id(aS) == 6)
        {
            printf("%d. Teknologi Gagal\n", count);
        }

        count += 1;
        aS = Next(aS);
    }
}

//  Skill  //
void pintuGaks(Player *P, int currentPlayer){
    if (isImmune(*P)[currentPlayer] == false)
    {
        isImmune(*P)[currentPlayer] = true;
    }
}

void cerminPengganda(Player *P, int currentPlayer){
    if (!isCermin(*P)[currentPlayer])
    {
        draw(P, currentPlayer, 0);
        draw(P, currentPlayer, 1);

        P->isCermin[currentPlayer] = true;
    }
}

void senterPembesarHoki(Player *P, int currentPlayer){
    P->isSenterPembesar[currentPlayer] = true;
}

void senterPengecilHoki(Player *P, int currentPlayer){
    P->isSenterPengecil[currentPlayer] = true;
}

void mesinPenukarPosisi(Player *P, int currentPlayer){
    ElType temp;
    int targetedPlayer;
    printf("Masukkan nomor dari player yang ingin ditukar: ");
    scanf("%d", &targetedPlayer);
    temp = pos(*P)[targetedPlayer];
    pos(*P)[targetedPlayer] = pos(*P)[currentPlayer];
    pos(*P)[currentPlayer] = temp;

}

void constructSkill(address aS, int id){
    switch (id)
    {
    case 1:
        Id(aS) = 1;
        Effect(aS) = pintuGaks;
        break;
    case 2:
        Id(aS) = 2;
        Effect(aS) = cerminPengganda;
        break;
    case 3:
        Id(aS) = 3;
        Effect(aS) = senterPembesarHoki;
        break;
    case 4:
        Id(aS) = 4;
        Effect(aS) = senterPengecilHoki;
        break;
    case 5:
        Id(aS) = 5;
        Effect(aS) = mesinPenukarPosisi;
        break;
    case 6:
        Id(aS) = 6;
        Effect(aS) = Nil;
        break;
    default:
        break;
    }
}

//  External  //
void copySkill(SkillMu origin, SkillMu *copy){
    SkillMu O = origin;
    while (O != Nil)
    {
        address aS;
        aS = newSkillDong();
        constructSkill(aS, Id(O));
        insertSkill(copy, aS);
        O = Next(O);
    }

}
