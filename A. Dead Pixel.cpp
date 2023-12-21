#include <iostream>
#include <algorithm>

int main()
{
    int n, a, b, x, y;


    std::cin >> n;


    for(int i = 0; i < n; i++) {

        std::cin >> a >> b >> x >> y;
        x++; y++;

        std::cout << std::max(std::max(x-1,a-x)*b, std::max(y-1,b-y)*a) << '\n';



    }

    return 0;
}
