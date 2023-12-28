#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() { _


    string s;
    cin >> s;

    int cont = 0;


    string::iterator it = s.begin();

    while(true)
    {
        if(it == s.end() - 1 || s.begin() == s.end()) break;

        if(*it == *(it + 1))
        {
            cont++;
            s.erase(it, it + 2);

            if(it != s.begin()) it--;
        }

        else it++;
    }

    if(cont % 2) cout << "Yes \n" ;
    else cout << "No \n" ;


}
