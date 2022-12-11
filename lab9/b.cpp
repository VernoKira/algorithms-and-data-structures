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
    string t; cin >> t;
    int n; cin >> n;
    string s; cin >> s;
    string st="";
    st = t + '#' +s;
    int cnt=0;
    vector<int> v = prefix_function(st);
    for(int i=0; i<st.size();i++){
        if(v[i]==t.size()){
            cnt++;
        }
    }
    if(cnt>=n) cout << "YES";
    else cout <<"NO";

}