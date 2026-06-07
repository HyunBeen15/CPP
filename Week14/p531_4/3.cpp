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

    int& operator()(int a, int b) {
        return list[a * b];
    }
};

int main() {
    SampleList sample;

    cout << "sample(3, 4) = "
         << sample(3, 4) << endl;

    sample(3, 4) = 555;

    cout << "변경 후 sample(3, 4) = "
         << sample(3, 4) << endl;

    return 0;
}