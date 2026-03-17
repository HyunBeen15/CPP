//1번
#include <iostream>

int main()
{
    for(int i = 1; i <= 5; ++i)             // = 초기값은 1, i가 5 이하면 1을 계속 더해라.
    {
    //     i = 1
        // std::cout << i << "\n";          //i를 출력하라. \n = 줄을 바꿔라.

        for(int j = 1; j <= i; ++j)
        {
            std::cout << j;
        }

        std::cout << "\n";
    }
}

//2번
#include <iostream>

int main()
{
    for(int i = 5; i >= 1; --i)// = 초기값은 1, i가 5 이하면 1을 계속 더해라.
    //     i = 1
        // std::cout << i << "\n";          //i를 출력하라. \n = 줄을 바꿔라.
    
    {
     for(int j = 5; j >= 6-i; --j)
        {
            std::cout << j;
        }

        std::cout << "\n";
    }
}

//3번
#include <iostream>

int main()
{
    for(int i = 1; i <= 5; ++i)
    {
        for(int j = 1; j <= 5-i; ++j)
        {
            std::cout << " ";
        }

        for (int j = i; j >= 1; --j)
        {
            std::cout << j;
        }
        
        std::cout << "\n";
    }
}

//4번
#include <iostream>

int main()
{
    for(int i = 1; i <= 5; ++i)
    {
        for(int j = 1; j <= 5-i; ++j)
        {
            std::cout << " ";
        }

        for (int j = i; j >= 1; --j)
        {
            std::cout << j;
        }

        for (int j = 2; j <= i; ++j)
        {
            std::cout << j;
        }
        
        std::cout << "\n";
    }
}