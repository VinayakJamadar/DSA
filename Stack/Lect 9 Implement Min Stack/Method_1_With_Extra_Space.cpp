// Problem: Implement Min Stack
// Min Stack is a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Method 1: With Extra Space

// Time Complexity: O(1)
// Reason: Same as Simple Stack

// Space Complexity: O(n)
// Reason: Using Extra Supportive Stack 'sSt' which at Worst Case (if all pushing elements are reverse stored) stores all 'n' element

#include<bits/stdc++.h>
using namespace std;

class minStack {
    private:
        // Stack
        stack<int> st;
        // Support Stack
        stack<int> sSt;

    public:
        // push Operation
        void push(int el) {
            st.push(el);
            if(sSt.empty() || sSt.top() >= el) {
                sSt.push(el);
            }
        }

        // pop Operation
        int pop() {
            if(st.empty()) return -1;
            int ans = st.top();
            st.pop();
            if(sSt.top() == ans) sSt.pop();
            return ans;
        }

        // getMin Operation
        int getMin() {
            if(sSt.empty()) return -1;
            return sSt.top();
        }

        // top Operation
        int top() {
            if(st.empty()) return -1;
            return st.top();
        }
};

int main() {
    // {18, 19, 29, 15}
    minStack mSt;
    cout << "push(18)" << endl;
    mSt.push(18);
    cout << "push(19)" << endl;
    mSt.push(19);
    cout << "push(29)" << endl;
    mSt.push(29);
    cout << "push(15)" << endl;
    mSt.push(15);
    cout << "top() " << mSt.top() << endl;
    cout << "getMin() " << mSt.getMin() << endl;
    cout << "pop() " << mSt.pop() << endl;
    cout << "top() " << mSt.top() << endl;
    cout << "getMin() " << mSt.getMin() << endl;
    return 0;
}