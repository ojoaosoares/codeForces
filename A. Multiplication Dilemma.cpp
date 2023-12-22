#include <iostream>

int main()
{

    int n, a , b, resto;
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {

        std::cin >> a >> b;

        resto = b % 10;

        if(resto)
        {
            int auxiliar = b;
            b = a;
            a = auxiliar;
        }

        else resto = a % 10;

        std::cout << a - resto << " x " << b << " + " << resto << " x " << b << '\n';
    }



    return 0;
};
