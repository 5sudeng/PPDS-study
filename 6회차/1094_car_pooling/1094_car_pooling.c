#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int location;  // 타거나 내리는 위치
    int passengers;  // 인원수 (양수: 탑승, 음수: 하차)
} Trip;

int compare(const void* a, const void* b) {
    Trip* tripA = (Trip*)a;
    Trip* tripB = (Trip*)b;
    return tripA->location - tripB->location;
}

bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity) {
    int totalTrips = 2 * tripsSize;  // 출발/도착 모두 포함
    Trip* onoff = (Trip*)malloc(totalTrips * sizeof(Trip));

    // 배열로 우선순위 큐 구현 (출발과 도착을 따로 저장)
    for (int i = 0; i < tripsSize; i++) {
        onoff[2 * i].location = trips[i][1];  // 출발 지점
        onoff[2 * i].passengers = trips[i][0];  // 인원수 (탑승)

        onoff[2 * i + 1].location = trips[i][2];  // 도착 지점
        onoff[2 * i + 1].passengers = -trips[i][0];  // 인원수 (하차)
    }

    // 정렬 (오름차순 정렬)
    qsort(onoff, totalTrips, sizeof(Trip), compare);

    // 용량 검사
    int passengers = 0;
    for (int i = 0; i < totalTrips; i++) {
        passengers += onoff[i].passengers;
        if (passengers > capacity) {
            free(onoff);
            return false; 
        }
    }

    free(onoff);
    return true; 
}