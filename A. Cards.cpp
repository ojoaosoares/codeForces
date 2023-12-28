#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() { _

    char letter;
    int size, ones = 0, zeros = 0;

    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cin >> letter;

        if (letter == 'z') zeros++;
        else if (letter == 'n') ones++;
    }


    for (int i = 0; i < ones; i++)
        cout << 1 << " ";

    for (int i = 0; i < zeros; i++)
        cout << 0 << " ";

    cout << '\n';




}
