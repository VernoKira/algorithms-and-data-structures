#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >>n;
    vector <int> st;
    // int mx = -10000000;
    while(n--){
        string s;       
        cin >> s;
        if(s=="add"){
            int x; 
            cin >>x;
            st.push_back(x);
        
        }
        if(s=="getcur"){
            if(!st.empty()){
                cout << st.back()<<endl;
            } 
            else {
                cout <<"error"<<endl;
            }
        }
        if(s=="getmax"){
            if(st.empty()){
                cout <<"error"<<endl;
            }
            else{
                int max_num= *max_element(st.begin(), st.end());
                cout << max_num<<endl;
            }
           
        }
        if(s=="delete"){
            if(!st.empty()){
                st.pop_back();
            }
        }
    }
        
   }
