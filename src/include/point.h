typedef struct {
  float x;
  float y;
} DecartPoint_t;

DecartPoint_t *inputPoint();
bool checkPoint(const DecartPoint_t *point);
void printPoint(const DecartPoint_t *point);
