#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node*left;
    Node* right;
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }

};

struct BST{
    Node*root;
    BST(){
        this->root = NULL;
    }
    Node* add(Node*cur, int x){
        if(cur ==NULL){
            return  new Node(x);
        }
        else if(cur->val>x){
            if(cur->left ==NULL){
                cur->left = add(cur->left,x);
            }
            else add(cur->left,x);
        }
        else{
            if(cur->right ==NULL){

                cur->right = add(cur->right,x);
            }
            else add(cur->right,x);
        }
        return cur;

    }
    Node* search(Node*cur, int x){
        if(cur==NULL) return NULL;
        if(cur->val==x) return cur;
        else if(cur->val >x) return search(cur->left,x);
        else return search(cur->right,x);
    }

    void print(Node*cur){
        if(cur!=NULL){
            cout << cur->val <<" ";
            print(cur->left);
            print(cur->right);
            
        }    
    }

};

int main(){
    int n; cin >> n;
    BST B;
    for(int i=0; i<n; i++){
        int x; cin >>x;
        if(B.root == NULL){
            B.root = B.add(B.root, x);
        }
        else B.add(B.root,x);
    }
    int num; cin >>num;
    Node*cur = B.search(B.root,num);
    B.print(cur);


}