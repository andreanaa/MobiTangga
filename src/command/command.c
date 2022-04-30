#include "command.h"
#include "../ADT/buff/buff.c"
#include "../ADT/map/map.c"
#include "../ADT/skill/skill.c"
#include "../ADT/stackundo/stackundo.c"
#include <stdio.h>
#include <time.h>
#include <math.h>

/*int main(){
    Map M;
    MakeEmptyMap(&M);
    M.PanjangPeta = 10;
    M.MaxRoll = 10;
    M.Peta.Neff = 10;
    for (int i=1; i<=M.PanjangPeta; i++) {
        SetEl(&(M.Peta), i, '.');
    }
    SetEl(&(M.Peta), 5, '#');
    PrintTabChar(M.Peta);
    printf("%c\n", M.Peta.TI[10]);
    M.Teleporters[3].PetakAsal = 3;
    M.Teleporters[3].PetakTujuan = 5;
    M.MaxRoll = 10;
    printf("%d\n", inspectTeleporter(3, M));
    printf("%d\n", isPetakTerlarang(5, M));
    printf("%d\n", isPetakTerlarang(7, M));
    Player P;
    CreatePlayer(&P);
    Stackundo historyPlayer;
    CreateStackundo (&historyPlayer);
    addPlayer(&P, 3);
    boolean rondeSelesai = false;
    boolean gameSelesai = false;
    int jumlahRonde = 2;
    insertCommand(&P,&historyPlayer, 1, &M, &rondeSelesai, &gameSelesai, &jumlahRonde);
}*/

void insertCommand(Player *P,Stackundo *historyPlayer, int giliranPlayer, Map *M, boolean *rondeSelesai, boolean *gameSelesai, int *jumlahRonde) {
    char command[20], /*command1[20], command2[20], command3[20], command4[20], command5[20], command6[20], command7[20], command8[20],*/ jawaban;
    int i, totalBuff, NomorPetak, hasilInspect, roll, maju, mundur, pilihan, NbSkill;
    boolean giliranSelesai, pindahPosisi;
    char command1[20] = "SKILL";
    char command2[20] = "MAP";
    char command3[20] = "BUFF";
    char command4[20] = "INSPECT";
    char command5[20] = "ROLL";
    char command6[20] = "SAVE";
    char command7[20] = "ENDTURN";
    char command8[20] = "UNDO";
    printf("+++++ LIST COMMAND ++++++\n");
    printf("++      1. SKILL       ++\n");
    printf("++      2. MAP         ++\n");
    printf("++      3. BUFF        ++\n");
    printf("++      4. INSPECT     ++\n");
    printf("++      5. ROLL        ++\n");
    printf("++      6. ENDTURN     ++\n");
    printf("++      7. UNDO        ++\n");
    printf("+++++++++++++++++++++++++\n");
    giliranSelesai = false;
    while (!giliranSelesai){
        printf("\nMasukkan command: ");
        scanf("%s", command);
        printf("\n");
        if (strcmp(command, command1)==0) {
            int activate = 99 ;
            while (activate != 0) {
                printf("\n") ;
                if (isSkillEmpty(skills(*P)[giliranPlayer])) {
                    printf("%s tidak memiliki skill apapun saat ini.\n", userName(*P)[giliranPlayer]);
                }
                else {
                    printSkill(P, giliranPlayer);
                }
                printf("\n") ;
                printf("Jika tidak ingin menggunakan skill masukkan 0.\n") ;
                printf("Masukan skill yang ingin dipakai: ");
                scanf("%d", &activate) ;
                printf("\n") ;
                if (activate != 0) {
                    if (activate > jumlahSkill(skills(*P)[giliranPlayer])) {
                        printf("Jumlah skillmu tidak mencukupi :(\n");
                    }
                    else if (activate>0 && activate <= jumlahSkill(skills(*P)[giliranPlayer])) {
                        if (Id(Search(&P->skills[giliranPlayer], activate)) == 2) {
                            if (P->isCermin[giliranPlayer] == false) {
                                printf("%s mengaktifkan ", userName(*P)[giliranPlayer]);
                                printOneSkill(&skills(*P)[giliranPlayer], activate);
                                Activate(P, &skills(*P)[giliranPlayer], activate, giliranPlayer);
                            }
                            else {
                                printf("Kamu sudah memakai Cermin Pengganda turn ini.\n");
                            }
                        }
                        else if (Id(Search(&P->skills[giliranPlayer], activate)) == 3 || Id(Search(&P->skills[giliranPlayer], activate)) == 4) {
                            if (P->isSenterPembesar[giliranPlayer] == false && P->isSenterPengecil[giliranPlayer] == false) {
                                printf("%s mengaktifkan ", userName(*P)[giliranPlayer]);
                                printOneSkill(&skills(*P)[giliranPlayer], activate);
                                Activate(P, &skills(*P)[giliranPlayer], activate, giliranPlayer);
                            }
                            else {
                                printf("Kamu sudah memakai Senter Pembesar atau Pengecil turn ini.\n");
                            }
                        }
                        else {
                            printf("%s mengaktifkan ", userName(*P)[giliranPlayer]);
                            printOneSkill(&skills(*P)[giliranPlayer], activate);
                            Activate(P, &skills(*P)[giliranPlayer], activate, giliranPlayer);
                        }
                    }
                    else if (activate<0 && -activate<= jumlahSkill(skills(*P)[giliranPlayer])) {
                        printf("%s membuang ", userName(*P)[giliranPlayer]);
                        printOneSkill(&skills(*P)[giliranPlayer], activate);
                        discard(&skills(*P)[giliranPlayer], -activate);
                    }
                    else {
                        printf("Input tidak valid!\n");
                    }
                }
            }
        }
        else if (strcmp(command, command2)==0) {
            for (i=1; i<=(*P).Neff; i++) {
                printf("%s", (*P).userName[i]);
                printf(" : ");
                PrintPetaPlayer((*P), i, (*M));
            }
        }
        else if (strcmp(command, command3)==0) {
            printf("Buff yang %s miliki:\n", (*P).userName[giliranPlayer]);
            i = 1;
            totalBuff = 4;
            if ((*P).isImmune[giliranPlayer]) {
                printf("%d. Imunitas Teleport\n", i);
                i = i + 1;
            } else { totalBuff = totalBuff - 1;}
            if ((*P).isCermin[giliranPlayer]) {
                printf("%d. Cermin Pengganda\n", i);
                i = i + 1;
            } else { totalBuff = totalBuff - 1;}
            if ((*P).isSenterPembesar[giliranPlayer]) {
                printf("%d. Senter Pembesar Hoki\n", i);
                i = i + 1;
            } else { totalBuff = totalBuff - 1;}
            if ((*P).isSenterPengecil[giliranPlayer]) {
                printf("%d. Senter Pengecil Hoki\n", i);
            } else { totalBuff = totalBuff - 1;}
            if (totalBuff == 0) {
                printf("Tidak ada. %s tidak memiliki buff apapun.\n", (*P).userName[giliranPlayer]);
            }
        }
        else if (strcmp(command, command4)==0) {
            printf("Masukkan petak: ");
            scanf("%d", &NomorPetak);
            while ((NomorPetak < 1) || (NomorPetak > (*M).PanjangPeta)) {
                printf("Input nomor petak tidak valid.\n");
                printf("Nomor petak yang valid adalah 1-%d. Silakan ulangi.\n", (*M).PanjangPeta);
                printf("Masukkan petak: ");
                scanf("%d", &NomorPetak);
            }
            if (isPetakTerlarang(NomorPetak, (*M))) {
                printf("Petak %d merupakan petak terlarang.\n", NomorPetak);
            }
            else {
                hasilInspect = inspectTeleporter(NomorPetak, (*M));
                if (PetakMemilikiTeleporter(NomorPetak, (*M))) {
                    printf("Petak %d memiliki teleporter menuju %d.\n", NomorPetak, hasilInspect);
                }
                else {
                    printf("Petak %d merupakan petak kosong.\n", NomorPetak);
                }
            }
        }
        else if (strcmp(command, command5)==0) {
            if (!(*P).isSudahRoll[giliranPlayer]) {
                pindahPosisi = false;
                roll = HasilRoll(*M, *P, giliranPlayer);
                printf("%s mendapatkan angka %d.\n", (*P).userName[giliranPlayer], roll);
                maju = (*P).pos[giliranPlayer] + roll;
                mundur = (*P).pos[giliranPlayer] - roll;
                if ((maju <= (*M).PanjangPeta) && (mundur >= 1)) {
                    if ((!isPetakTerlarang(maju, *M)) && (!isPetakTerlarang(mundur, *M))) {
                        printf("%s dapat maju dan mundur.\n", (*P).userName[giliranPlayer]);
                        printf("Ke mana %s mau bergerak:\n", (*P).userName[giliranPlayer]);
                        printf("1. %d\n", maju);
                        printf("2. %d\n", mundur);
                        printf("Masukkan pilihan (1 atau 2): ");
                        scanf("%d", &pilihan);
                        printf("\n");
                        while ((pilihan != 1) && (pilihan != 2)) {
                            printf("Input pilihan tidak valid. Silakan ulangi. (Contoh input: 2)\n");
                            printf("Masukkan pilihan (1 atau 2): ");
                            scanf("%d", &pilihan);
                        }
                        if (pilihan == 1) {
                            printf("%s maju %d langkah.\n", (*P).userName[giliranPlayer], roll);
                            pos(*P)[giliranPlayer] = maju;
                            pindahPosisi = true;
                        }
                        else {
                            printf("%s mundur %d langkah.\n", (*P).userName[giliranPlayer], roll);
                            pos(*P)[giliranPlayer] = mundur;
                            pindahPosisi = true;
                        }
                    }
                    else if ((!isPetakTerlarang(maju, *M)) && (isPetakTerlarang(mundur, *M))) {
                        printf("%s dapat maju.\n", (*P).userName[giliranPlayer]);
                        printf("%s maju %d langkah.\n", (*P).userName[giliranPlayer], roll);
                        pos(*P)[giliranPlayer] = maju;
                        pindahPosisi = true;
                    }
                    else if ((isPetakTerlarang(maju, *M)) && (!isPetakTerlarang(mundur, *M))) {
                        printf("%s dapat mundur.\n", (*P).userName[giliranPlayer]);
                        printf("%s mundur %d langkah.\n", (*P).userName[giliranPlayer], roll);
                        pos(*P)[giliranPlayer] = mundur;
                        pindahPosisi = true;
                    }
                    else {
                        pindahPosisi = false;
                    }
                }
                else if ((maju <= (*M).PanjangPeta) && (mundur < 1)) {
                    if (!isPetakTerlarang(maju, *M)) {
                        printf("%s dapat maju.\n", (*P).userName[giliranPlayer]);
                        printf("%s maju %d langkah.\n", (*P).userName[giliranPlayer], roll);
                        pos(*P)[giliranPlayer] = maju;
                        pindahPosisi = true;
                    }
                    else {
                        pindahPosisi = false;
                    }
                }
                else if ((maju > (*M).PanjangPeta) && (mundur >= 1)) {
                    if (!isPetakTerlarang(mundur, *M)) {
                        printf("%s dapat mundur.\n", (*P).userName[giliranPlayer]);
                        printf("%s mundur %d langkah.\n", (*P).userName[giliranPlayer], roll);
                        pos(*P)[giliranPlayer] = mundur;
                        pindahPosisi = true;
                    }
                    else {
                        pindahPosisi = false;
                    }
                } else {
                    pindahPosisi = false;
                }
                if (!pindahPosisi) {
                    printf("%s tidak dapat bergerak.\n", (*P).userName[giliranPlayer]);
                } else {
                    printf("%s berada di petak %d.\n", (*P).userName[giliranPlayer], pos(*P)[giliranPlayer]);
                    hasilInspect = inspectTeleporter(pos(*P)[giliranPlayer], (*M));
                    if (!PetakMemilikiTeleporter(pos(*P)[giliranPlayer], (*M))) {
                        printf("%s tidak menemukan teleporter.\n", (*P).userName[giliranPlayer]);
                    }
                    else {
                        printf("%s menemukan teleporter.\n", (*P).userName[giliranPlayer]);
                        if (!isImmune(*P)[giliranPlayer]) {
                            printf("%s tidak memiliki imunitas teleport.\n", (*P).userName[giliranPlayer]);
                            printf("%s teleport ke petak %d.\n", (*P).userName[giliranPlayer], hasilInspect);
                            pos(*P)[giliranPlayer] = hasilInspect;
                        }
                        else {
                            printf("%s memiliki imunitas teleport.\n", (*P).userName[giliranPlayer]);
                            printf("Apakah %s ingin teleport (Y/N)? ", (*P).userName[giliranPlayer]);
                            scanf("%c", &jawaban);
                            printf("\n");
                            while ((jawaban != 'Y') && (jawaban != 'N')) {
                                printf("Jawaban yang Anda masukkan tidak valid. Silakan ulangi.\n");
                                printf("Apakah %s ingin teleport (Y/N)? ", (*P).userName[giliranPlayer]);
                                scanf("%c", &jawaban);
                                printf("\n");
                            }
                            if (jawaban == 'N') {
                                printf("%s tidak teleport.\n", (*P).userName[giliranPlayer]);
                                isImmune(*P)[giliranPlayer] = false;
                                printf("Buff imunitas teleport hilang.\n");
                            }
                            else {
                                printf("%s teleport ke petak %d.\n", (*P).userName[giliranPlayer], hasilInspect);
                                pos(*P)[giliranPlayer] = hasilInspect;
                            }
                        }
                    }
                    if (pos(*P)[giliranPlayer] == (*M).PanjangPeta) {
                        printf("%s telah mencapai ujung.\n", (*P).userName[giliranPlayer]);
                        printf("Pemenang game ini adalah %s.\n", (*P).userName[giliranPlayer]);
                        giliranSelesai = true;
                        (*rondeSelesai) = true;
                        (*gameSelesai) = true;
                    }
                }
                isSudahRoll(*P)[giliranPlayer] = true;
                printf("\n");
            } else {
                printf("Player hanya dapat melakukan satu kali roll tiap giliran.\n");
            }
            if ((*P).pos[giliranPlayer] == (*M).PanjangPeta) {
                giliranSelesai = true ;
                printf("%s telah mencapai ujung.\n", (*P).userName[giliranPlayer]) ;
                printf("Pemenang game ini adalah %s.\n", (*P).userName[giliranPlayer]) ;
                *gameSelesai = true ;
                *rondeSelesai = true ;
            }
        }
        else if (strcmp(command, command7)==0) {
            if (isSudahRoll(*P)[giliranPlayer]) {
                isSenterPembesar(*P)[giliranPlayer] = false;
                isSenterPengecil(*P)[giliranPlayer] = false;
                isCermin(*P)[giliranPlayer] = false;
                giliranSelesai = true;
                printf("\n");
            }
            else {
                printf("ENDTURN hanya dapat dilakukan setelah pemain bergerak (roll).\n");
                printf("%s belum melakukan roll.\n", (*P).userName[giliranPlayer]);
            }
        }
        else if (strcmp(command, command8)==0) {
            giliranSelesai = true;
            *rondeSelesai = true;
            boolean berhasilUndo;
            boolean undoBenar = false;
            char undo;
            (*jumlahRonde)--;
            Pop(historyPlayer, P, &berhasilUndo);
            if (berhasilUndo){
                printf("Undo berhasil.\n");
                if (*jumlahRonde == 0){
                    printf("State permainan akan berubah kembali ke awal permainan.\n\n");
                    berhasilUndo = false;
                }else{
                    printf("State permainan akan berubah kembali ke akhir ronde %d.\n\n", *jumlahRonde);
                }
            }else{
                printf("Undo gagal.\n\n");
            }
            while (!undoBenar && berhasilUndo){
                printf("Apakah ingin melakukan undo lagi? (Y/N): ");
                getchar();
                scanf("%c", &undo);
                if (undo == 'Y'){
                    Pop(historyPlayer, P, &berhasilUndo);
                    if (berhasilUndo){
                        (*jumlahRonde)--;
                        printf("Undo berhasil.\n");
                        if (*jumlahRonde == 0){
                            printf("State permainan akan berubah kembali ke awal permainan.\n\n");
                            berhasilUndo = false;
                        }else{
                            printf("State permainan akan berubah kembali ke akhir ronde %d.\n\n", *jumlahRonde);
                        }
                    }else{
                        printf("Undo gagal.\n\n");
                    }
                }else if (undo == 'N'){
                    undoBenar = true;
                    printf("\n");
                }else{
                    printf("Hanya terdapat input Y dan N.\n\n");
                }
            }
        }
        else {
            printf("Command yang %s masukkan tidak valid. Silakan ulangi.\n", (*P).userName[giliranPlayer]);
            insertCommand(P, historyPlayer, giliranPlayer, M, rondeSelesai, gameSelesai, jumlahRonde);
        }
    }
}
