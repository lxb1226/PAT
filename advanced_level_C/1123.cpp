#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

struct node{
    int data;
    node *left, *right;
};

node* rotateLeft(node *root){
    node* t = root->right;
    root->right = t->left;
    t->left = root;
    return t;
}

node* rotateRight(node* root){
    node* t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}

node* rotateLeftRight(node* root){
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}

node* rotateRightLeft(node* root){
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}

int getHeight(node* root){
    if(root == NULL) return 0;
    return max(getHeight(root->left), getHeight(root->right)) +1;
}

node* insert(node* root, int data){
    if(root == NULL){
        root = new node();
        root->data = data;
        root->left = root->right = NULL;
        return root;
    }else if(root->data > data){
        root->left = insert(root->left, data);
        if(getHeight(root->left) - getHeight(root->right) >= 2)
            return data < root->left->data ? rotateRight(root) : rotateLeftRight(root);
    }else{
        root->right = insert(root->right, data);
        if(getHeight(root->right) - getHeight(root->left) >= 2)
            return data > root->right->data ? rotateLeft(root):rotateRightLeft(root);
    }

}

int isComplete = 1, after = 0;
vector<int> levelOrder(node *root){
    vector<int> v;
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        node *temp = q.front();
        q.pop();
        v.push_back(temp->data);
        if(temp->left != NULL){
            if(after) isComplete = 0;
            q.push(temp->left);
        }else{
            after = 1;
        }
        if(temp->right != NULL){
            if(after) isComplete = 0;
            q.push(temp->right);
        }else{
            after = 1;
        }
    }

    return v;
}

int main(){
    int n, temp;
    scanf("%d", &n);
    node *tree = NULL;
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        tree = insert(tree, temp);
    }
    vector<int> v = levelOrder(tree);
    printf("%d\n", v.size());
    for(int i = 0; i < v.size(); i++){
        if(i != 0) printf(" ");
        printf("%d", v[i]);
    }
    printf("\n%s", isComplete ? "YES":"NO");
    return 0;
}
