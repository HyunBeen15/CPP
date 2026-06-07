#include <iostream>
#include <cstdlib>
using namespace std;

class SampleList {
    int list[100];

public:
    SampleList() {
        for(int x = 0; x < 100; x++)
            list[x] = rand() % 1000;
    }

    int& operator[](int index) {
        return list[index];   // 배열 항목 반환
    }
};

int main() {
    SampleList sample;

    cout << "sample[10] = "
         << sample[10] << endl;

    sample[10] = 999;

    cout << "변경 후 sample[10] = "
         << sample[10] << endl;

    return 0;
}