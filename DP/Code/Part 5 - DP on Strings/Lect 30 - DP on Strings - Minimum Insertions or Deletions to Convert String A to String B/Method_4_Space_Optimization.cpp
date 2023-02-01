// Topic : DP on Strings
// Problem : Minimum Insertions Deletions to Convert String A to String B


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

// IMPORTANT NOTE : We have not done the Index Shifting. So Code is different than Striver

int main()
{
    string s = "abcd", t = "anc";
    int n = s.size(), m = t.size();
    vector<int> previous(m, -1);

    for (int i = 0; i < n; i++)
    {
        vector<int> current(m, -1);
        for (int j = 0; j < m; j++)
        {
            // Base Case
            if(s[i] == t[j]) {
                if(i == 0 or j == 0) current[j] = 1;
                else current[j] = 1 + previous[j-1];
            }
            // Recursive Case
            else {
                if(i == 0 or j == 0) {
                    if(i == 0 and j == 0) current[j] = 0;
                    else if(j == 0) current[j] = previous[j];
                    else current[j] = current[j-1];
                }
                else current[j] = max(previous[j], current[j-1]);
            }
        }
        previous = current;
    }
    
    cout<<"Answer : "<<n + m - (2 * previous[m-1]);
    return 0;
}