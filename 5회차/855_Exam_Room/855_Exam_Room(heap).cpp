#include <iostream>
#include <queue>
#include<tuple>


using namespace std;



class ExamRoom {
public:

    int n;
    priority_queue<tuple<int, int, int>> heap; //세개가 들어가서 tuple로 들어가기.

    ExamRoom(int n): n(n) {
        int dist = distance(0, n-1);
        heap.push({-dist, 0, n-1});
    }

    int distance(int start, int end){
        if (start == 0 || end == n-1){
            return end- start;
        }
        return (end - start) /2;
    }
    
    int seat() {
        
        int pos = 0;
        int dist, start, end;
        tie(dist, start, end) = heap.top();
        heap.pop();
        dist = -dist;


        if(start == 0){pos= 0;}
        else if(end == n-1){pos == n-1;}
        else{pos = start + dist;}

        if (pos > start){
            heap.push({-distance(start, pos-1), start, pos-1});
        }
        else if (pos< start){
            heap.push({-distance(pos+1, end), pos+1, end});
        }

        return pos;
    }
    
    void leave(int p) {
        // 떠난 좌석 기준으로 병합할 구간 찾기
        std::tuple<int, int, int> leftSegment, rightSegment;
        bool hasLeft = false, hasRight = false;

        std::vector<std::tuple<int, int, int>> heapContents;

        // 힙 내용을 모두 꺼내면서 병합할 구간 확인
        while (!heap.empty()) {
            auto segment = heap.top();
            heap.pop();
            int start = std::get<1>(segment);
            int end = std::get<2>(segment);

            if (end + 1 == p) {
                leftSegment = segment;
                hasLeft = true;
            } else if (start - 1 == p) {
                rightSegment = segment;
                hasRight = true;
            } else {
                heapContents.push_back(segment);
            }
        }

        // 새 구간 시작과 끝 계산
        int newStart = p, newEnd = p;
        if (hasLeft) {
            newStart = std::get<1>(leftSegment);
        }
        if (hasRight) {
            newEnd = std::get<2>(rightSegment);
        }

        // 병합된 새 구간 삽입
        heap.push(std::make_tuple(-distance(newStart, newEnd), newStart, newEnd));

        // 힙 내용 복원
        for (const auto& segment : heapContents) {
            heap.push(segment);
        }

    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */