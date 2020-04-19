#include<cstdio>
#include<vector>
using namespace std;

struct node{
    int data;
    node *lchild, *rchild;
};



node* build(node* root, int data){
    if(root == NULL){
        root = new node();
        root->data = data;
        root->lchild  = root->rchild = NULL;
    }else if(data > root->data)
        root->rchild = build(root->rchild, data);
    else
        root->lchild = build(root->lchild, data);
    return root;
}

vector<int> num(1000);
int maxDepth = -1;

void dfs(node* root, int depth){
   if(root == NULL){
        maxDepth = max(depth, maxDepth);
        return;
   }
   num[depth]++;
   dfs(root->lchild, depth+1);
   dfs(root->rchild, depth+1);
}

int main(){
    int n, temp;
    scanf("%d", &n);
    node* root = NULL;
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        root = build(root, temp);
    }
    dfs(root, 0);
    printf("%d + %d = %d", num[maxDepth-1], num[maxDepth-2],num[maxDepth-1] + num[maxDepth-2]);
    return 0;
}
