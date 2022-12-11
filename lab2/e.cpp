#include <bits/stdc++.h>
using namespace std;


struct Node{
    string d;
    Node *next;
    Node(){};
    Node(string d){
        this->d = d;
        next = nullptr;
    }

};

struct LL{
    Node *head;
    int cnt = 0;
    LL(){
        head = nullptr;
    }

    void push(string d){
        Node* n = new Node(d);

        if(head == nullptr){
            head = n;
            cnt++;
        }

        else{
            if(n->d == head->d){
                return;
            }
            n->next = head;
            head = n;
            cnt++;
        }

    }
    void print(){

        Node *cur = head;
        cout <<"All in all: " << cnt << endl;
        cout << "Students:" << endl;
        cur = head;

        while(cur!=nullptr){
            cout << cur->d << endl;
            cur = cur->next;
                
        }
    }
};

int main(){
    int n; cin >> n;
    LL l;
    string s;
    for(int i=0; i<n; i++){
        cin >> s;
        l.push(s);
    }
    l.print();

}