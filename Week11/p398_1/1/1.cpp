#include <iostream>
using namespace std;

class Sample {
private:
    static int count;       // 모든 객체가 공유하는 정적 변수, 객체 개수 저장

public:
    Sample() {     // 기본 생성자
        count++;
    }

    static void printCount() {                       // 객체 개수 출력 정적 함수
        cout << "객체 개수: " << count << endl;        
    }
};

int Sample::count = 0;                               // 정적 변수 클래스 밖에서 반드시 초기화

int main() {
    Sample::printCount();                            // 객체 생성 전 개수 출력

    Sample a;                                        // 첫 번째 객체 생성
    Sample::printCount();

    Sample b;                                        // 두 번째 객체 생성
    Sample::printCount();

    return 0;
}