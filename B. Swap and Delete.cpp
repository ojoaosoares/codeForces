#include <iostream>
#include <string>

// Link of the problem : https://codeforces.com/contest/1913/problem/B

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

    int* amount_0s_in_t = new int[size]; // The array that contains the amount of 0-bits in the string t till a determined size

    int total_of_1s_in_s = 0; // Amount of 0-bits in the original string

    for (int i = 0; i < size; i++)
    {
        if(s[i] == '1') total_of_1s_in_s++; // Increses the counter of 1-bits of the original string
    
        amount_0s_in_t[i] = total_of_1s_in_s; // The total of 1-bits in determined part of the original string will be the total of 0-bits
        // in the string t in the same size
    }

    const int total_of_0s_in_s = size - total_of_1s_in_s; // The total of 0-bits in the original string will be the total size minus the amout of 1-bits

    int size_final_string; // It's the variable tha represents the size of the string t, what is the counterpart of the orignal string

    for (size_final_string = size; size_final_string > 0; size_final_string--)
        if(total_of_0s_in_s >= amount_0s_in_t[size_final_string - 1] && total_of_1s_in_s >= size_final_string - amount_0s_in_t[size_final_string - 1])
            break; // If the amout of 0-bits and 1-bits of the first string t of size size_final_string are smaller than the orinal string, then will be the 
            //exacly string we're looking for
    
    delete[] amount_0s_in_t;

    return size - size_final_string; // We return the diference of the size of the two strings, because it's exacly the cost of the operation of removim a caracter
    // Remembering that changing positions of two caracters cost nothing

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
