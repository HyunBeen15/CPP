#include "TimeHMS.h"

int main() {
    TimeHMS t1(1, 20, 30);

    cout << "전체 시간: " << double(t1) << "시간" << endl;

    return 0;
}