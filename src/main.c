#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/point.h"

#define RADIUS 1

static void printResult(const bool result);

int main(const int argc, const char** argv) {
  if (argc < 3) {
    fprintf(stderr, "Too few CLI arguments. Need two args with float numbers.\n");
    exit(1);
  }

  DecartPoint_t* point = readPoint(argv);

  printPoint(point);

  bool result = checkPoint(point, RADIUS);

  printResult(result);

  free(point);

  return 0;
}

static void printResult(const bool ok) {
  printf("\n");

  if (ok) {
    printf("Point is in the area.\n");
  }
  else {
    printf("Point is not in the area.\n");
  }
}
