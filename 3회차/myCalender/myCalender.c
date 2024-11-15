#include <stdio.h>
#include <stdbool.h>

#define MAX_EVENTS 1000

typedef struct {
    int start;
    int end;
} Event;

typedef struct {
    Event calendar[MAX_EVENTS];
    Event overlaps[MAX_EVENTS];
    int calendar_size;
    int overlaps_size;
} MyCalendarTwo;

// 생성자 역할을 하는 함수
void myCalendarTwoInit(MyCalendarTwo* obj) {
    obj->calendar_size = 0;
    obj->overlaps_size = 0;
}

// 겹치는 구간을 확인하고, 겹치는 구간을 반환하는 함수
bool overlap(Event a, Event b, Event* result) {
    int overlap_start = a.start > b.start ? a.start : b.start;
    int overlap_end = a.end < b.end ? a.end : b.end;

    if (overlap_start < overlap_end) {
        result->start = overlap_start;
        result->end = overlap_end;
        return true;
    }
    return false;
}

// 새로운 예약을 추가하는 함수
bool myCalendarTwoBook(MyCalendarTwo* obj, int start, int end) {
    Event new_event = {start, end};
    Event temp_overlap;

    // Step 1: 삼중 예약이 되는지 확인
    for (int i = 0; i < obj->overlaps_size; i++) {
        if (overlap(new_event, obj->overlaps[i], &temp_overlap)) {
            return false;
        }
    }

    // Step 2: 이중 예약으로 인한 겹침을 overlaps에 추가
    for (int i = 0; i < obj->calendar_size; i++) {
        if (overlap(new_event, obj->calendar[i], &temp_overlap)) {
            obj->overlaps[obj->overlaps_size++] = temp_overlap;
        }
    }

    // Step 3: 새로운 예약을 calendar에 추가
    obj->calendar[obj->calendar_size++] = new_event;
    return true;
}

int main() {
    MyCalendarTwo calendar;
    myCalendarTwoInit(&calendar);

    // 예제 예약 추가
    printf("%d\n", myCalendarTwoBook(&calendar, 10, 20)); // 출력: 1 (성공)
    printf("%d\n", myCalendarTwoBook(&calendar, 15, 25)); // 출력: 1 (성공)
    printf("%d\n", myCalendarTwoBook(&calendar, 20, 30)); // 출력: 1 (성공)
    printf("%d\n", myCalendarTwoBook(&calendar, 5, 15));  // 출력: 0 (삼중 예약이므로 실패)

    return 0;
}
