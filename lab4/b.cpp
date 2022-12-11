#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
     Node* left;
     Node* right;
     Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
     }

};

struct BST{
    Node* root;
    int cnt = 0;
    BST(){
        this->root = NULL;
    }
    Node* add(Node* cur, int x){
        if(cur==NULL){
            return new Node(x);
        }
        else if(cur->val > x){
            if(cur->left==NULL){
                cur->left = add(cur->left,x);
            }
            else add(cur->left,x);
        }
        else {
            if(cur->right==NULL){
                cur->right= add(cur->right,x);
            }
            else add(cur->right,x);
        }
        return cur;

    }


    int cntNum(Node*cur){
        if(cur==NULL) return 0;
        
        if(cur != NULL){
            cnt++;
            cntNum(cur->left);
            cntNum(cur->right);
        }
    
        return cnt;    
    }

    Node * searchNode(Node*cur, int num){
        if(cur == NULL){
            return NULL;
        }
        if(cur->val == num){
            return cur;
        }else if(cur->val > num){
            return searchNode(cur->left, num);
        }else{
            return searchNode(cur->right, num);
        }


    }

};

int main(){
    int n; cin >>n;
    BST B;
    for(int i=0; i<n ;i++){
        int x; cin>>x;
        if(B.root==NULL) {
            B.root =B.add(B.root, x);
        }
        else B.add(B.root, x);
    }
    int num ; cin>>num;
    Node *cur = B.searchNode(B.root, num);
    cout << B.cntNum(cur);
 

}