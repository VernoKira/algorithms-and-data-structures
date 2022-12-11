#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        this->left=this->right= NULL;
    }
};

class BST{
private:
    Node* root;
    int cnt=0;
    Node* push(Node*cur, int val){
        if (cur==NULL) return new Node(val);
        if(val < cur->val){
            cur->left = push(cur->left, val);
        }
        else cur->right = push(cur->right, val);

        return cur;
    }

    int check(Node*cur){
        if(cur==NULL) return 0;
        else{
            check(cur->left);
            if(cur->left!=NULL && cur->right!=NULL){
                cnt++;
            }
            check(cur->right);
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

void checkT(){
    cout <<check(root) <<endl;
}



};

int main(){
    int n ;cin >>n;
    BST b;
     for(int i=0; i<n; i++){
        int x; cin >>x;
        b.push(x);
     }
     b.checkT();
}