#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 4, k = 17, fact = 1;
    vector<int> numbers;
    for (int i = 1; i < n; i++)
    {
        fact *= i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    
    k -= 1;
    string ans = "";
    while(1) {
        ans += to_string(numbers[k/fact]);
        numbers.erase(numbers.begin() + (k/fact));
        if(numbers.size() == 0) {
            break;
        }
        k %= fact;
        fact /= numbers.size();
    }
    cout<<ans<<endl;
    return 0;
}