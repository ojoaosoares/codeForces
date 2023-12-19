#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// const int calculateCost(const std::string &s) { First version that exceded the time limit

//     const int size = s.length(); 
//     std::string t = s; 
//     char auxiliar; // The varible that is used to assit changing the bits in the string
//     int pos = -1; // The target position where the char will be taken out
    
//     for (int first_counter = 0; first_counter < size; first_counter++)
//     {
//         if(t[first_counter] == s[first_counter]) // If the bit is still the same as the original
//         {
//             pos = -1;
//             for (int second_counter = first_counter + 1; second_counter < size; second_counter++)
//                 if(t[first_counter] != t[second_counter]) // If exist a posterior char that can be changed
//                 {
//                     pos = second_counter;
//                     break;
//                 }
            
//             if(pos == -1) return size - first_counter; // If a good position hasn't been found, we return the number of bits that cannot be change, 
//             //that is equal to the amount of bits that will be ereased

//             auxiliar = t[first_counter];
//             t[first_counter] = t[pos];
//             t[pos] = auxiliar;
//         }
        
//     }
//     // If everything goes fine, we don't need to erease any single bit, so the cost is 0
    
//     return 0;
    
// }


const int calculateCost(const std::string &s) {

    const int size = s.length(); 
    std::vector<int> amount_0s_in_t;
    int total_of_1s_in_s = 0;

    for (int i = 0; i < size; i++)
    {
        if(s[i] == '1') total_of_1s_in_s++;
    
        amount_0s_in_t.push_back(total_of_1s_in_s);
    }

    int total_of_0s_in_s = size - total_of_1s_in_s;

    std::reverse(amount_0s_in_t.begin(), amount_0s_in_t.end());

    int op;
    for (op = 0; op < size; op++)
        if(total_of_0s_in_s >= amount_0s_in_t[op] && ((size - op) - amount_0s_in_t[op]) <= total_of_1s_in_s) break;

    return op;



}


int main() {

    int n;
    std::cin >> n;
    
    std::string s;

    for (int i = 0; i < n; i++)
    {
        std::cin >> s;    
        std::cout << calculateCost(s) << std::endl;
    }
    

    return 0;
}