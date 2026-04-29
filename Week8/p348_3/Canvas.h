#pragma once
#include <iostream>
#include <string>
using namespace std;

class Canvas {
    int width, height;
    string canvas[40][40];   // 화면 저장 배열

public:
    Canvas(int w, int h) : width(w), height(h) {
        clear();
    }

    void clear() {                                               // 화면 초기화
        for (int y = 0; y < height; y++)
            for (int x = 0; x < width; x++)
                canvas[y][x] = ".";
    }

    void draw(int x, int y, string val) {                        // 특정 위치에 그리기
        if (x >= 0 && x < width && y >= 0 && y < height)
            canvas[y][x] = val;
    }

    void print() {                                               // 화면 출력
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++)
                cout << canvas[y][x];
            cout << endl;
        }
    }
};