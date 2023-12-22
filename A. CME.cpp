#include <iostream>

int main()
{

    int n, matches;
    std::cin >> n;


    for(int i = 0; i < n; i++)
    {
        std::cin >> matches;

        if(matches == 2) std::cout << 2 << '\n';
        else std::cout << matches % 2 << '\n';

    }


    return 0;
}
