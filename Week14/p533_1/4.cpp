#include "TimeHMS.h"

int main() {
    TimeHMS t1(1, 20, 30);

    ++t1; // 전위 ++ : 1시간 증가
    cout << "++t1 = " << t1 << endl;

    --t1; // 전위 -- : 1시간 감소
    cout << "--t1 = " << t1 << endl;

    return 0;
}