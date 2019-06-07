#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include "include/point.h"

using namespace std;

static void printResult(const bool result);

int main(void) {
  DecartPoint_t* point = inputPoint();

  printPoint(point);

  bool result = checkPoint(point);

  printResult(result);

  free(point);

  return 0;
}

static void printResult(const bool ok) {
  cout << endl;

  if (ok) {
    cout << "Point is in the area." << endl;
  }
  else {
    cout << "Point is not in the area." << endl;
  }
}
