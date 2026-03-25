#include <iostream>
#include <algorithm>
#include <string>
#include "3.hpp"

std::string reverseString(std::string s)
{
    std::reverse(s.begin(), s.end());
    return s;
}

int main()
{
    std::string s;
    std::cout << "숫자를 입력하세요: ";
    std::cin >> s;

    std::cout << reverseString(s) << std::endl;

    return 0;
}
