#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "set.h"

int legion_size = 0;
Set *uniq_given = NULL;

int random_(int, int);
int uniq_random(int, int);

int main() {
  srand(time(NULL));

  printf("Good morning, Commander!\n");
  legion_size = random_(10, 100);

  int efforts = 0, row_count, col_count, remainder, answer = 0;

  do {
    efforts++;

    row_count = uniq_random(1, 10);
    col_count = legion_size / row_count;
    remainder = legion_size % row_count;

    printf("Rows: %d\tRemainder: %d\nWhat is the legion size?\nAnswer: ",
           row_count, remainder);
    scanf("%d", &answer);

  } while (legion_size != answer);

  printf("Correct after %d trials!\n", efforts);
}

int random_(int m, int n) { return (rand() % m) + (rand() % (n - m)) + m + 1; }

int uniq_random(int m, int n) {
  int r;

  if (uniq_given == NULL) {
    r = random_(m, n);

    uniq_given = set_init((Set *)calloc(1, sizeof(Set)), r);

    return r;
  }

  do {
    r = random_(m, n);
  } while (set_in(uniq_given, r));

  set_add(uniq_given, r);

  return r;
}
