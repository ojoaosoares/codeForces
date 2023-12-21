#include <iostream>
#include <vector>

int main()
{

    int n;
    std::cin >> n;

    int *array = new int[n];

    for (int i = 0; i < n; i++) std::cin >> array[i];

    int menor, aux;

    std::vector<int*> swaps;

    for (int i = 0; i < n; i++) {
        menor = i;
        for (int j = i + 1; j < n; j++)
            if(array[j] < array[menor]) menor = j;

        if(menor != i) {

            aux = array[i];
            array[i] = array[menor];
            array[menor] = aux;

            int *swap = new int[2];
            swap[0] = i;
            swap[1] = menor;
            swaps.push_back(swap);
        }

    }


    std::cout << swaps.size()  << '\n';
    for (int i = 0; i < (int) swaps.size(); i++) {
        std::cout << swaps[i][0] << " " << swaps[i][1]  << '\n';
        delete[] swaps[i];
    }

    return 0;
}
