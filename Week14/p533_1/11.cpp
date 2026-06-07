#include "TimeHMS.h"

int main() {
    TimeHMS t1(1, 20, 30), t2(4, 35, 46), t3;

    cout << "t1 = " << t1 << endl;
    cout << "t2 = " << t2 << endl;

    cout << "t1 + t2 = " << t1 + t2 << endl;
    cout << "t2 - t1 = " << t2 - t1 << endl;

    cout << "t1 == t2 : " << (t1 == t2) << endl;
    cout << "t1 != t2 : " << (t1 != t2) << endl;

    ++t1;
    cout << "++t1 = " << t1 << endl;

    --t1;
    cout << "--t1 = " << t1 << endl;

    t1++;
    cout << "t1++ = " << t1 << endl;

    t1--;
    cout << "t1-- = " << t1 << endl;

    cout << "t1[0] = " << t1[0] << endl;
    cout << "t1[1] = " << t1[1] << endl;
    cout << "t1[2] = " << t1[2] << endl;

    cout << "int(t1) = " << int(t1) << "초" << endl;
    cout << "double(t1) = " << double(t1) << "시간" << endl;

    t3 = 2 * t1;
    cout << "2 * t1 = " << t3 << endl;

    return 0;
}