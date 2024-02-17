#include "gun_cl.h"
#include "bugay_cl.h"
#include "player_cl.h"

#include <stdio.h>
#include <stdlib.h>

int main(){   
    struct gun_t* gun;
    struct gun_t* gun2;
    struct gun_t* gun3;
    gun2 = gun_init();
    gun = gun_init();
    gun3 = gun_init();
    gun_ctor(gun, RIFLE, "AK");
    gun_ctor(gun2, PISTOL, "M4");
    gun_ctor(gun3, SHOTGUN, "Shotgun");
    struct player_t* player;
    player = player_init();
    player_ctor(player, "Alex");
    player_set_gun(player, gun3);
    player_shoot(player);
    free(player);

    struct bugay_t* bugay;
    bugay = bugay_init();
    bugay_ctor(bugay, "Bugay");
    bugay_change_gun(bugay, gun);
    bugay_shoot(bugay);
    bugay_change_gun(bugay, gun2);
    bugay_shoot(bugay);
    free(bugay);

    free(gun2);    
    free(gun);

    return 0;
}