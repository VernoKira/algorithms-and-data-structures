#include <bits/stdc++.h>
using namespace std;
int main(){
string s; 
cin >> s;
stack <char> s1;
for (int i=0; i<s.size(); i++){
        if(!s1.empty()&& s[i]==s1.top()) {
            s1.pop();
        }
        else{ 
            s1.push(s[i]);
        }

    } 

 if (!s1.empty()) cout <<"NO";
 else cout << "YES";
   
}