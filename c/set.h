#pragma onnce

#include <stdbool.h>

typedef struct Set {
  int item;
  struct Set *next;
} Set;

Set *set_init(Set *, int);
void set_add(Set *, int);
bool set_in(Set *, int);
