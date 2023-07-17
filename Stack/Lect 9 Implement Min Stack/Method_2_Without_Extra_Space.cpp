// Problem: Implement Min Stack
// Min Stack is a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Method 1: With Extra Space

// Time Complexity: O(1)
// Reason: Same as Simple Stack

// Space Complexity: O(1)
// Reason: O(1) as we are only using variable 'minEle'

#include<bits/stdc++.h>
using namespace std;

class minStack {
    private:
        // Stack
        stack<int> st;
        // Variable for Min Stack
        int minEle;

    public:
        // push Operation
        void push(int x) {
            if(st.empty()) {
                st.push(x);
                minEle = x;
            }
            else {
                if(x >= minEle) {
                    st.push(x);
                }
                else {
                    st.push(2 * x - minEle);
                    minEle = x;
                }
            }
        }

        // pop Operation
        int pop() {
            if(st.empty()) return -1;
            int ans = st.top(), y = st.top();
            st.pop();
            if(ans < minEle) {
                ans = minEle;
                minEle = 2 * minEle - y;
            }
            return ans;
        }

        // getMin Operation
        int getMin() {
            if(st.empty()) return -1;
            return minEle;
        }

        // top Operation
        int top() {
            if(st.empty()) return -1;

            if(st.top() >= minEle) return st.top();
            return minEle;
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