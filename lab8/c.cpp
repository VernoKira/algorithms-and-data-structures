#include <bits/stdc++.h>
#define ll long long
using namespace std;
int cnt = 0;

vector<int> :: iterator it;
set<int> st;

vector<int> rab(string s, string t){
    int n = s.size();
    vector<ll> p_pow(n);
    vector<int> res;
    ll p = 5;
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
        if (i > 0) hs[i] += hs[i - 1];
    }
    for (int i = 0; i + t.size() - 1 < n; i++) {
        ll cur = hs[i + t.size() - 1];
        if (i > 0) {
            cur -= hs[i - 1];
        }
        if (ht * p_pow[i] == cur) {
            res.push_back(i);
        }
    
    }
    return res;
}

int main() {
    string s; 
    cin >>s;
    int n; 
    cin >> n;
    for(int i=0; i<n; i++){
        string t;  cin >> t;

        vector<int> res = rab(s,t);

        for(int i=0; i<res.size();i++){
            for(int j=0 ; j<t.size();j++){
                st.insert(res[i] + j);
            }
        }
    }
    if(st.size()==s.size()) cout <<"YES";
    else cout <<"NO";
}