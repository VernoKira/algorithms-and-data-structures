#include <bits/stdc++.h>
#define ll long long
using namespace std;
void rabin(string s, pair <string, int> & t, int & mx_cnt){
    int n = s.size();
    vector<ll> p_pow(n);
    ll p = 31;
    p_pow[0] = 1; 
    for (int i = 1; i < n; ++i) {
        p_pow[i] = p_pow[i - 1] * p;
    }

    ll ht = 0;
    for (int i = 0; i < t.first.size(); ++i) {
        ht += (t.first[i] - 'a' + 1) * p_pow[i];
    }

    vector<ll> hs(n);
    for (int i = 0; i < n; ++i) {
        hs[i] = (s[i] - 96) * p_pow[i];
        if (i > 0) 
            hs[i] += hs[i - 1];
    }

    for (int i = 0; i + t.first.size() - 1 < n; i++) {
        ll cur = hs[i + t.first.size() - 1];
            if (i > 0) cur -= hs[i - 1];
                if (ht * p_pow[i] == cur){
                    t.second++;
                    if(mx_cnt < t.second) mx_cnt = t.second;
                }
    }
}

int main() {
    while(true){
        int n; cin >> n;
        if(n == 0) break;
        pair <string, int> v[n];
        for(int i = 0; i < n; i++){
            cin >> v[i].first;
            v[i].second = 0;
        }
        string s; cin >> s;
        int mx_cnt = -1;
        for(int i = 0; i < n; i++){
            rabin(s, v[i], mx_cnt);
        }
        cout << mx_cnt << endl;
        for(int i = 0; i < n; i++){
            if(v[i].second == mx_cnt){
                cout << v[i].first << endl;
            }
        }
    }
    return 0;
}