#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);


const char diferent(const char c1, const char c2)
{

    if(c1 != 'S' && c2 != 'S') return 'S';
    else if(c1 != 'E' && c2 != 'E') return 'E';
    return 'T';

}

int main() { _


    int n, s;
    long p = 0;
    ;

    cin >> n >> s;

    set<string> cards;

    string card;

    for (int i = 0; i < n; i++)
    {
        cin >> card;
        cards.insert(card);
    }


    for(set<string>::iterator it1 = cards.begin(); it1 !=  prev(cards.end()); it1++)
    {
        for(set<string>::iterator it2 =  next(it1); it2 != cards.end(); it2++)
        {
            string candidat;
            for (int i = 0; i < s; i++)
            {
                if((*it1)[i] == (*it2)[i]) candidat += (*it1)[i];
                else candidat += diferent((*it1)[i],(*it2)[i]);
            }

            if(cards.find(candidat) != cards.end()) p++;
        }

    }


    cout << p/3 << '\n' ;
}

