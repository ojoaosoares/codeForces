#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() { _

   long long n;
   
   cin >> n;

   while (n--)
   {
        long long currency_types, number_competitiions;
        cin >> currency_types >> number_competitiions;

        unordered_map<string,double> currencys;
        currencys["JD"] = 1;

        double total = 0;

        while (currency_types--)
        {
            double currency;
            string currency_name;
    
            cin >> currency_name >> currency;
            currencys[currency_name] = currency;
        }

        while (number_competitiions--)
        {   
            double value;
            string currency_name;

            cin >> value >> currency_name;;
            total += (value * currencys[currency_name]);
        }


        cout << fixed;
        cout.precision(6);
        cout << total << '\n';
   }


}
