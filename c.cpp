#include <bits/stdc++.h>
using namespace std;
int main(){
string a ,b;
cin >>a >> b;
stack <char> a1, b1;
for(int i=0; i<=a.size(); i++){
    if(a[i] != '#'){
        a1.push(a[i]);
    }
    if(a[i]=='#'){
        a1.pop();
    }
}

for(int m=0; m<=b.size(); m++){
    if(b[m] !='#'){
        b1.push(b[m]);
    }
    if(b[m]=='#'){
        b1.pop();
    }
}

if (a1==b1) cout <<"Yes";
else cout <<"No";

}