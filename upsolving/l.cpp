#include <bits/stdc++.h>
using namespace std;
int cnt=0;
struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->right = this->left = NULL;
    }

};
class BST{
private:
    Node* root;
    Node* push(Node* cur, int val){
        if(cur==NULL) {
            return new Node (val);
        }
        if(val < cur->val) cur->left= push(cur->left, val);
        if(val > cur->val) cur->right=push(cur->right, val);
        return cur;
    }

   unsigned int getLeafCount(Node* cur)  { 
    if(cur == NULL)     
        return 0; 
    if(cur->left == NULL && cur->right == NULL) 
        return 1;         
    else
        return getLeafCount(cur->left)+ 
            getLeafCount(cur->right); 
    }

public:
    BST(){
        root = NULL;
    }
    void push(int val){
        root = push(root, val);
    }

    void cntt(){
        cout << getLeafCount(root);

    }
    
};


int main(){
    int n; cin >>n;
    BST b;

    for(int i=0; i<n;i++){
        int x; cin >>x;
        b.push(x);

    }
    b.cntt();
}