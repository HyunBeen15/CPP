#include "TimeHMS.h"

int main() {
    TimeHMS t1(1, 20, 30), t2(4, 35, 46);

    cout << "t1 == t2 : " << (t1 == t2) << endl; // 같으면 1
    cout << "t1 != t2 : " << (t1 != t2) << endl; // 다르면 1

    return 0;
}