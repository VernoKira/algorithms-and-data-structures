#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
struct Node{
    int val;
    Node* right;
    Node* left;

    Node(int val){
        this->val=val;
        this->left = this->right = NULL;
    }
};

class BST{
private:
    Node* root;

    map<int, int> mp;

    Node* push(Node* cur, int val){
        if(cur==NULL){
            return new Node(val);
        } 
        if(val<cur->val) cur->left = push(cur->left, val);
        if(val>cur->val) cur->right = push(cur->right, val);
        return cur;
    }
    
    void level(Node* cur, int x){
        if(cur==NULL)
            return;
        mp[x]+=cur->val;
        level(cur->right, x+1);
        level(cur->left, x+1);
    }

    void print(Node* cur){
        vector<int> v;
        map<int, int>:: iterator it;
        for(it = mp.begin(); it!=mp.end(); it++){
            v.push_back(it->second);
        }

        cout << v.size() << endl;
        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
        }
    }
    

public:
    BST(){
        root = NULL;
    }

    void push(int val){
        root = push(root, val);
    }

    void level(){
        level(root, 0);
    }
    
    void print(){
        print(root);
    }
};

int main(){
    BST tree;
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        tree.push(a[i]);
    }
    tree.level();
    tree.print();
}