#include<stdio.h>
#include<stdlib.h>

/*
동적 할당과
struct 사용 및 array사용에 익숙해질 것!

*/

typedef struct{
    int n;
    int* seats; // 정렬된 좌석
    int seat_count;
} ExamRoom;



// 배열 삽입 및, 정렬 상태 유지
void insert_seat(ExamRoom* room, int seat){
    int i = room->seat_count-1; // 끝에서부터


    while(i>=0 && room->seats[i]>seat){
        room->seats[i+1] = room->seats[i]; // 한칸씩 뒤로 미루기.
        i--;
    }

    //위치 찾았다면 넣기 (i는 seat보다 작은 것을 찾은 것의 인덱스)
    room->seats[i+1] = seat;
    room->seat_count++;
}

void remove_seat(ExamRoom* room, int seat){
    // 특정 값 제거

    int i = 0;
    // 찾아서 제거
    while(i<room->seat_count && room->seats[i] != seat){
        i++;
    }
    //아예 끝 혹은 찾은 인덱스
    if(i<room->seat_count){
        //찾은 경우
        //제거 하고 이 이후꺼 다 앞으로 가져와야 함.
        for(int j = i; j<room->seat_count;j++){
            room->seats[j] = room->seats[j+1]; //뒤에거 앞으로 당기기
        }
        room->seat_count --;
    }

}

// 객체 생성
ExamRoom* examRoomCreate(int n) {
    ExamRoom* room = (ExamRoom*)malloc(sizeof(ExamRoom)); // 동적 할당
    room-> n= n;
    room->seats = (int*)malloc(n*sizeof(int)); // 최대 n개의 배열
    room ->seat_count = 0;
    return room;
}


//앉히기
int examRoomSeat(ExamRoom* obj) {
    
    int seat; // 앉을 위치
    if(obj->seat_count ==0){
        seat = 0;
    }

    else{
        int max_dist = obj->seats[0];
        seat = 0;


        for(int i =1; i<obj->seat_count ; ++i){
            int prev = obj->seats[i-1];
            int curr = obj->seats[i];

            int dist = (curr - prev)/2;

            if(dist>max_dist){
                max_dist = dist;
                seat = prev + dist;
            }
        }

        if((obj->seat_count -1 - obj->seats[-1]) > max_dist)
        {
            seat = obj->seat_count -1;
        }
    }
    insert_seat(obj, seat);

    return seat;
}

//떠나기
void examRoomLeave(ExamRoom* obj, int p) {
    remove_seat(obj, p);
}


//객체 제거
void examRoomFree(ExamRoom* obj) {
    free(obj->seats);
    free(obj);
}


