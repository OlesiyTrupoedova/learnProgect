#ifndef CAT_CL_H
#define CAT_CL_H
// предварительное объявление
struct cat_t;
// аллокатор памяти
struct cat_t* cat_new();
// конструктор
void cat_ctor(struct cat_t*);
// деструктор
void cat_dtor(struct cat_t*);
// все поведенческие функции наследуются от класса Animal
#endif
