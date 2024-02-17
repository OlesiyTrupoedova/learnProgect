#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// только публичные интерфейсы
#include "animal_cl.h"
#include "cat_cl.h"
#include "snake_cl.h"

int main(int argc, char** argv) {
  struct animal_t* animal = animal_new();
  struct cat_t* cat = cat_new();
  struct snake_t* snake = snake_new();
  animal_ctor(animal);
  cat_ctor(cat);
  snake_ctor(snake);
  animal_sound(animal);
  animal_sound((struct animal_t*)cat);
  animal_sound((struct animal_t*)snake);
  animal_dtor(animal);
  cat_dtor(cat);
  snake_dtor(snake);
  free(snake);
  free(cat);
  free(animal);
  return 0;
}