#include <iostream>
using namespace std;

class Point {          // 부모 클래스
protected:
    int x, y;

public:
    Point(int xx, int yy)
        : x(xx), y(yy) {
    }

    void draw() {                                              // 부모 클래스 draw 함수
        cout << x << "," << y << "에 점을 그려라.\n"; 
    }
};

class Rectangle : public Point {                               // 자식 클래스
private: 
    int width, height;

public:
    Rectangle(int xx, int yy, int w, int h): Point(xx, yy), width(w), height(h) {  // 생성자
    }

    void draw() {    // draw 함수 재정의(오버라이딩)

        cout << x << "," << y << "에 가로 " << width << " 세로 " << height << "인 사각형을 그려라.\n";  // 사각형 정보 출력
    }
};

int main() {
    Rectangle r(2, 3, 100, 200);    // 객체 생성

    r.draw();                       // Rectangle의 draw 함수 호출

    return 0;
}