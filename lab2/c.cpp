
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node*next;
    Node(){}
    Node(int val){
        this->val=val;
        next = nullptr;
    }

};


struct LL{
    Node* head;
    Node* end;
    LL(){
        head = nullptr;
        end = nullptr;
    }

    void push(Node* &head,int t){

        Node * n = new Node(t);
        if(head == nullptr){
            head=n;
            return;
        }
         Node* cur = head;
         while(cur){
        if(cur->next==nullptr){
            cur->next = n;
            break;
        }
        cur = cur->next;
    }

        }



    };
   void print(Node*cur){
        while(cur){
        cout << cur->val<<" ";
        cur = cur->next;
    }

    }

int main(){
    int n; cin >> n;
    Node*head =nullptr;
    LL l;
    for(int i=0; i<n;i++){
        int t; cin >> t;
        if(i%2!=1) l.push(head,t);
       
    }
    print(head); 
}