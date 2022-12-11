#include <bits/stdc++.h>
using namespace std;

void merge(vector<pair<int, vector<string>>> a, int l1, int r1, int l2, int r2){
    int n1 = r1 - l1 + 1;
    vector<pair<int, vector<string>>> L(n1);
    for(int i = 0; i < n1; ++i){
        L[i] = a[l1 + i];
    }

    int n2 = r2 - l2 + 1;
    vector<pair<int, vector<string>>> R(n2);
    for(int i = 0; i < n2; ++i){
        R[i] = a[l2 + i];
    }

    int i = l1;
    int i1 = 0;
    int i2 = 0;

    while(i1 < n1 && i2 < n2){
        if(L[i1].first < R[i2].first){
            a[i++] = L[i1++];
        }else {
            a[i++] = R[i2++];
        }
    }
    
    //copy rest of L
    while(i1 < n1){
        a[i++] = L[i1++];
    }

    //copy rest of R
    while(i2 < n2){
        a[i++] = R[i2++];
    }

}

void msort(vector<pair<int, vector<string>>> a, int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        msort(a, l, m);
        msort(a, m + 1, r);
        merge(a, l, m , m + 1, r);
    }
}

int main(){
    int n; cin >>n;
    string s;
    while(n--){
        map<int,vector<string>> mp;
        while(1){
            cin >> s;
            mp[s.size()].push_back(s);
            if(cin.get()=='\n') break;
        }
        vector<pair<int, vector<string>>> v(mp.begin(), mp.end());
        msort(v, 0, v.size()-1);

        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v[i].second.size(); j++){
                cout << v[i].second[j]<<" ";
            }
        }
        cout << '\n';
   }
}