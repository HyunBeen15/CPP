#include <iostream>
#include <cstring>
using namespace std;

class Sample {
private:
    char* name;       // 문자열을 저장할 포인터 변수

public:
    Sample(const char* name) {                       // 문자열을 매개변수로 받는 생성자
        this->name = new char[strlen(name) + 1];  

        strcpy(this->name, name);                    // 매개변수 name을 객체의 name에 복사
    }

    void print() {                                   // 저장된 이름 출력 함수
        cout << "name: " << name << endl; 
    }
};

int main() {
    Sample a("Sample");    // 생성자 호출

    a.print();             // 객체 a의 name 출력

    return 0;
}