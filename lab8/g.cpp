#include <bits/stdc++.h>
#define ll long long
using namespace std;


void rab(string s,  string t){
    int n = s.size();
    vector<ll> p_pow(n);
    ll p = 45;
    p_pow[0] = 1; 
    for (int i = 1; i < n; ++i) {
        p_pow[i] = p_pow[i - 1] * p;
    }
    ll ht = 0;
    for (int i = 0; i < t.size(); ++i) {
        ht += (t[i] - 'a' + 1) * p_pow[i]; 
    }

    vector<ll> hs(n);
    for (int i = 0; i < n; ++i) {
        hs[i] = (s[i] - 96) * p_pow[i];
        if (i > 0) {
            hs[i] += hs[i - 1];
        }
        
    }
    int cnt=0;
    for (int i = 0; i + t.size() - 1 < n; i++) {
        ll cur = hs[i + t.size() - 1];
        if (i > 0) cur -= hs[i - 1];
        if (ht * p_pow[i] == cur) {
            cnt++;
        }
    }
    cout << cnt<<'\n';
}

int main() {
    string s; cin >> s;
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int l , r; cin >> l >> r;
        string t;
        for(int i=l-1;i<=r-1;i++){
            t+=s[i];
        }
        rab(s, t);
    }

    
    return 0;
}
