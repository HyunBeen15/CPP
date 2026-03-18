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