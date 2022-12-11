#include <bits/stdc++.h>
using namespace std;

struct Node{
    string d;
    Node*next;
    Node(){};
    Node(string d){
        this->d = d;
        next = nullptr;
    }

};

struct LL{

    Node*head;
    Node*tail;

    LL(){
        head = nullptr;
        tail = nullptr;
    }

    void add_front(string s){
        Node*n =new Node(s);
        n->next = head;
        head = n;
        cout <<"ok\n";
    }

    void add_back(string s){
        Node*n = new Node(s);

        if(head==nullptr){
            head = n;
        }
        else{
            Node*cur = head;
            while(cur!=nullptr){
                if(cur->next==nullptr){
                    cur->next=n;
                    break;
                }

                cur = cur->next;
            }
            
        }
        cout << "ok\n";

    }

    void erase_front(){
        if(head==nullptr){
            cout <<"error\n";
             
            return;
            
        }
       
            cout << head->d<<"\n";
            head = head->next;
        

    }
    void erase_back(){
        if(head==nullptr){
            cout <<"error\n";
        }
        if(head->next==nullptr){
            cout << head->d<<endl;

            head=nullptr;
            return;
        }
        Node*cur = head;
        while(cur){
            if (cur->next==nullptr){
                cout << cur->d<<endl;
                cur =nullptr;
                break;
            }
            cur = cur->next;
            }
        }
    void front(){
        if(head==nullptr){
            cout <<"error\n";
            return;
        }
        else{
            cout <<head->d << endl;

        }
    }
    void back(){
        if(head==nullptr){
            cout << "error\n";
            return;
        }
            Node*cur = head;
            while(cur){
                if(cur->next==nullptr){
                    cout << cur->d << endl;
                    break;
                }
                cur = cur->next;

            }

    }
    void clear(){
        head =nullptr;
        cout <<"ok\n";
    }
    void print(){
        Node*cur = head;
        while (cur){
            cout<< cur->d<<" ";
            cur = cur->next;

        }
        
        
    }

};


int main(){
    string s;
    LL l;
    while(true){
        cin >>s;
        if(s == "add_front"){
            string book;
            cin >> book;
            l.add_front(book);
        }
        if(s=="add_back"){
            string book; cin >>book;
            l.add_back(book);

        }
        if(s=="erase_front"){
            l.erase_front();
        }
        if(s=="erase_back"){
            l.erase_back();
        }
        if(s=="front"){
            l.front();
        }
        if(s=="back"){
            l.back();
        }
        if(s=="clear"){
            l.clear();
        }
        if(s=="print"){
            l.print();
        }
        if(s=="exit"){
            cout <<"goodbye";
            return 0;
        }

    }

}