#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int max=-10000;
    stack <int> st;
    stack<int> max_int;
    while(n--){
        string s; cin >>s;
        if(s=="add"){
            int x; cin >> x;
            st.push(x);

            if(x>max){
                max = x;
                max_int.push(max);        
            }
        

        }

        if(s=="getmax"){
            if(!s.empty()){
               cout << max_int.top()<<endl;
            }
            else{
                cout <<  "error" << endl;
            }
        }
        if(s=="getcur"){
            if(s.empty()) cout << "error" << endl;

            else cout << st.top();
        }
        if(s=="delete"){
               if(!st.empty()) {
                    st.pop();
                }   
        }
    }
}