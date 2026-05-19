#include <iostream>
using namespace std;

class Point {                       // 부모 클래스
protected:  //private               // protected → private로 변경
    int x, y;

public:
    Point(int xx, int yy)           // 생성자
        : x(xx), y(yy) {
    }
};

class Rectangle : public Point {    // 자식 클래스
public:
    Rectangle(int xx, int yy): Point(xx, yy) {     // 생성자
    }

    void show() {                   // 출력 함수

        cout << x << "," << y << endl;             // 오류 발생 부분, x와 y가 private이므로 접근 불가능
    }
};

int main() {

    Rectangle r(2, 3);

    r.show();

    return 0;
}

// x, y가 private, 부모 클래스 내부에서만 사용 가능하니까 자식 클래스 Rectangle에서 사용하면 오류 발생
// Rectangle 클래스에서 x와 y에 직접 접근할 수 없기 때문