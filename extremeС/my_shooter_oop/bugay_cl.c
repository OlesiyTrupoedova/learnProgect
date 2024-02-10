#include "gun_cl.h"
#include "player_cl.h"
#include "player_cl_p.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct bugay_t{
    player_t player;
    int health;
}bugay_t;

void bugay_ctor(bugay_t* bugay, char* name){
    player_ctor(&bugay->player, name);
    bugay->health = 100;
}

bugay_t *bugay_init(){
    bugay_t *bugay = malloc(sizeof(bugay_t));
    return bugay;
}

void bugay_shoot(bugay_t* bugay){
    player_shoot((struct player_t*)bugay);
    printf("Health: %d\n", bugay->health);
    printf("Name: %s IM A BUGAY\n", bugay->player.name);
}

void bugay_change_gun(bugay_t* bugay, struct gun_t* gun){
    player_change_gun((struct player_t*)bugay, gun);
}