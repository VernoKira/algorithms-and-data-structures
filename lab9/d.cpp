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
    string s, t; int n, l = 1; 
    cin >> s >> n;
    s[0]+=32;
    vector <string> vs;
    while(n--){
        cin >> t;
        t[0]+=32;
        string ans = t + '#' + s;
        vector<int> v = prefix_function(ans);
        t[0]-=32;
        if(v[v.size() - 1] == l){
            vs.push_back(t);
        }
        else if(l < v[v.size() - 1]) {
            l = v[v.size() - 1];
            vs.resize(0);
            vs.push_back(t);
        }
    }
    cout << vs.size() << "\n";
    for(int i = 0; i < vs.size(); i++) {
        cout << vs[i] << "\n";
    }
}
