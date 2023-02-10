// Topic : DP on Strings
// Problem : Longest Common Subsequence


// Method 4 : Using Space Optimization (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*m)
// Reason : As we are using two nested For Loops (n and m iterations)


// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(m)
// Reason : Using vector data structure of m size

// Total Space Complexity : O(m)
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(m) (i.e O(1) = O(1)+O(m))

#include <bits/stdc++.h>
using namespace std;

// IMPORTANT NOTE : With Index Shifting

int main()
{
    string pattern = "ba*a?", text = "baaabab";
    int n = pattern.size(), m = text.size();
    vector<bool> previous(m+1, false);

    for (int i = 0; i < n+1; i++)
    {
        vector<bool> current(m+1, false);
        for (int j = 0; j < m+1; j++)
        {
            // Base Case
            if(i == 0 and j == 0) current[0] = true;
            else if(i == 0) current[j] = false;
            else if(j == 0) {
                bool flag = true;
                for (int k = 1; k <= i; k++)
                {
                    if(pattern[k-1] != '*') {
                        flag = false;
                        break;
                    }
                }
                current[j] = flag;
            }
            // Recursive Case
            else {
                if(pattern[i-1] == text[j-1] or pattern[i-1] == '?') current[j] = previous[j-1];
                else {
                    if(pattern[i-1] == '*') {
                        current[j] = previous[j] or current[j-1];
                    }
                    else {
                        current[j] = false;
                    }
                }
            }
        }
        previous = current;
    }
    
    cout<<"Answer : "<<(previous[m] ? "true" : "false");
    return 0;
}