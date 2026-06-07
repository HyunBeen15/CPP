#include "TimeHMS.h"

int main() {
    TimeHMS t1(1, 20, 30);

    cout << "시: " << t1[0] << endl;
    cout << "분: " << t1[1] << endl;
    cout << "초: " << t1[2] << endl;

    return 0;
}