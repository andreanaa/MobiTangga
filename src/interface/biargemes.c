/* File : biargemes.c */
/* Definisi Modul print ASCII Art */
#include <stdio.h>
#include <stdlib.h>
#include "biargemes.h"


void asciiart (char *filename) {
    FILE *gemes = NULL;
    if ((gemes = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "error opening %s\n", filename);
    }
    char read_string[MAX_LEN];
    while (fgets(read_string, sizeof(read_string), gemes) != NULL)
        printf("%s", read_string);
    fclose(gemes);
}

void welcomeText(){
    asciiart("../src/interface/welcome.txt");
}

void start(){
    asciiart("../src/interface/start.txt");
}

void bye(){
    asciiart("../src/interface/close.txt");
}