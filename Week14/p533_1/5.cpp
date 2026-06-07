#include "TimeHMS.h"

int main() {
    TimeHMS t1(1, 20, 30);

    t1++;   // 후위 ++ : 1초 증가
    cout << "t1++ = " << t1 << endl;

    t1--;   // 후위 -- : 1초 감소
    cout << "t1-- = " << t1 << endl;

    return 0;
}