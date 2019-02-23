#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "include/point.h"

#define X_ARG_POSITION 1
#define Y_ARG_POSITION 2

#define PW(x) powf(x, 2)

static float calcRadius(const DecartPoint_t *point);

DecartPoint_t *readPoint(const char **argv) {
  DecartPoint_t *point = (DecartPoint_t *) malloc(sizeof(DecartPoint_t));

  point->x = (float) atof(argv[X_ARG_POSITION]);
  point->y = (float) atof(argv[Y_ARG_POSITION]);

  return point;
}

bool checkPoint(const DecartPoint_t *point, const float radius) {
  if (point->x > 0 && point->y > 0 && (point->x + point->y) <= 2) {
    return true;
  }
  else if (point->x < 0 && point->y < 0) {
    float point_radius = calcRadius(point);

    if (point_radius <= radius) {
      return true;
    }

    return false;
  }
  else {
    return false;
  }
}

static float calcRadius(const DecartPoint_t *point) {
  return sqrtf(PW(point->x) + PW(point->y));
}
