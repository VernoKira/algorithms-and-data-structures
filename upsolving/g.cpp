#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x;
    cin >> n;
    deque<int> dq;
    while(n--){
        cin >> x; 
        dq.push_back(x);
        if(x >= 3000){
            int diff = x - 3000;
            while(!dq.empty() && dq.front() < diff){
                dq.pop_front();
            }
        }
        cout << dq.size() << " "<<endl;
    }
}