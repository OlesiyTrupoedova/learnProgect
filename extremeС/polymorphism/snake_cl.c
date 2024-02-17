#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "animal_cl.h"
#include "animal_cl_p.h"

typedef struct {
  animal_t animal;
} snake_t;
// определяем новое поведение для операции sound
void __snake_sound(void* ptr) {
  animal_t* animal = (animal_t*)ptr;
  printf("%s: Hiss\n", animal->name);
}
// аллокатор памяти
snake_t* snake_new() {
  return (snake_t*)malloc(sizeof(snake_t));
}

void snake_ctor(snake_t* snake) {
    animal_ctor((struct animal_t*)snake);
    strcpy(snake->animal.name, "Snake");
    snake->animal.sound_func = __snake_sound;
}
// деструктор
void snake_dtor(snake_t* snake) {
  animal_dtor((struct animal_t*)snake);
}