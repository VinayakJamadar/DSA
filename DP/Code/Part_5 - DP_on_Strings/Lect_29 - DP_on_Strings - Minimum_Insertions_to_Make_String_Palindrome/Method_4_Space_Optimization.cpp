// Topic : DP on Strings
// Problem : Minimum Insertions to Make String Palindrome


// Method 4 : Using Space Optimization (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*n)
// Reason : As we are using two nested For Loops (n and m iterations)


// Auxilliary Space Complexity : O(1)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O(n)
// Reason : Using vector data structure of n size

// Total Space Complexity : O(n)
// Reason : Sum of Auxilliary Space Complexity O(1) and Non-Auxilliary Space Complexity O(n) (i.e O(1) = O(1)+O(n))

#include <bits/stdc++.h>
using namespace std;

// IMPORTANT NOTE : We have not done the Index Shifting. So Code is different than Striver

int main()
{
    string s = "edge", t = s;
    reverse(t.begin(), t.end());
    int n = s.size();
    vector<int> previous(n, -1);

    for (int i = 0; i < n; i++)
    {
        vector<int> current(n, -1);
        for (int j = 0; j < n; j++)
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
    
    cout<<"Answer : "<<n - previous[n-1];
    return 0;
}