#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "gun_cl.h"

typedef struct gun_t{
    int type;
    int cartridges;
    int horn;
    char name_gun[20];
}gun_t;

void __gun_reload(gun_t *gun);

void __gun_random(gun_t *gun){
    srand(time(NULL));
    gun->horn = rand() % 3 + 1;
    if(gun->type == RIFLE){
        gun->cartridges = 4;
    }
    if(gun->type == SHOTGUN){
        gun->cartridges = 8;
    }
    if(gun->type == SNIPER){
        gun->cartridges = 5;
    }
    if(gun->type == PISTOL){
        gun->cartridges = 6;
    }

}

gun_t *gun_init(int type, char *name_gun){
    gun_t *gun = malloc(sizeof(gun_t));
    gun->type = type;
    gun->cartridges = 0;
    gun->horn = 0;
    strcpy(gun->name_gun, name_gun);
    __gun_random(gun);
    return gun;
}

void __gun_shoot_sound(int type){
    if(type == 0){
        printf("Pew Pew");
    }
    if(type == 1){
        printf("Paw");
    }
    if(type == 2){
        printf("Skidish");
    }
    if(type == 3){
        printf("Pabax");
    }
}

void gun_shoot(gun_t *gun){
    while (1)
    {
        // sleep(1);
    gun->cartridges--;
    if(gun->cartridges == 0){
        gun->horn--;
        if(gun->horn != 0){
            __gun_reload(gun);
        } else if(gun->horn == 0){
            printf("\nGun %s is broken\n", gun->name_gun);
            break;
        }
    }
    __gun_shoot_sound(gun->type);
}
}

void __gun_reload(gun_t *gun){
    if(gun->type == 0){
        gun->cartridges = 6;    
    }
    if(gun->type == 1){
        gun->cartridges = 4;
    }
    if(gun->type == 2){
        gun->cartridges = 5;
    }
    if(gun->type == 3){
        gun->cartridges = 6;
    }
}

void gun_destroy(gun_t *gun){
    free(gun);
}