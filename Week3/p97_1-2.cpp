#include <iostream>

int main()
{
    for(int i = 5; i >= 1; --i)            // = 초기값은 5, i가 1 이상이면 1을 계속 빼라.
    {
        for(int j = 5; j >= 6-i; --j)      //     i = 5, 위의 코드에서 i가 5부터 1씩 계속 빠지므로 6-i에도 1 2 3 4 5 와 같이 늘어난다.                   
        {
            std::cout << j;                // std::cout << j << "\n";          
        }                                  //j를 출력하라. \n = 줄을 바꿔라.

        std::cout << "\n";
    }
}