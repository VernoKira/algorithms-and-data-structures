#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val; 
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;   
    }

};
struct  LL
{
    Node* head;
    Node* tail;
    LL(){
        head = NULL;
        tail = NULL;
    }
    void push(int val){
        Node* n =new Node(val);

        if(head==NULL){
            head =n;
            tail = n;
        }
        else{
            // if(n->val==head->val){
            //     return;
            // }
            n->next=head;
            head = n;
        }
    }
    void rev(int val){
        Node* rev = new Node(val);
        
        

    }

    void print(){
        Node* cur = head;
        cur = head;
        while(cur!=NULL){
            cout << cur->val << endl;
            cur = cur->next;
        }
    }

};


int main(){
    int n; cin >>n;
    LL l;
    string s;
    int val;
    while(n--){
        cin>> s;
        if(s=="1"){
            cin >> val;
            l.push(val);
        }
        if(s=="2"){

        }

    }
    l.print();
}