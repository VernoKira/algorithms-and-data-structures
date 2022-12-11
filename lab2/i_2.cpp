#include <bits/stdc++.h>
  
using namespace std;

struct Node{
	Node * prev;
	Node * next;
	string val;
	Node(string _val){
		prev = NULL;
		next = NULL;
		val = _val;
	}	
};

Node * head = NULL;
Node * tail = NULL;
int cnt;
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
    

}
void add_front(string s){
     Node*n =new Node(s);
        n->next = head;
        head = n;

}
bool empty(){
    if (head==nullptr) return true;
    return false;

}
void erase_front(){
    // cout << head->val;
    head = head->next;

}
void erase_back(){
    if(head->next==NULL){
        // cout << head->val<<endl;
        head=NULL;
        return;
    }
    Node*cur =head;

    while(cur){
        if(cur->next==NULL){
            // cout << cur->val<<endl;
            cur =NULL;
            break;
        }
        cur = cur->prev;
    }




}
string front(){
    return head->val;
}
string back(){
    Node*cur = head;
    while(cur){
        if(cur->next==nullptr){
            return cur->val;
        }
        cur = cur->next;

    }
    return cur->val;

}
void clear(){
    head = nullptr;
}
  
int main()
{
	string s;
   	while(cin >> s){
   		if(s == "add_front"){
   			string t;
   			cin >> t;
   			add_front(t);
   			cout << "ok" << endl;
   		}
   		if(s == "add_back"){
   			string t;
   			cin >> t;
   			add_back(t);
   			cout << "ok" << endl;
   		}
   		if(s == "erase_front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else
   			{
   				cout << front() << endl;
   				erase_front();
   			}
   		}
   		if(s == "erase_back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   				erase_back();
   			}
   		}
   		if(s == "front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << front() << endl;
   			}
   		}
   		if(s == "back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   			}
   		}
   		if(s == "clear"){
   			clear();
   			cout << "ok" << endl;
   		}
   		if(s == "exit"){
   			cout << "goodbye" << endl;
   			break;
   		}
   	}
    return 0;
}