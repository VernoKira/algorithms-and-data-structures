#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node*left;
    Node*right;
    Node(int val){
        this->val = val;
        this->left = this->right = NULL;
    }
};

class BST{
private:
Node* root;

Node*push(Node* cur, int val){
    if(cur==NULL) return new Node(val);
    else if(val < cur->val) cur->left = push(cur->left, val);
    else cur->right = push(cur->right, val);

    return cur;

}

bool check(Node* cur, string s){
    for(int i=0; i <s.size(); i++){
        if( s[i]=='L') {
            cur = cur->left;
            if(cur==NULL) return false;
        }else if(s[i]=='R') {
            cur = cur->right;
            if(cur==NULL) return false;
        }
    }
        return true;
    
}



public:
BST(){
    root = NULL;
}
void push(int x){
    root = push(root, x);
}

void check(string s){
    if(check(root, s)) cout <<"YES"<<endl;
    else cout <<"NO"<<endl;
}

};
int main(){
    int n, m; cin >>n >> m;
    BST b;
    for(int i=0; i<n; i++){
        int x; cin >>x;
        b.push(x);

    }

    while(m--){
        string s;
         cin >>s;
            b.check(s);
            
         }
    }

