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
    vector<int> v = prefix_function(s);
    int cnt = 0;
    for(int i = 1; i < v.size(); i++){
        if(v[i - 1] == 0) continue;
        else if((i / (i - v[i - 1])) % 2 == 0 && i % (i - v[i - 1]) == 0) cnt++;
    }
    cout << cnt;
}