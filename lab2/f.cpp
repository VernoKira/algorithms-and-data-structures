#include <iostream>

using namespace std;

struct Node{
    int val;
    Node * next;

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
        Node * n =new Node(val);
        if(head == nullptr){
            head = n;
            end = n;
        }
        else{
            end->next = n;
            end = n;
        }
    }


    void ins(int pos, int val){
        Node * newNode = new Node(val);
        if(pos == 0) {
            newNode->next = head;
            head = newNode;
            return;
    }
    Node* cur = head;
    int cnt = 0;
    while(cur) {
        if(cnt + 1 == pos) {
            newNode->next = cur->next;
            cur->next = newNode;
        }
        cur = cur->next;
        cnt++;
        }
    }
    
    void print(){
        Node * cur = head;
        while(cur != nullptr){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
    }
};

int main(){
    LL l;
    int n; cin >>n;
    int a[n];
    for(int i=0; i<n;i++){
        cin >> a[i];
        l.push(a[i]);
    }
        int ins;
         cin >> ins;
        int p;
         cin >> p; 
         
        l.ins(p, ins);
    l.print();
}