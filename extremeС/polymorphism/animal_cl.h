#ifndef ANIMAL_CL_H
#define ANIMAL_CL_H

struct animal_t;
struct animal_t* animal_new();
void animal_ctor(struct animal_t* animal);
void animal_get_name(struct animal_t* animal, char* buffer);
void animal_dtor(struct animal_t* animal);
void animal_sound(struct animal_t* animal);

#endif