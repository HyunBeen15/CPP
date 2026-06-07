#include "TimeHMS.h"

int main() {
    TimeHMS t1(1, 20, 30), t2(4, 35, 46), t3;

    t3 = t2 - t1; // - 연산자로 두 시간의 차를 구함

    cout << "t2 - t1 = " << t3 << endl;
    return 0;
}