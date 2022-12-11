#include <bits/stdc++.h>
using namespace std;
vector<int> prefix_function (string s) {
 int n = (int) s.length();
 vector<int> pi (n);
 for (int i=1; i<n; ++i) {
  int j = pi[i-1];
  while (j > 0 && s[i] != s[j])
   j = pi[j-1];
  if (s[i] == s[j])  ++j;
  pi[i] = j;
 }
 return pi;
}

 int main(){
    string s; cin >> s;
    string t; cin >> t;
    string st="";
    st = t + '#' +s;
    int n;
    vector<int> res;
    vector<int> v = prefix_function(st);
    for(int i=0; i<st.size();i++){
        if(v[i]==t.size()){
            n = i-2*t.size();
            res.push_back(n);
        }
    }
    cout << res.size()<<'\n';
    for(auto i: res){
        cout << i+1 <<" ";
    }
    

}