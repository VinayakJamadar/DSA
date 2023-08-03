#include<bits/stdc++.h>
using namespace std;

void solve(int n, int s, int d, int h, int& count) {
    if(n == 0) {
        return ;
    }
    count++;
    solve(n-1, s, h, d, count);
    cout << "Moving Disc " << n << " from Plate " << s << " to " << d << endl;
    solve(n-1, h, d, s, count);
}

int main() {
    int n;
    cout << "Enter number of Discs: ";
    cin >> n;
    // 1. source plate
    // 2. helping plate
    // 3. destination plate
    int s = 1, h = 2, d = 3;
    int count = 0;
    cout << "Steps of Solving Tower of Honai for " << n << " Discs." << endl;
    solve(n, s, d, h, count);
    cout << "Steps of Solving Tower of Honai for " << n << " Discs : " << count << endl;
    return 0;
}