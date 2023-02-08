#include <bits/stdc++.h>
using namespace std;
void cntPrimes (int n) {
    int c = 2;
    int cnt = 0;
    bool found = false;
    while (n > 1) {
        if (n % c == 0) {
            if (!found) {
                cnt++;
            }
            found = true;
            n /= c;
        }
        else {
            c++;
            found = false;
        }
    }
    cout <<cnt;
}
int main(){
    int n; cin >>n;
    cntPrimes(n);
   
}