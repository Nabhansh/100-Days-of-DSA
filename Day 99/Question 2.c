#include <stdlib.h>

typedef struct {
    int pos;
    double time;
} Car;

int compare(const void* a, const void* b) {
    Car* c1 = (Car*)a;
    Car* c2 = (Car*)b;
    return c2->pos - c1->pos; // descending by position
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    Car cars[positionSize];

    for (int i = 0; i < positionSize; i++) {
        cars[i].pos = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    qsort(cars, positionSize, sizeof(Car), compare);

    int fleets = 0;
    double maxTime = 0.0;

    for (int i = 0; i < positionSize; i++) {
        if (cars[i].time > maxTime) {
            fleets++;
            maxTime = cars[i].time;
        }
    }

    return fleets;
}
