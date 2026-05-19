#include <iostream>
using namespace std;

class Point {               // 부모 클래스
protected:                  // 자식 클래스에서 접근 가능
    int x, y;

public:
    Point(int xx, int yy) : x(xx), y(yy) {}     // 생성자

    void draw() {                               // 점 출력 함수
        cout << x << "," << y << "에 점을 그려라.\n";
    }
};

class Rectangle : public Point {                // Rectangle 클래스가 Point 클래스를 상속받음
private:
    int width, height;                          // 가로, 세로 길이 저장

public:
    Rectangle(int xx, int yy, int w, int h)     // 생성자
        : Point(xx, yy) {

        width = w;                              // 가로 길이 저장
        height = h;                             // 세로 길이 저장
    }

    void show() {
        cout << "Rectangle 클래스 생성 완료\n";
    }
};

int main() {
    Rectangle r(2, 3, 100, 200);                // Rectangle 객체 생성
 
    r.show();
    
    return 0;
}