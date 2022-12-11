#include <bits/stdc++.h>
using namespace std;
int main(){
    map<string,string> m;
    map<string, string>:: iterator it;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string s1; string s2;
        cin >> s1; cin >> s2;
        if(!m.empty()){
            for(it = m.begin(); it != m.end(); it++){
                if(s1 == it->second){
                    m[it->first] = s2;
                    m.erase(s1);
                    break;
                }
                else{
                    m[s1] = s2;
                }
            }
        }
        else{
            m[s1] = s2;
        }
    }
    
    cout << m.size() << endl;
    for(it = m.begin(); it != m.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
}