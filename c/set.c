#include "set.h"
#include <stdbool.h>
#include <stdlib.h>

Set *set_init(Set *s, int n) {
  s->item = n;

  return s;
}

void set_add(Set *set, int n) {
  if (set->item == n) {
    return;
  }

  if (set->next != NULL) {
    set_add(set->next, n);
    return;
  }

  Set *node = (Set *)calloc(1, sizeof(Set));

  set->item = n;
  set->next = node;
}

bool set_in(Set *set, int n) {
  if (set->item == n) {
    return true;
  }

  if (set->next == NULL) {
    return false;
  } else {
    return set_in(set->next, n);
  }
}
