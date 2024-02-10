#ifndef GUN_CL
#define GUN_CL

enum gun_type {
    PISTOL = 0,
    RIFLE = 1,
    SHOTGUN = 2,
    SNIPER = 3
};

struct gun_t;

void gun_ctor(struct gun_t*,int , char *);
void gun_shoot(struct gun_t *);
void gun_destroy(struct gun_t *);
struct gun_t *gun_init();
#endif