// Topic : DP on Strings
// Problem : Distinct Subsequences


// Method 4 : Using Space Optimization (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*m)
// Reason : As we are using two nested For Loops (n and m iterations)


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(m)
// Reason : Using vector data structure of m size

// Total Space Complexity : O(m)
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(m) (i.e O(1) = O(1)+O(m))

#include <bits/stdc++.h>
using namespace std;

// With Index Shifting and Using Single Array

#define mod 1000000007;

int main()
{
    string s = "babgbag", t = "bag";
    int n = s.size(), m = t.size();
    vector<int> previous(m+1, 0);

    // Base Case
    previous[0] = 1;
    
    // Recursive Case
    for (int i = 1; i < n+1; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            if(s[i-1] == t[j-1]) {
                previous[j] = (previous[j-1] + previous[j]) % mod;
            }
            else {
                previous[j] = previous[j];
            }
        }
    }

    cout<<"Answer : "<<previous[m];
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// // Without Index Shifting and Using Single Array

// #define mod 1000000007;

// int main()
// {
//     string s = "babgbag", t = "bag";
//     int n = s.size(), m = t.size();
//     vector<int> previous(m, 0);

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = m-1; j >= 0; j--)
//         {
//             // Base Case
//             if(j == 0) {
//                 if(i == 0) previous[0] = (s[i] == t[0]);
//                 else previous[0] = (s[i] == t[0]) + previous[0];
//             }
//             // Recursive Case
//             else if(i > 0) {
//                 if(s[i] == t[j]) {
//                     previous[j] = (previous[j-1] + previous[j]) % mod;
//                 }
//                 else {
//                     previous[j] = previous[j];
//                 }
//             }
//         }
//     }

//     cout<<"Answer : "<<previous[m-1];
//     return 0;
// }