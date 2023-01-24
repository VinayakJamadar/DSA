#include<bits/stdc++.h>
using namespace std;

// 1.
// print all subsequence with sum equal to given sum
// void f(int ind, vector<int>& ds, int s, int sum, int arr[], int n) {
//     if(ind == n) {
//         if(s == sum) {
//             for (auto &&i : ds) cout<<i<<" ";
//             cout<<endl;
//         }
//         return ;
//     }

//     ds.push_back(arr[ind]);
//     s += arr[ind];
//     f(ind+1, ds, s, sum, arr, n);

//     ds.pop_back();
//     s -= arr[ind];
//     f(ind+1, ds, s, sum, arr, n);
// }

// int main(){
//     int n = 3, sum = 2;
//     int arr[] = {1, 2, 1};
//     vector<int> ds;
//     f(0, ds, 0, sum, arr, n);
//     return 0;
// }

// 2.
// print any one subsequence with sum equal to given sum
// bool f(int ind, vector<int>& ds, int s, int sum, int arr[], int n) {
//     if(ind == n) {
//         if(s == sum) {
//             for (auto &&i : ds) cout<<i<<" ";
//             cout<<endl;
//             return true;
//         }
//         return false;
//     }

//     ds.push_back(arr[ind]);
//     s += arr[ind];
//     if(f(ind+1, ds, s, sum, arr, n)) return true;

//     ds.pop_back();
//     s -= arr[ind];
//     if(f(ind+1, ds, s, sum, arr, n)) return true;

//     return false;
// }

// int main(){
//     int n = 3, sum = 2;
//     int arr[] = {1, 2, 1};
//     vector<int> ds;
//     f(0, ds, 0, sum, arr, n);
//     return 0;
// }

// 3.
// count subsequence with sum equal to given sum
// int f(int ind, int s, int sum, int arr[], int n){
//     if(ind == n) {
//         if(s == sum) return 1;
//         else return 0;
//     }

//     s += arr[ind];
//     int l = f(ind+1, s, sum, arr, n);

//     s -= arr[ind];
//     int r = f(ind+1, s, sum, arr, n);

//     return l+r;
// }

// int main(){
//     int n = 3, sum = 2;
//     int arr[] = {1, 2, 1};
//     cout<<f(0, 0, sum, arr, n)<<endl;
//     return 0;
// }

// 4.
// count subsequence with sum equal to given sum for array contain only positive numbers
int f(int ind, int s, int sum, int arr[], int n){
    if(s > sum) return 0;
    if(ind == n) {
        if(s == sum) return 1;
        else return 0;
    }

    s += arr[ind];
    int l = f(ind+1, s, sum, arr, n);

    s -= arr[ind];
    int r = f(ind+1, s, sum, arr, n);

    return l+r;
}

int main(){
    int n = 3, sum = 2;
    int arr[] = {1, 2, 1};
    cout<<f(0, 0, sum, arr, n)<<endl;
    return 0;
}