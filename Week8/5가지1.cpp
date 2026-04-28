#include <iostream>
using namespace std;

class Complex {
public:
    double real, imag;

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    void print() {
        cout << real << " + " << imag << "i\n";
    }

    // 3. 멤버 함수, void, 참조 전달
    void Complex::add(Complex& a, Complex& b) {
        real = a.real + b.real;                                            // 결과는 호출 객체(this)에 저장됨 
        imag = a.imag + b.imag;                                            // 결과는 호출 객체(this)에 저장됨
    }

    // 4. 멤버 함수, return, 참조 전달
    Complex Complex::add(Complex& b) {                    
        return Complex(real + b.real, imag + b.imag);                      // this + b 결과를 새 객체로 반환 
    }

    // 5. 연산자 오버로딩
    Complex Complex operator+(Complex& b) {
        return Complex(real + b.real, imag + b.imag);                      // a + b 형태로 사용 가능
    }
};

// 1. 일반 함수, void, 참조 전달
void add(Complex& a, Complex& b, Complex& c) {
    c.real = a.real + b.real;                                              // 결과를 세 번째 인자 result에 저장
    c.imag = a.imag + b.imag;                                              // 결과를 세 번째 인자 result에 저장
}

// 2. 일반 함수, return, 값 전달
Complex add(Complex a, Complex b) { 
    return Complex(a.real + b.real, a.imag + b.imag);                           // a, b가 값으로 전달되므로 복사 발생 가능
}

int main() {
    Complex a(1, 2);
    Complex b(3, 4);
    Complex c;

    cout << "a = ";
    a.print();

    cout << "b = ";
    b.print();

    cout << "\n1. 일반 함수, void, 참조 전달\n";
    add(a, b, c);
    c.print();

    cout << "\n2. 일반 함수, return, 값 전달\n";
    c = add(a, b);
    c.print();

    cout << "\n3. 멤버 함수, void, 참조 전달\n";
    c.add(a, b);
    c.print();

    cout << "\n4. 멤버 함수, return, 참조 전달\n";
    c = a.add(b);
    c.print();

    cout << "\n5. 연산자 오버로딩\n";
    c = a + b;
    c.print();

    return 0;
}