#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, x; cin >> n;
    while(n--){
        cin >> x;
        string s = "";
        while(x > 0){
            s += (x % 2 + '0');
            x /= 2;
            }
            stack<char> st;
            for(int i = 0; i < s.size(); i++){
                if(!st.empty() && st.top() == '0' && s[i] == '1') st.pop();
                else st.push(s[i]);     
            }

            if(st.empty()) cout << "YES" << endl;
            else cout << "NO" << endl; 
    }
    
}
