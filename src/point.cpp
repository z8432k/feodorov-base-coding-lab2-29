#include <stdlib.h>
#include <iostream>
#include <limits>
#include <math.h>
#include <stdbool.h>
#include "include/point.h"

#define PW(x) (powf(x, 2))

using namespace std;

static float calcPointRadius(const DecartPoint_t *point);
static float calcMaxRadius(const DecartPoint_t *point);
static void inputValue(float *value, const char* errStr);

DecartPoint_t *inputPoint() {
  DecartPoint_t *point = (DecartPoint_t *) malloc(sizeof(DecartPoint_t));

  const char *errStr = "Bad value. Try again: ";

  cout << "Input x point coord: ";
  inputValue(&point->x, errStr);

  cout << "Input y point coord: ";
  inputValue(&point->y, errStr);

  return point;
}

bool checkPoint(const DecartPoint_t *point) {
  if (point->y == 0 && point->x == 0) {
    return true;
  }
  else if (point->y < 0) {
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

    if (pointRadius <= maxRadius) {
      return true;
    }
  }

  return false;
}

void printPoint(const DecartPoint_t *point) {
  cout << "Point coords:\t(" << point->x << ", " << point->y << ")" << endl;
}

static float calcPointRadius(const DecartPoint_t *point) {
  return sqrtf(PW(point->x) + PW(point->y));
}

static float calcMaxRadius(const DecartPoint_t *point) {
  float pointAngle = atanf(point->y / point->x);

  return sinf(M_PI_4) / cosf(pointAngle - M_PI_4);
}

static void inputValue(float *value, const char* errStr) {
  cin >> *value;

  while (!cin.good()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cerr << errStr;
    cin >> *value;
  }
}
