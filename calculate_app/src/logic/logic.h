#ifndef LOGIC_H
#define LOGIC_H

#define is_number(x) (((x) >= '0' && (x) <= '9') || (x) == '.' || (x) == 'x')

typedef struct {
  long double expression[255];
  int len;
} locals;

typedef struct {
  int priority;
  char operat;
} operat_priority;

typedef struct {
  operat_priority expression[255];
  int len;
} in_stack;

enum {
  OK = 0,
  ERROR_BREAKET = 1,
  ERROR_SIGN = 2,
};

int validate(char *expression);
char *polish_notation(const char *expression);
long double calculation(const char *expression, long double x, int, int *error);
long double calc_logic(char *expression);

int sign(char sign);
int is_sign(char sign);
int check_mass_is_correct_br(char mass[2]);
int check_mass_is_correct(char *mass);
int sign_sequence(char *expression, int length);
int staple_sequence(char *expression, int length);
char is_operat(char operat, char op, int *i);
void get_out_stack_breakets(in_stack *stack, char *result, int *j);
void get_out_stack(in_stack *stack, char *result, int *j);
void put_in_stack(in_stack *stack, char operat, char op, int *i);
void number_in_result(char *result, const char *expression, int *j, int *i);
int is_priority(char operat);
int is_trig(char);
int validate_trigonometry(const char *expression, int length);
#endif  // LOGIC_H
