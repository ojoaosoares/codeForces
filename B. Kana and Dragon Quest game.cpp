#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() { _

    int n;
    cin >> n;

    while(n--)
    {
        int hp, void_ab, lightning;
        cin >> hp >> void_ab >> lightning;

        for (int i = 0; i < void_ab; i++)
        {
            if(hp <= lightning * 10 || ((int) floor(hp / 2.0)) < 10) break;
            hp = ((int) floor(hp / 2.0)) + 10;
        }

        hp -= lightning * 10;

        if(hp > 0) cout << "NO\n";
        else cout << "YES\n";
    }



}
