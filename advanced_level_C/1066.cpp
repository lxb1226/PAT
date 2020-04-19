#include<iostream>
#include<cstdio>
using namespace std;
struct node{
    int val;
    struct node *left, *right;
};

// 左旋
node *rotateLeft(node *root){
    node *t = root->right;
    root->right = t->left;
    t->left = root;
    return t;
}

// 右旋
node *rotateRight(node *root){
    node *t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}

// 先左旋后右旋
node *rotateLeftRight(node *root){
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}

// 先右旋后左旋
node *rotateRightLeft(node *root){
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}

int getHeight(node *root){
    if(root == NULL) return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}


node *insert(node *root, int val){
    if(root == NULL){
        root = new node();
        root->val = val;
        root->left = root->right = NULL;
    }else if(val < root->val){
        root->left = insert(root->left, val);
        // 如果左子树的高度-右子树的高度 == 2
        if(getHeight(root->left) - getHeight(root->right) == 2)
            // 如果要插入的值在左子树，那么进行右旋，否则先左旋再右旋
            root = val < root->left->val ? rotateRight(root):rotateLeftRight(root);
    }else{
        root->right = insert(root->right, val);
        // 如果左子树的高度-右子树的高度 == -2
        if(getHeight(root->left) - getHeight(root->right) == -2)
            // 如果要插入的值在右子树，那么进行左旋，否则先右旋再左旋
            root = val > root->right->val ? rotateLeft(root):rotateRightLeft(root);
    }

    return root;
}

int main(){
    int n, val;
    scanf("%d", &n);
    node *root = NULL;
    for(int i = 0; i < n; i++){
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("%d", root->val);
    return 0;
}
