#include <bits/stdc++.h>
using namespace std;

struct Node{

int val;
Node*next;
Node(){};
Node(int val){
    this->val = val;
    next = nullptr;
}
};
struct LL{    
    Node * head;
    Node * end;
    LL(){
        head = nullptr;
        end =nullptr;
    }


    void push(int val){
        Node* n =new Node(val);
        if(head == nullptr){
            head = n;
            end = n;
        }
        else{
            end->next = n;
            end = n;
        }

}
    void print(){
        int k; cin >>k;
        Node * cur = head;
        int ind = 0, cnt = 0;
        int d = abs(k - head->val);
        while(cur){
            if(d > abs(k-cur->val)){
                d = abs(k - cur->val);
                ind = cnt;
            }
            cnt++;
            cur = cur->next;
        }
        cout << ind;
        
    }
};


int main(){
    int n; cin >>n;
    LL l;
    while(n--){
       int c;  cin >> c;
        l.push(c);
    }
    
    l.print();

}