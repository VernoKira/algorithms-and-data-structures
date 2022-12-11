#include <bits/stdc++.h>
using namespace std;
int main(){
    map<string,string> m;
    map<string, string>:: iterator it;
    int n; cin >> n;
    while(n--){
        string a,b;
        cin >> a >> b;
        if(!m.empty()){
            for(it = m.begin(); it != m.end(); it++){
                if(a == it->second){
                    m[it->first] = b;
                    m.erase(a);
                    break;
                }
                else{
                    m[a] = b;
                }
            }
        }
        else{
            m[a] = b;
        }
    }

    cout << m.size() << endl;
    for(it = m.begin(); it != m.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
}