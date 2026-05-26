#include <iostream>
using namespace std;
class Sample1{
public:
    Sample1() { }
    virtual void play() { cout << "1번 sample" << endl; }    // 가상함수
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
    Sample2* arr[4];                               // Sample1* 에서 Sample2*로 수정
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

// 현재 main함수 안의 코드를 보면 arr[0] = a를 저장하려고 한다. a는 Sample1* 이다.
// 부모 클래스 객체(Sample1*)를 자식 클래스 포인터(Sample2*)에 넣을 수 없기 때문에 수정된 코드는 실행 불가능하다.

// 예상 출력 결과
// 컴파일 오류 발생