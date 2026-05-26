#include <iostream>
using namespace std;
class Sample1{
public:
    Sample1() { }
    void play() { cout << "1번 sample" << endl; }
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
int main(){                                          // 책에서는 void main()으로 나왔지만 코드 오류 발생 int main()으로 변경
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

// Sample1의 play() 함수는 가상함수가 아니기 때문에 arr[i]->play();를 실행해도 모두 Sample1::play()가 호출됨.

// 프로그램의 출력 결과
// 1번 sample
// 1번 sample
// 1번 sample
// 1번 sample