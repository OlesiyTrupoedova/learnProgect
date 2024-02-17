#include "gun_cl.h"

#ifndef PLAYER_CL_H
#define PLAYER_CL_H

struct player_t;
struct gun_t;

struct player_t* player_init();
void player_ctor(struct player_t* player, char* name);
void player_set_gun(struct player_t* , struct gun_t* );
void player_shoot(struct player_t* );
void player_change_gun(struct player_t* , struct gun_t* );
void player_destroy(struct player_t* );

#endif