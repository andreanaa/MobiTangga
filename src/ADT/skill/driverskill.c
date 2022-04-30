#include <stdio.h>
#include <stdlib.h>
#include "skill.c"

int main (){
    SkillMu s;
    Player p;
    SkillMu copySkill;
    int random, hasilRandom;

    CreateEmptySkill(&s);
    random = randomize(4);
    hasilRandom = randomSkill(random);

    draw(&p, 1, hasilRandom);
    pintuGaks(&p, 1);
    
    printf("pemain mendapatkan skill dengan id %d\n", hasilRandom);
    return 0;
}
