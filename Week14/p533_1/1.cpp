#include "TimeHMS.h"

int main() {
    TimeHMS t1(1, 20, 30), t2(4, 35, 46), t3;

    t3 = t1 + t2; // + 연산자로 두 시간을 더함

    cout << "t1 + t2 = " << t3 << endl;
    return 0;
}