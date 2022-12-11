#include <bits/stdc++.h>
using namespace std;
#define ll long long
int rab(string s, string t) {
    // long long p[s.size()];
    long long q = 2147483647;
    int n = s.size();
    vector<ll> p(n);
    
    p[0] = 1;
    for (int i = 1; i < n; ++i) {
        p[i] = p[i - 1] * q;
    }
    ll ht = 0;
    for (int i = 0; i < t.size(); ++i) {
        ht += (t[i] - 'a' + 1) * p[i]; 
    }
    vector<ll> hs(n);
    for (int i = 0; i < n; ++i) {
        hs[i] = (s[i] - 96) * p[i];
        if (i > 0) hs[i] += hs[i - 1];
    }
    for (int i = 0; i + t.size() - 1 < n; i++) {
        ll cur = hs[i + t.size() - 1];
        if (i > 0) cur -= hs[i - 1];
        if (ht * p[i] == cur) return 1;
    }
    return 0;
}

string getCommonString(string* arr, string smallest, int k) {
    for(int i = smallest.size() - 1; i > 0; i--) {
        for(int j = 0; j + i < smallest.size(); j++) {
            string cur = smallest.substr(j, i + 1);
            bool found = true;
            for(int l = 0; l < k; l++) {
                if(smallest == arr[l]) continue;
                if(rab(arr[l], cur) == 0) {
                    found = false;
                    break;
                }
            }
            if(found) {
                return cur;
            }
        }
    }
    return "";
}

int main() {
    int k;
    cin >> k;

    string arr[k];
    string smallest;
    for(int i = 0; i < k; i++) {
        cin >> arr[i];
        if(i < 1) smallest = arr[i];
        else if(smallest.size() > arr[i].size()) smallest = arr[i];
    }

    cout << getCommonString(arr, smallest, k);
    
    return 0;
}