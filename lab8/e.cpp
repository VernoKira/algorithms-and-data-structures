#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll n ;cin >>n;
    ll a[n];
    for (ll i = 0; i < n; i++){
        cin >> a[i];
    }
    for (ll i = 0; i <n; i ++){
        if(i) {
            cout << char((a[i] - a[i - 1]) /pow(2,i) + 97);
        }
         else cout << char(a[i] / pow(2,i)+ 97);
    }
}