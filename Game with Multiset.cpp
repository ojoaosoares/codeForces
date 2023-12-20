#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>

// Link of the problem : https://codeforces.com/problemset/problem/1913/C


const bool findCombination(std::map<int, int> &ocorrencias, int target) {

    if (target == 0) return true;
    else if(target < 0 || ocorrencias.empty()) return false;
    
    for (std::map<int,int>::reverse_iterator rit = ocorrencias.rbegin(); rit != ocorrencias.rend(); ++rit)
    {
        if(target >= (*rit).first) target -= (*rit).first * std::min((*rit).second, target/(*rit).first);
        if(!target) return true;   
        
    }
    
    return false;
    
}



int main() {

    
    int command,n, number;
    std::map<int,int> potencias, ocorrencias;
    
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> command >> number;

        if (command == 1)
        {
            if(potencias.find(number) == potencias.end()) potencias.insert(std::pair<int, int>(number, pow(2,number)));

            if(ocorrencias.find(potencias[number]) == ocorrencias.end()) ocorrencias.insert(std::pair<int, int>(potencias[number], 1));
            else ocorrencias[potencias[number]]++;
        }

        else if (command == 2)
        {
            if(findCombination(ocorrencias,number)) std::cout << "YES" << std::endl;
            else std::cout << "NO" << std::endl;
        }
    }   
    
    


    return 0;
}
