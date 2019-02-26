typedef struct DecartPoint
{
  float x;
  float y;
} DecartPoint_t;

DecartPoint_t *readPoint(const char **argv);
bool checkPoint(const DecartPoint_t *point, const float radius);
void printPoint(const DecartPoint_t *point);
