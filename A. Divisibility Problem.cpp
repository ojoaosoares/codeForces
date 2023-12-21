#include <iostream>

int main()
{
    int n, a, b;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> a >> b;

        if(a%b) std::cout << (b - a%b) << '\n';
        else std::cout << 0 << '\n';
    }
    return 0;
}
