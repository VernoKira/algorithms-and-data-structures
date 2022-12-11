#include <bits/stdc++.h>
using namespace std;
#define ll long long
void rab(string s){
    unordered_map <ll, bool> mp;
        int cnt = 0;
        ll p = 465453145312312158;
        for(int i = 0; i < s.size(); i++){
            ll hash = 0;

            for(int j = i; j < s.size(); j++){
                hash = (hash * 256 + s[j]) % p;
                if (mp.find(hash) == mp.end()){
                    cnt++;
                }
                mp[hash] = true;
            }
        }
        cout << cnt;
}

int main(){
    string s; cin >> s;
    rab(s);
}