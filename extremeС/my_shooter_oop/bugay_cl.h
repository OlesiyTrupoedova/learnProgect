#include "player_cl_p.h"
#include "gun_cl.h"
#include "player_cl.h"

#ifndef BUGAY_CL
#define BUGAY_CL

struct bugay_t;
struct bugay_t *bugay_init();
void bugay_shoot(struct bugay_t* );
void bugay_change_gun(struct bugay_t* , struct gun_t* gun);
void bugay_ctor(struct bugay_t* bugay, char* name);
#endif