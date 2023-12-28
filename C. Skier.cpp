#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() { _

    int n, time;
    cin >> n;

    string movements;

    for (int i = 0; i < n; i++)
    {

        pair<int,int> start = {0,0};
        pair<int,int> end = start;
        set<pair<pair<int,int>,pair<int,int>>> coordenadas;

        cin >> movements;

        time = 0;

        for (int j = 0; j < (int) movements.length(); j++)
        {
            switch(movements[j])
            {
                case 'N':
                   end.first++;
                   break;
                case 'S':
                   end.first--;
                   break;
                case 'W':
                    end.second++;
                   break;
                case 'E':
                   end.second--;
                   break;
                default:
                   break;
            }

            pair<int,int> menor = start;
            pair<int,int> maior = end;

            if(menor != min(start,end)) {
                menor = end;
                maior = start;
            }

            if (coordenadas.find({menor,maior}) == coordenadas.end())
            {
                coordenadas.insert({menor,maior});
                time += 5;
            }

            else time++;

            start = end;
        }

        cout << time << '\n';
    }
}

