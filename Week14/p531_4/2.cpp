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

    int& operator()(int index) {
        return list[index];
    }
};

int main() {
    SampleList sample;

    cout << "sample(20) = "
         << sample(20) << endl;

    sample(20) = 777;

    cout << "변경 후 sample(20) = "
         << sample(20) << endl;

    return 0;
}