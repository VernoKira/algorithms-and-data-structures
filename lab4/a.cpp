#include <bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node*left;
    Node*right;
    Node(int data){
        this->data=data;
        this->left= NULL;
        this->right=NULL;
    };

};

struct BST{
    Node*root;
    BST(){
       this->root=NULL;
    }

Node*add(Node*cur, int val){
    if(cur==NULL){
        cur = new Node(val);
    }
    else if(cur->data>val){
        if(cur->data==NULL){
            cur->left=add(cur->left,val);
        }
        else cur->left = add(cur->left,val);
    }

    else{
        if(cur->right==NULL){
            cur->right = add(cur->right,val);
        }
        else
             cur->right=add(cur->right,val);
    }
     return cur;

}


};

int main(){
    int n, m; cin >>n >>m;
    BST B;
    for(int i=0; i<n;i++){
        int val; cin >> val;
        if(B.root==NULL){
            B.root = B.add(B.root,val);
         }
         else B.add(B.root,val);
    }

    while (m--){
        string s; cin>>s;
        Node*cur =B.root;
        for(int i=0; i<s.length(); i++){
            if(cur == NULL) break;
            if(s[i]=='L')
                cur = cur->left;
            
            if (s[i] == 'R') cur = cur->right;

        }
        
        if(cur!=NULL) cout <<"YES\n";
        else cout <<"NO\n";
    }
  
}