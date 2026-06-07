#include "TimeHMS.h"

int main() {
    TimeHMS t1(1, 20, 30), t2;

    t2 = 2 * t1; // 정수와 TimeHMS 객체 곱셈

    cout << "2 * t1 = " << t2 << endl;

    return 0;
}