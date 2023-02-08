#include <bits/stdc++.h>
using namespace std;
vector <int> v;


bool isPrime(int n){
    for(int j=2; j*j<=n;j++){
            if(n%j==0) {
               return false;
            }
    }
    
    return true;
}

void getPrimes(int n) {
    for(int i = 2; i <= n; i++) {
        if(isPrime(i)) v.push_back(i);
    }
}


int main(){
    int n; cin >>n;
    getPrimes(n);
    for(int i=0; i<=v.size(); i++){
        for(int j=0; j<=v.size();j++ ){
            if(v[i] +v[j]==n) {
                cout <<v[i]<< " " <<v[j];
                return 0;
            }
        }
    }

}