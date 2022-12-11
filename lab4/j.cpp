#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int key;
    Node* left;
    Node* right;
    Node(){
        left = NULL;
        right = NULL;
    }
    Node(int key) {
        this->key = key;
    }
};

void insert(Node* &root, int key){
    if(root == NULL){ 
    root = new Node(key);
    return;
    }
    if (key < root->key)
    {
       insert(root->left, key);
    }
    else
    {
        insert(root->right, key);
    }
    
    
}

Node* answer(int a[], int start, int end){
    if(start > end) return NULL;

    int mid = (start + end) / 2;
    Node* root = new Node(a[mid]);
    root->left = answer(a, start, mid - 1);
    root->right = answer(a, mid + 1, end);

    return root;
}

void preorder(Node* root){
    if(root == NULL) return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);

}

int main(){
    int n;
    cin >> n;
    int size = pow(2,n) - 1;
    int a[100001];
    for(int i = 0; i < size; i++){
        cin >> a[i];
    }
    sort(a, a+size);
    Node* root = answer(a, 0, size-1);

    preorder(root);
}