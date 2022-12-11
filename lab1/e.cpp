#include <bits/stdc++.h>
using namespace std;
int main(){
deque <int> boris , nurs;
int cnt=0;
for(int i=0;i<5;i++){
    int a;
    cin >> a;
    boris.push_back(a);
}
for(int j=0;j<5;j++){
    int b; cin >> b; 
    nurs.push_back(b);
}

while(!boris.empty() && !nurs.empty() && cnt!=1000000){
        
    if(boris.front()==0 && nurs.front()==9){
        boris.push_back(boris.front());
        boris.push_back(nurs.front());
           cnt++;

    }
    else if(nurs.front()==0 && boris.front()==9){
        nurs.push_back(boris.front());
        nurs.push_back(nurs.front());
        cnt++;

    }
    else if(boris.front() > nurs.front()){
    
        boris.push_back(boris.front());
        boris.push_back(nurs.front());
        cnt++;

    }
    else if(nurs.front()>boris.front()){
        nurs.push_back(boris.front());
        nurs.push_back(nurs.front());
        cnt++;
    }
    boris.pop_front();
    nurs.pop_front();
    }
if(boris.empty()) cout <<"Nursik" << " "<<cnt;
else if(nurs.empty()) cout <<"Boris"<< " " << cnt;
else cout <<"blin nichya";


}
