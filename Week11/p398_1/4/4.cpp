#include <iostream>
#include <cstring>
using namespace std;

class Sample {
private:
    char* name;      // 문자열 저장 포인터

public:
    Sample(const char* name) {                      // 일반 생성자
        this->name = new char[strlen(name) + 1];    // 문자열 공간 동적 할당

        strcpy(this->name, name);                   // 문자열 복사
    }

    Sample(const Sample& s) {                       // 복사 생성자, 다른 객체 이용해 새 객체 생성
        name = new char[strlen(s.name) + 1];        // 원본 객체 문자열 크기만큼 새 메모리 할당

        strcpy(name, s.name);                       // 원본 객체의 문자열을 새 메모리에 복사

        cout << "name: " << name << endl;           // 복사 생성자 호출 확인
    }

    void print() {                                  // 출력 함수
        cout << "name: " << name << endl;           // name 출력
    }
};

int main() {
    Sample a("sample");                             // 원본 객체 a 생성

    Sample b(a);                                    // 객체 a를 이용해 객체 b 생성

    b.print();                                      // b의 name 출력

    return 0;
}