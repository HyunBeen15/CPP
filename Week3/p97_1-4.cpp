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