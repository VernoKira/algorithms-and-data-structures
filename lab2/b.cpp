#include <bits/stdc++.h>
using namespace std;

struct Node{
    string d;
    Node*next;

    Node(){};
    Node(string d){
        this->d=d;
        next = nullptr;
    }
};


struct LL{

    Node*head;
    Node*tail;
    LL(){
    head=nullptr;
    tail = nullptr;

    }

    void push(string d){
        Node*n= new Node(d);
        if (head == nullptr){
            head= n;
            tail =n;
        }
        else {
            tail->next=n;

            tail=n;
        }


    };

    void print(int k){{
        while(k--){
            (*this).push(head->d);
            head = head->next;
        }
        while(head){
            cout << head->d<< " ";
            head = head->next;
        }
    }

    }


};


int main(){
    int n; cin >>n;
    int k; cin >>k;
    LL l;
    string s;
    for(int i=0;i<n;i++){
        cin >> s;
        l.push(s);

    }
    l.print(k);

}