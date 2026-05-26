#include <iostream>
using namespace std;
class Sample1{
public:
    Sample1() { }
    virtual void play() { cout << "1번 sample" << endl; }   // 가상함수로 수정
};
class Sample2 : public Sample1 {
public:
    Sample2() { }
    void play(){ cout << "2번 sample" << endl; }
};

class Sample3 : public Sample1 {
public: 
    Sample3() { }
    void play(){ cout << "3번 sample" << endl; }
};
class Sample4 : public Sample1 {
public: 
    Sample4() { }
    void play(){ cout << "4번 sample" << endl; }
};
int main(){                                          
    Sample1* arr[4];
    Sample1* a = new Sample1();
    Sample2* b = new Sample2();
    Sample3* c = new Sample3();
    Sample4* d = new Sample4();
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;
    for (int i = 0; i < 4; i++) arr[i]->play();
} 

// 동적 바인딩이 발생하여 실제 객체의 함수가 호출된다.

// 예상 출력 결과
// 1번 sample
// 2번 sample
// 3번 sample
// 4번 sample