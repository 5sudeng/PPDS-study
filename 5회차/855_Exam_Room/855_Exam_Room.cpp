#include<iostream>
#include<set>


using namespace std;


class ExamRoom {
public:

    int n;
    set<int> students; // sorted ascending order, balanced binary search tree(RBT)
    ExamRoom(int n) :n(n){
      
    }
    
    int seat() {
        
        int student;
        if (students.empty()){
            student = 0;
        }

        else{
            int max_dist = *(students.begin());
            student = 0;

            
            auto prev = students.begin();
            for(set<int>::iterator it = next(students.begin()); it !=students.end(); ++it){
              
                auto curr =it;

                int dist  = (*curr-*prev) /2;

                if (dist > max_dist){
                    max_dist = dist;
                    student = *prev+ dist;

                }
                prev = it;
            }
            if (((n-1) - *(students.rbegin())) > max_dist){
                student = n-1;
            }
        }

        // 선택된 자리 정보 삽입:
        students.insert(student);

        return student;
    }
    
    void leave(int p) {
        students.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */