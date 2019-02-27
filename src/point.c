#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "include/point.h"


#define X_ARG_POSITION 1
#define Y_ARG_POSITION 2

#define PW(x) (powf(x, 2))

static float calcPointRadius(const DecartPoint_t *point);
static float calcMaxRadius(const DecartPoint_t *point);

DecartPoint_t *readPoint(const char **argv) {
  DecartPoint_t *point = (DecartPoint_t *) malloc(sizeof(DecartPoint_t));

  point->x = (float) atof(argv[X_ARG_POSITION]);
  point->y = (float) atof(argv[Y_ARG_POSITION]);

  return point;
}

bool checkPoint(const DecartPoint_t *point, const float radius) {
  if (point->y < 0) {
    return false;
  }
  else if (point->x < 0) {
    if ((fabsf(point->x) + point->y) <= 2) {
      return true;
    }
  }
  else if (point->x > 0) {
    float pointRadius = calcPointRadius(point);
    float maxRadius = calcMaxRadius(point);

    printf("%f - %f\n", pointRadius, maxRadius);

    if (pointRadius <= maxRadius) {
      return true;
    }
  }

  return false;
}

void printPoint(const DecartPoint_t *point) {
  printf("Point coords:\t(%0.2f, %0.2f)\n", point->x, point->y);
}

static float calcPointRadius(const DecartPoint_t *point) {
  return sqrtf(PW(point->x) + PW(point->y));
}

static float calcMaxRadius(const DecartPoint_t *point) {
  float pointAngle = atanf(point->y / point->x);

  return sinf(M_PI_4) / cosf(pointAngle - M_PI_4);
}
