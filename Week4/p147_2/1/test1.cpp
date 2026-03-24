#include <iostream>
#include <algorithm>

int reverse(int a)
{
    int reverse_Number = 0;

    while(a)
    {
        int reverse_Number = 0;
        int digit = a % 10;
        reverse_Number = reverse_Number * 10 + digit;
        a /= 10;
    }

    return reverse_Number;
}

std::string reverse(std::string s)
{
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    int a;
    std::cin >> a;

    std::cout << reverse(a) << std::endl;

    std::string s;
    std::cin >> s;

    std::cout << reverse(s) << std::endl;
}

// int main()
// {
//     std::string s;
//     std::cin >> s;

//     std::cout << reverse(s) << std::endl;
// }