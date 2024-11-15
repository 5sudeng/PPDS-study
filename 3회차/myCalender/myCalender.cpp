#include <iostream>
#include <vector>

class MyCalendarTwo {
private:
    std::vector<std::pair<int, int>> calendar;   // 모든 예약을 저장하는 벡터
    std::vector<std::pair<int, int>> overlaps;   // 겹친 예약을 저장하는 벡터

    // 두 구간이 겹치는지 확인하고, 겹치는 구간을 반환하는 함수
    bool overlap(const std::pair<int, int>& a, const std::pair<int, int>& b, std::pair<int, int>& result) {
        int overlap_start = std::max(a.first, b.first);
        int overlap_end = std::min(a.second, b.second);

        if (overlap_start < overlap_end) {
            result = {overlap_start, overlap_end};
            return true;
        }
        return false;
    }

public:
    // 생성자
    MyCalendarTwo() {}

    // 새로운 예약을 추가하는 함수
    bool book(int start, int end) {
        std::pair<int, int> new_event = {start, end};
        std::pair<int, int> temp_overlap;

        // Step 1: 삼중 예약이 되는지 확인
        for (const auto& o : overlaps) {
            if (overlap(new_event, o, temp_overlap)) {
                return false;
            }
        }

        // Step 2: 이중 예약으로 인한 겹침을 overlaps에 추가
        for (const auto& e : calendar) {
            if (overlap(new_event, e, temp_overlap)) {
                overlaps.push_back(temp_overlap);
            }
        }

        // Step 3: 새로운 예약을 calendar에 추가
        calendar.push_back(new_event);
        return true;
    }
};

int main() {
    MyCalendarTwo myCalendar;

    // 예제 예약 추가
    std::cout << myCalendar.book(10, 20) << std::endl; // 출력: 1 (성공)
    std::cout << myCalendar.book(15, 25) << std::endl; // 출력: 1 (성공)
    std::cout << myCalendar.book(20, 30) << std::endl; // 출력: 1 (성공)
    std::cout << myCalendar.book(5, 15) << std::endl;  // 출력: 0 (삼중 예약이므로 실패)

    return 0;
}
