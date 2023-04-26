// Topic : DP on Strings
// Problem : Edit Distance


// Method 4 : Using Space Optimization (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*m)
// Reason : As we are using two nested For Loops (n and m iterations)


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(m)
// Reason : Using vector data structure of m size

// Total Space Complexity : O(m)
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(m) (i.e O(1) = O(1)+O(m))


// Answer : 5

#include <bits/stdc++.h>
using namespace std;

// IMPORTANT NOTE : With Index Shifting

int main()
{
    string s = "intention", t = "execution";
    int n = s.size(), m = t.size();
    vector<int> previous(m+1, -1);

    for (int i = 0; i < n+1; i++)
    {
        vector<int> current(m+1, -1);
        for (int j = 0; j < m+1; j++)
        {
            // Base Case
            if(i == 0 or j == 0) {
                if(i == 0) current[j] = j;
                else current[j] = i;
            }
            // Recursive Case
            else {
                if(s[i-1] == t[j-1]) current[j] = 0 + previous[j-1];
                else {
                    // 1. Insert
                    int insert = current[j-1];
                    // 2. Remove
                    int remove = previous[j];
                    // 3. Replace
                    int replace = previous[j-1];

                    current[j] = 1 + min(insert, min(remove, replace));
                }
            }
        }
        previous = current;
    }
    
    cout<<"Answer : "<<previous[m];
    return 0;
}