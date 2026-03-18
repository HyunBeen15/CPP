#include <iostream>

int main()
{
    int num;
    std::cout << "정수를 입력하세요 (100000 미만): ";
    std::cin >> num;
    
    if (num < 0 || num >= 100000) 
    {
        std::cout << "입력값이 범위를 벗어났습니다." << std::endl;
        return 1;
    }

    int 만 = num / 10000;
    int 천 = (num % 10000) / 1000;
    int 백 = (num % 1000) / 100;
    int 십 = (num % 100) / 10;
    int 일 = num % 10;

    if (만 > 0)
    {
        if (만 == 1) std::cout << "만 ";
        else std::cout << 만 << "만 ";
    }

    if (천 > 0)
    {
        if (천 == 1) std::cout << "천 ";
        else std::cout << 천 << "천 ";
    }

    if (백 > 0)
    {
        if (백 == 1) std::cout << "백 ";
        else std::cout << 백 << "백 ";
    }

    if (십 > 0)
    {
        if (십 == 1) std::cout << "십 ";
        else std::cout << 십 << "십 ";
    }

    if (일 > 0) std::cout << 일;

    std::cout << std::endl;

    return 0;
}