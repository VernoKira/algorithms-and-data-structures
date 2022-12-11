#include <bits/stdc++.h>
using namespace std;
bool Prime(int m){
    if(m== 0 || m== 1) return false;
    for(int i = 2; i * i <=m; i++){
        if(m% i == 0) return false;
    }
    return true;
}
int main(){
    int m; cin >> m;
    vector<int> a;
       for(int i = 1; i < 100000; i++){
        if(Prime(i)){
            a.push_back(i);
        }
    }
    cout << a[m - 1];
}