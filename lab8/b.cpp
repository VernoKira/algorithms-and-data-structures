#include <bits/stdc++.h>
#define ll long long
using namespace std;
int cnt =0;
map<int, int> res;
map<int, int> :: iterator it;
void rab(string s, string t){
    int n = s.size();
    vector<ll> p_pow(n);
   
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
            res[i]+=1;
    }
        
    }
    
}

int main() {
    string a,b, pl;
    cin >> a >>b >> pl;
    rab(a, pl);
    rab(b, pl);
    for(int i=0 ; i<max(a.size(), b.size());  i++){
        if(res[i]==2) {
            cnt++;
        }
    }
    cout << cnt;

}
