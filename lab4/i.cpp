#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    int cnt;
    Node* left;
    Node* right;

    Node(int val){
        this->val=val;
        this->cnt=1;
        this->left = this->right=NULL;
    }
};

class BST{
private:
    Node* root;

    Node* push(Node* cur, int val){
        if(cur==NULL){
            return new Node(val);
        }
        if(cur->val==val) cur->cnt++;
        if(cur->val>val) cur->left = push(cur->left, val);
        if(cur->val<val) cur->right = push(cur->right, val);
        return cur;
    }

    void print(Node* cur, int val){
        if(cur==NULL){
            cout << 0 << endl;
            return;
        } else if(cur->val==val){
            cout << cur->cnt << endl;
            return;
        }
        if(cur->val>val) 
            print(cur->left, val);
        if(cur->val<val) 
            print(cur->right, val);
    }

    void Delete(Node* cur, int val){
        if(cur!=NULL){
            if(cur->val==val){
                if(cur->cnt>0){
                    (cur->cnt)--;
                    return;
                } else {
                    cur->cnt=0;
                }
            } 
            if(val<cur->val) 
                Delete(cur->left, val);
            if(val>cur->val) 
                Delete(cur->right, val);
        }
        return;
    }

public:
    BST(){
        root = NULL;
    }

    void push(int n){
        root = push(root, n);
    }

    void print(int x){
        print(root, x);
    }

    void Delete(int x){
        Delete(root, x);
    }
};

int main(){
    BST b;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string s; 
        int x;
        cin >> s >> x;
        if(s=="insert"){
            b.push(x);
        }
        else if(s=="cnt"){
            b.print(x);

        } else if(s=="delete"){
            b.Delete(x);
        }
    }
}