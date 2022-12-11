#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> res;
vector<int> :: iterator it;

long long rab(string s){
    const int p = 11;
    const int m = 1e9 + 7;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 47) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

int main() {
    int n, cnt = 0; cin >> n;
    int sx = 2*n;
    vector<string> v;
    unordered_map<string, long long> m;
    string t;
    while(sx--){
       cin >> t;
       v.push_back(t);
       m[t] = -1;
    }
    
    for(auto i : v){
        if(cnt - n == 0){
            return 0;
        }
        if(m[to_string(rab(i))] == -1){
            cout << "Hash of string " << '"' << i << '"' << " is " << rab(i) << '\n';
            cnt++;
        }
    }
}