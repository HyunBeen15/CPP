#include <iostream>
using namespace std;

class Point {                 // 부모 클래스
protected:
    int x, y;

public:
    Point(int xx, int yy): x(xx), y(yy) {   // 생성자
    }
};

class Rectangle : public Point {            // 자식 클래스
private: 
    int width, height;

public:
    Rectangle(int xx, int yy, int w, int h): Point(xx, yy), width(w), height(h) {    // 초기화 리스트 사용
    // 부모 클래스 생성자 호출, width 초기화, height 초기화
    }

    void show() {                   // 출력 함수

        cout << "x = " << x << ", y = " << y << endl;                       // 부모 클래스 멤버 출력

        cout << "width = " << width << ", height = " << height << endl;     // Rectangle 멤버 출력
    }
};

int main() {
    Rectangle r(2, 3, 100, 200);    // 객체 생성

    r.show();   // 결과 출력
 
    return 0;
}