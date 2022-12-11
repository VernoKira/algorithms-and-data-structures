#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node*left;
    Node*right;
    Node(int val){
        this->val = val;
        this->left = this->right =NULL;
    }

};

class BST{
private:
Node* root;
Node* target;

int cnt = 0;

Node* push(Node* cur , int val){
    if(cur==NULL) 
        return new Node(val);
    else if(val < cur->val){
        cur->left = push(cur->left, val);
    }
    else cur->right = push(cur->right, val);

    return cur; 
}

Node* search(Node* cur , int t){
    if(cur!=NULL){
        search(cur->left, t);
        search(cur->right, t);
        if(cur->val==t){
            target  =  cur;
        }
        
    }return target;

}

int cntS(Node*target){
    if(target!=NULL){
        cnt++;
        cntS(target->left);
        cntS(target->right);
    }
    return cnt;
}

public:
    BST(){
        root = NULL;
    }
    void push(int x){
        root = push(root, x);
    }

    void search(int t){
        target = search(root, t);
    }

    void cntS(){
        cout << cntS(target);
    }



};

int main(){
    int n ; cin >>n;
    BST b;
    for(int i=0; i<n;i++){
        int x; cin >>x;
        b.push(x);

    }
    int t; cin >>t;

    b.search(t);
    b.cntS();

}