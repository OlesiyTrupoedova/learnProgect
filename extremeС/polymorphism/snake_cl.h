#ifndef SNAKE_CL
#define SNAKE_CL

struct snake_t;
struct snake_t* snake_new();
void snake_ctor(struct snake_t* snake);
void snake_dtor(struct snake_t* snake);

#endif