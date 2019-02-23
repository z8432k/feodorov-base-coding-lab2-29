#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/point.h"

#define RADIUS 1

void printResult(const bool result);

int main(const int argc, const char** argv) {
  if (argc < 3) {
    fprintf(stderr, "Too few CLI arguments. Need two args with float numbers.\n");
    exit(1);
  }

  DecartPoint_t* point = readPoint(argv);

  printf("Point coords: (%0.2f, %0.2f)\n", point->x, point->y);

  bool result = checkPoint(point, RADIUS);

  printResult(result);

  free(point);

  return 0;
}

void printResult(const bool ok) {
  printf("\n");

  if (ok) {
    printf("Point is in the area.\n");
  }
  else {
    printf("Point is not in the area.\n");
  }
}
