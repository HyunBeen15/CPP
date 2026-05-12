#include <iostream>
#include <cstring>
using namespace std;

class Sample {
private:
    char* name;     // 동적 할당된 문자열 주소를 저장하는 포인터

public:
    Sample(const char * name) {                      // 생성자 
        this->name = new char[strlen(name) + 1];     // 문자열 저장 공간 동적 할당

        strcpy(this->name, name);                    // 문자열 복사
    }

    ~Sample() {                                      // 소멸자, 객체가 사라질 때 자동 호출
        delete[] name;                               // new로 할당한 배열 메모리 해제

        cout << "메모리 해제 완료" << endl;             // 소멸자 호출 확인용 출력
    }

    void print() {                                   // 출력 함수
        cout << "name: " << name << endl;            // name 출력
    }
};

int main() {
    Sample a("sample");
    
    a.print();

    return 0;
}