#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define X_ARG_POSITION 1
#define Y_ARG_POSITION 2

#define RADIUS 1

#define PW(x) powf(x, 2)

typedef struct DecartPoint {
  float x;
  float y;
} DecartPoint_t;

DecartPoint_t* readPoint(const char** argv);
float calcRadius(const DecartPoint_t *);
bool checkPoint(const DecartPoint_t *);
void printResult(const bool result);

DecartPoint_t* readPoint(const char** argv) {
  DecartPoint_t* point = (DecartPoint_t*) malloc(sizeof(DecartPoint_t));

  point->x = (float) atof(argv[X_ARG_POSITION]);
  point->y = (float) atof(argv[Y_ARG_POSITION]);

  return point;
}

int main(const int argc, const char** argv) {
  if (argc < 3) {
    fprintf(stderr, "Too few CLI arguments. Need two args with float numbers.\n");
    exit(1);
  }

  DecartPoint_t* point = readPoint(argv);

  printf("Point coords: (%0.2g, %0.2g)\n", point->x, point->y);

  bool result = checkPoint(point);

  printResult(result);

  free(point);

  return 0;
}

bool checkPoint(const DecartPoint_t* point) {
  if (point->x > 0 && point->y > 0 && (point->x + point->y) <= 2) {
    return true;
  }
  else if (point->x < 0 && point->y < 0) {
    float point_radius = calcRadius(point);

    if (point_radius <= RADIUS) {
      return true;
    }

    return false;
  }
  else {
    return false;
  }
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

float calcRadius(const DecartPoint_t* point) {
  return sqrtf(PW(point->x) + PW(point->y));
}
