#include <iostream>

int main()
{
    int n, a, b;

    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        std::cin >> a >> b;
        if (b == a) std::cout << 0  << '\n';
        else if ((a % 2 != b % 2 && b > a) || (a % 2 == b % 2 && a > b)) std::cout << 1 << '\n';
        else std::cout << 2 << '\n';
    }

    return 0;
}
