#include <iostream>

int main()
{

    int n, size, cont, smallest;

    int *prices;

    std::cin >> n;

    while(n--)
    {
        std::cin >> size;
        prices = new int[size];


        for(int j = 0; j < size; j++)
            std::cin >> prices[j];

        cont = 0;
        smallest = prices[size - 1];

        for (int j = size - 2; j >= 0; j--)
        {
            if(prices[j] <= smallest)
                smallest = prices[j];

            else cont++;
        }

        delete[] prices;

        std::cout << cont << '\n';

    }

    return 0;
}
