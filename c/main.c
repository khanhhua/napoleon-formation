#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int legion_size = 0;

int random_(int, int);

int main() {
  srand(time(NULL));

  printf("Good morning, Commander!\n");
  legion_size = random_(10, 100);

  int efforts = 0, row_count, col_count, remainder, answer = 0;

  do {
    efforts++;

    row_count = random_(1, 10);
    col_count = legion_size / row_count;
    remainder = legion_size % row_count;

    printf("Rows: %d\tRemainder: %d\nWhat is the legion size?\nAnswer: ",
           row_count, remainder);
    scanf("%d", &answer);

  } while (legion_size != answer);

  printf("Correct!");
}

int random_(int m, int n) { return (rand() % m) + (rand() % (n - m)) + m + 1; }
