/*
Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed 
to output the level order traversal sequence of the corresponding binary tree.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (°‹30), the total number of nodes in the binary
tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by 
a space.

Output Specification:
For each test case, print in one line the level order traversal sequence of the corresponding binary tree. 
All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
7

2 3 1 5 7 6 4		∫Û 
1 2 3 4 5 6 7		œ» 

      
    
Sample Output:
4 1 6 3 5 7 2
*/

#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 50;

struct node{
	int data;
	node *lchild, *rchild;
};

int pre[maxn], in[maxn], post[maxn];
int n;

node* create(int postL, int postR, int inL, int inR){
	if(postL > postR)
		return NULL;
	node* root = new node;
	root->data = post[postR];
	int k;
	for(k = inL; k <= inR; k++){
		if(in[k] == post[postR]){
			break;
		}
	}
	int numLeft = k - inL;
	root->lchild = create(postL,postL + numLeft -1,inL,k-1);
	root->rchild = create(postL+numLeft,postR - 1,k+1, inR);
	return root;
	
}

int num = 0;
void BFS(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* now = q.front();
		q.pop();
		printf("%d", now->data);
		num++;
		if(num < n) printf(" ");
		if(now->lchild != NULL) q.push(now->lchild);
		if(now->rchild != NULL) q.push(now->rchild);
	}
}

int main(void){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", post+i);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", in+i);
	}
	node* root = create(0, n-1, 0, n-1);
	BFS(root);
	return 0;
	
	
	
}

