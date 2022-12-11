#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
 
    map <int, int> m;
    int m_cnt = 1;
    while(n--) {
        int c;
        cin >> c;
        m[c]++;
 
        m_cnt = max(m_cnt, m[c]);
    }
    map <int, int>::reverse_iterator it = m.rbegin();
    for(it; it != m.rend(); it++) {
        if(it->second == m_cnt) {
            cout << it->first<< " ";
        }
    }
}

    
