// Topic : Partition DP
// Problem : Minimum cost to cut the stick

// Method 2 : Using Memoization (Top-Down DP --> Recursive Cases to Base Cases)

// Time Complexity : O((c+2)*(c+2)*c)
// Reason : 
// As we avoided the overlapping subproblem. So mostly we have to calculate only (c+2)*(c+2) values (i.e calculating and storing the values in dp[i][j]) after that once we get a overlapping subproblem we will return the value from already calculate value (i.e dp[i][j]) and also using for loop of c size.
// So overall time complexity is O((c+2)*(c+2)*c)


// Auxilliary Space Complexity : O(c)
// Reason : Auxilliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxilliary Space Complexity : O((c+2)*(c+2))
// Reason : Using of vector of vector data structure

// Total Space Complexity : O(c) + O((c+2)*(c+2))
// Reason : Sum of Auxilliary Space Complexity O(c) and Non-Auxilliary Space Complexity O((c+2)*(c+2))

#include <bits/stdc++.h>
using namespace std;

// IMPORTANT NOTE :

// 1. Reason for inserting 0 at front and n at back
// To get the length of currently cutting stick.

// 2. Reason for sorting 'cuts' array : 
// Now the problem that we face here is that the information that marking 1 can be cut is not passed into the correct CUTS array of the left subproblem rather it is lying in the CUTS array of the right subproblem. 
// Therefore these subproblems cannot be solved independently, thus defeating the whole point of a recursive solution. 
// In order to solve this problem, we can initially sort the CUTS array. 
// By sorting the CUTS array, we know that at whatever point we are making the cut, the information on the markings of the left portion will always be present on the left side of the CUTS array partition. Similarly on the right side.

// 3. After Sorting subproblems are independent of each other 
// i.e After Sorting subproblems f(i, k-i) and f(k+1, j) are independent of each other

int f(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
    // Base Case
    if(i > j) return 0;
    // Recursive Case
    if(dp[i][j] != -1) return dp[i][j];
    int mini = INT_MAX;
    for (int k = i; k <= j; k++)
    {
        int cost = (cuts[j+1]-cuts[i-1]) + f(i, k-1, cuts, dp) + f(k+1, j, cuts, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}

int main()
{
    vector<int> cuts{1, 3, 4, 7};
    int n = 10, c = cuts.size();
    // Inserting 0 at front
    cuts.insert(cuts.begin(), 0);
    // Inserting n at back
    cuts.push_back(n);
    // Sort 'cuts'
    sort(cuts.begin(), cuts.end());
    
    vector<vector<int>> dp(c+2, vector<int> (c+2, -1));
    cout<<"Minimum cost to cut the stick is : "<<f(1, c, cuts, dp);
    return 0;
}