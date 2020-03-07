/**

������������������������������
*/

node* create(int preL, int preR, int inL, int inR){
	if(preL > preR)
		return NULL;
	node* root = new node;
	root->data = pre[preL];
	int k;
	for(k = inL; K<inR; k++){
		if(in[k] = pre[preL])
			break;
	}
	
	int numLeft = k - inL;
	root->lchild = create(preL+1, preL+numLeft, inL, k - 1);
	root->rchild = create(preL+numLeft+1, preR, k+1, inR);
	return root;
}


// dfs�����������

#include<cstdio>
const int maxn = 30;
// ��Ʒ����n,��������V,����ֵmaxValue 
int n, V, maxValue = 0;   
// w[i]Ϊÿ����Ʒ������,c[i]Ϊÿ����Ʒ�ļ�ֵ 
int w[maxn], c[maxn];

// DFS,indexΪ��ǰ�������Ʒ���
// sumW��sumC�ֱ�Ϊ��ǰ�������͵�ǰ�ܼ�ֵ 
void DFS0(int index, int sumW, int sumC){
	// �Ѿ���ɶ�n����Ʒ��ѡ������ͬ�� 
	if(index == n){
		if(sumW <= V && sumC > maxValue)
			maxValue = sumC;		// ��������������ʱ��������ֵmaxValue 
		return ;
	}
	// �����
	// ��ѡ��index����Ʒ 
	DFS(index+1, sumW, sumC);
	// ѡ��index����Ʒ 
	DFS(index+1, sumW + w[index], sumC + c[index]);
	
} 

// DFS�Ľ�
void DFS1(int index, int sumW, int sumC){
	// �Ѿ���ɶ�n����Ʒ��ѡ������ͬ�� 
	if(index == n){
		return ;
	}
	// �����
	// ��ѡ��index����Ʒ 
	DFS(index+1, sumW, sumC);
	// ֻ�м����index����Ʒ��δ��������v,���ܼ��� 
	if(sumW + w[index] <= V){
		if(sumC + c[index] > ans)
			ans = sumC + c[index];	// ���¸����ֵmaxValue 
		// ѡ��index����Ʒ 
		DFS(index+1, sumW + w[index], sumC + c[index]);
	}
	
}  


/*
ö�ٴ�N��������ѡ��K�����ķ��� 

*/ 

// ����A��n����ѡk����ʹ�ú�Ϊx�����ƽ����ΪmaxSumSqu 
int n, k, x, maxSumSqu = -1, A[maxn];
// temp�����ʱ������ans���ƽ�������ķ��� 
vector<int> temp, ans;
// ��ǰ����index����������ǰ��ѡ��������ΪnowK
// ��ǰ��ѡ����֮��Ϊsum,��ǰ��ѡ����ƽ����ΪsumSqu
void DFS2(int index, int nowK, int sum, int sumSqu){
	// �ҵ�k�����ĺ�Ϊx 
	if(nowK == k && sum == x){
		// ����ȵ�ǰ�ҵ��ĸ��� 
		if(sumSqu > maxSumSqu){
			// �������ƽ���� 
			maxSumSqu = sumSqu;
			ans = temp;
		}
		return;
	}
	// �Ѿ�������n�����������Ѿ�����k���������ߺͳ���x������ 
	if(index == n || nowK > k || sum > x) return;
	// ѡindex���� 
	temp.push_back(A[index]);
	DFS(index+1, nowK + 1, sum + A[index], sumSqu + A[index] * A[index]);
	temp.pop_back();
	// ��ѡindex���� 
	DFS(index+1, nowK, sum, sumSqu);
} 



#include<cstdio>
#include<queue>
using namespace std;
const int maxn = 100;
struct node{
	int x,y;// λ��(x,y) 
}Node; 

int n, m;
int matrix[maxn][maxn];
bool inq[maxn][maxn] = {false};
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};

bool judge(int x, int y){
	if(x >= n || x < 0 || y>=m || y<0) return false;
	if(matrix[x][y] == 0 || inq[x][y] == true) return false;
	return true;
}

void BFS(int x, int y){
	queue<node> Q;
	Node.x = x, Node.y = y;
	Q.push(Node);
	inq[x][y] = true;
	while(!Q.empty()){
		node top = Q.front();
		Q.pop();
		for(int i = 0; i < 4; i++){
			int newX = top.x + X[i];
			int newY = top.y + Y[i];
			if(judge(newX, newY)){
				Node.x = newX, Node.y = newY;
				Q.push(Node);
				inq[newX][newY] = true;
			}
		}
	}
}

int main(void){
	scanf("%d %d", &n, &m);
	for(int x = 0; x < n; x++){
		for(int y = 0; y<m; y++){
			scanf("%d", &matrix[x][y]);
		}
	}
	int ans = 0;
	for(int x = 0; x < n; x++){
		for(int y = 0; y<m; y++){
			if(matrix[x][y] == 1 && inq[x][y] == false){
				ans++;
				BFS(x,y);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}


const int MAXV = 1000;//��󶥵���
const int INF = 10000000; // ��INFΪһ���ܴ���� 
//	�ڽӾ����DFS 
int n, G[MAXV][MAXV];	// nΪ��������MAXVΪ��󶥵��� 
bool vis[MAXV] = {false};	// �������i�ѱ����ʣ���vis[i]==true,��ֵΪfalse 

// uΪ��ǰ���ʵĶ�����,depthΪ��� 
void DFS(int u, int depth){
	vis[u] = true;	// ����u�ѱ�����
	// �����Ҫ��u���в������������������
	// ��������д�u�����ܵ���ķ�֧�������ö��
	// ��ÿ������v 
	for(int v = 0; v < n; v++){
		// ���vδ������,��u�ɵ���v 
		if(vis[v] == false && G[u][v] != INF){
			// ����v����ȼ�1 
			DFS(v,depth+1);
		}
	}
}

void DFSTrave(){
	for(int u = 0; u<n; u++){
		if(vis[u] == false){
			DFS(u, 1);
		}
	}
} 

// �ڽӱ��
vector<int> Adj[MAXV];
int n;
bool vis[MAXV]  = {false};

void DFS(int u, int depth){
	vis[u] = true;
	for(int i = 0; i < Adj[u].size(); i++){
		int v = Adj[u][i];
		if(vis[v] == false)
			DFS(v,depth+1);
	}
} 

void DFSTrave(){
	for(int u = 0; u<n; u++){
		if(vis[u] == false){
			DFS(u, 1);
		}
	}
} 



// Dijkstra�㷨
const int MAXV = 1000;
const int INF = 0x3fffffff; 

//�ڽӾ����
int n, G[MAXV][MAXV]; 	// nΪ��������MAXVΪ��󶥵��� 
int d[MAXV];		// ��㵽���������·������ 
bool vis[MAXV] = {false};	// �������,vis[i] == true��ʾ�ѷ��ʡ���ֵ��Ϊfalse 

void Dijkstra(int s){	// sΪ��� 
	fill(d,d+MAXV, INF);	// fill����������d���鸳ֵΪINF(����memset) 
	d[s] = 0;		// ��㵽������ľ���Ϊ0 
	for(int i = 0; i < n; i++){	// ѭ��n�� 
		int u = -1; MIN = INF;	// uʹd[u]��С��MIN��Ÿ���С��d[u] 
		for(int j = 0; j < n; j++){
			// �ҵ�δ���ʵĶ�����d[]��С�� 
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		// �Ҳ���С��INF��d[u]��˵��ʣ�µĶ�������s����ͨ 
		if(u == -1) return ;
		// ���u�ѷ��� 
		vis[u] = true;
		for(int v = 0; v<n; v++){
			// ���vδ����&&u�ܵ���v&&��uΪ�н�����ʹd[v]���� 
			if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]){
				d[v] = d[u] + G[u][v];	//�Ż�d[v] 
			}
		}
	}
} 


// �ڽӱ��
struct Node{
	int v, dis;	// vΪ�ߵ�Ŀ�궥�㣬disΪ��Ȩ 
}; 

vector<Node> Adj[MAXV];	// ͼG,Adj[u]��ŴӶ���u�������Ե�������ж��� 
int n;		// nΪ������,ͼGʹ���ڽӱ�ʵ��,MAXVΪ��󶥵��� 
int d[MAXV];	// ��㵽���������·������ 
bool vis[MAXV] = {false};	// �������,vis[i]==true��ʾ�ѷ��ʣ���ֵ��Ϊfalse

void Dijkstra(int s){
	fill(d, d+MAXV, INF);
	d[s] = 0;
	for(int i = 0; i < n; i++){
		int u = -1; MIN = INF;
		for(int j = 0; j < n; j++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		
		if(u == -1) return ;
		vis[u] = true;
		for(int j = 0; j < Adj[u].size()); j++){
			int v = Adj[u][j].v;
			if(vis[v] == false && d[u] + Adj[u][j].dis < d[v]){
				d[v] = d[u] + Adj[u][j].dis;
			}
		}
	}
} 


// Bellman-Ford�㷨
struct Node{
	int v, dis;
}; 

vector<Node> Adj[MAXV];
int n;
int d[MAXV];

bool Bellman(int s){
	fill(d, d+MAXV, INF);
	d[s] = 0;
	for(int i = 0; i < n - 1; i++){
		for(int u = 0; u < n; u++){
			for(int j = 0; j < Adj[u].size(); j++){
				int v = Adj[u][j].v;
				int dis = Adj[u][j].dis;
				if(d[u] + dis < d[v]){
					d[v] = d[u] + dis;
					
				}
			}
		}
	}
	
	// ����Ϊ�жϸ����Ĵ���
	for(int u = 0; u < n; u++){
		for(int j = 0; j < Adj[u].size(); j++){
			int v = Adj[u][j].v;
			int dis = Adj[u][j].dis;
			if(d[u] + dis < d[v]){
				return false;
			}
		}
		return true;
	} 
	 
}


// Floyd�㷨��ȫԴ���·��
const int INF = 0x3fffffff;
const int MAXV = 200;
int n, m;
int dis[MAXV][MAXV];

void Floyd(){
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(dis[i][k] != INF && dis[k][j] != INF && dis[i][k] + dis[k][j] < dis[i][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
} 

