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
    int n; cin >> n;
    while(n--){
        string s; cin >> s;
        int k; cin >> k;
        vector<int> v = prefix_function(s);
        cout << (s.size()-v.back())*k+ v.back()<<'\n';
    }
}