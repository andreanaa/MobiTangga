#include "map.c"
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int PanjangPeta, NomorPetak, hasilInspect;
    Map M;
    Player P;
    MakeEmptyMap(&M);
    printf("Masukkan panjang peta (1-100) : ");
    scanf("%d", &PanjangPeta);
    M.PanjangPeta = PanjangPeta;
    M.Peta.Neff = M.PanjangPeta;
    printf("Menginisiasi seluruh elemen efektif peta yang indeksnya kelipatan 4 dengan '#' dan sisanya '.'\n");
    for (int i=1; i<=M.PanjangPeta; i++) {
        SetEl(&(M.Peta), i, '.');
    }
    for (int i=1; i<=M.PanjangPeta; i++) {
        if ((i % 4) == 0) {
            SetEl(&(M.Peta), i, '#');
        }
    }
    int n = 1;
    for (int i=1; i<=(M.Peta.Neff-4); i++) {
        if ((i % 3) == 0) {
            M.Teleporters[n].PetakAsal = i;
            M.Teleporters[n].PetakTujuan = i+4;
            n++;
        }
    }
    printf("Setiap elemen efektif peta yang indeksnya kelipatan 3 (hingga 4 elemen sebelum elemen terakhir) diisi dengan teleporter 4 petak setelahnya.\n");
    printf("Hasil print Peta: ");
    PrintTabChar(M.Peta);
    printf("\n");
    CreatePlayer(&P);
    addPlayer(&P, 1);
    printf("INSPECT (Untuk mengetahui apakah suatu petak merupakan petak kosong, petak terlarang, atau petak yang memiliki teleporter)\n");
    printf("Masukkan petak: ");
    scanf("%d", &NomorPetak);
    while ((NomorPetak < 1) || (NomorPetak > M.PanjangPeta)) {
        printf("Input nomor petak tidak valid.\n");
        printf("Nomor petak yang valid adalah 1-%d. Silakan ulangi.\n", M.PanjangPeta);
        printf("Masukkan petak: ");
        scanf("%d", &NomorPetak);
    }
    if (isPetakTerlarang(NomorPetak, M)) {
        printf("Petak %d merupakan petak terlarang.\n", NomorPetak);
    }
    else {
        hasilInspect = inspectTeleporter(NomorPetak, M);
        if (PetakMemilikiTeleporter(NomorPetak, M)) {
            printf("Petak %d memiliki teleporter menuju %d.\n", NomorPetak, hasilInspect);
        }
        else {
            printf("Petak %d merupakan petak kosong.\n", NomorPetak);
        }
    }
    printf("ROLL (Untuk mendapatkan integer hasil roll dadu)\n");
    printf("Masukkan MaxRoll : ");
    scanf("%d", &M.MaxRoll);
    printf("Hasil roll : ");
    printf("%d\n", HasilRoll(M, P, 1));
    printf("Membaca file konfigurasi testReadConfig.txt.\n");
    STARTKATA("testReadConfig.txt");
    ReadFileKonfigurasi(&M);
    printf("Hasil print Peta: ");
    PrintTabChar(M.Peta);
    printf("\n");
    printf("INSPECT (Untuk mengetahui apakah suatu petak merupakan petak kosong, petak terlarang, atau petak yang memiliki teleporter)\n");
    printf("Masukkan petak: ");
    scanf("%d", &NomorPetak);
    while ((NomorPetak < 1) || (NomorPetak > M.PanjangPeta)) {
        printf("Input nomor petak tidak valid.\n");
        printf("Nomor petak yang valid adalah 1-%d. Silakan ulangi.\n", M.PanjangPeta);
        printf("Masukkan petak: ");
        scanf("%d", &NomorPetak);
    }
    if (isPetakTerlarang(NomorPetak, M)) {
        printf("Petak %d merupakan petak terlarang.\n", NomorPetak);
    }
    else {
        hasilInspect = inspectTeleporter(NomorPetak, M);
        if (PetakMemilikiTeleporter(NomorPetak, M)) {
            printf("Petak %d memiliki teleporter menuju %d.\n", NomorPetak, hasilInspect);
        }
        else {
            printf("Petak %d merupakan petak kosong.\n", NomorPetak);
        }
    }
}
