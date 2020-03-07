/**

根据先序遍历和中序遍历构建二叉树
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


// dfs解决背包问题

#include<cstdio>
const int maxn = 30;
// 物品件数n,背包容量V,最大价值maxValue 
int n, V, maxValue = 0;   
// w[i]为每件物品的重量,c[i]为每件物品的价值 
int w[maxn], c[maxn];

// DFS,index为当前处理的物品编号
// sumW和sumC分别为当前总重量和当前总价值 
void DFS0(int index, int sumW, int sumC){
	// 已经完成对n件物品的选择（死胡同） 
	if(index == n){
		if(sumW <= V && sumC > maxValue)
			maxValue = sumC;		// 不超过背包容量时更新最大价值maxValue 
		return ;
	}
	// 岔道口
	// 不选第index件物品 
	DFS(index+1, sumW, sumC);
	// 选第index件物品 
	DFS(index+1, sumW + w[index], sumC + c[index]);
	
} 

// DFS改进
void DFS1(int index, int sumW, int sumC){
	// 已经完成对n件物品的选择（死胡同） 
	if(index == n){
		return ;
	}
	// 岔道口
	// 不选第index件物品 
	DFS(index+1, sumW, sumC);
	// 只有加入第index件物品后未超过容量v,才能继续 
	if(sumW + w[index] <= V){
		if(sumC + c[index] > ans)
			ans = sumC + c[index];	// 更新更大价值maxValue 
		// 选第index件物品 
		DFS(index+1, sumW + w[index], sumC + c[index]);
	}
	
}  


/*
枚举从N个整数中选择K个数的方案 

*/ 

// 序列A中n个数选k个数使得和为x，最大平方和为maxSumSqu 
int n, k, x, maxSumSqu = -1, A[maxn];
// temp存放临时方案，ans存放平方和最大的方案 
vector<int> temp, ans;
// 当前处理index号整数，当前已选整数个数为nowK
// 当前已选整数之和为sum,当前已选整数平方和为sumSqu
void DFS2(int index, int nowK, int sum, int sumSqu){
	// 找到k个数的和为x 
	if(nowK == k && sum == x){
		// 如果比当前找到的更优 
		if(sumSqu > maxSumSqu){
			// 更新最大平方和 
			maxSumSqu = sumSqu;
			ans = temp;
		}
		return;
	}
	// 已经处理完n个数，或者已经超过k个数，或者和超过x，返回 
	if(index == n || nowK > k || sum > x) return;
	// 选index号数 
	temp.push_back(A[index]);
	DFS(index+1, nowK + 1, sum + A[index], sumSqu + A[index] * A[index]);
	temp.pop_back();
	// 不选index号数 
	DFS(index+1, nowK, sum, sumSqu);
} 



#include<cstdio>
#include<queue>
using namespace std;
const int maxn = 100;
struct node{
	int x,y;// 位置(x,y) 
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


const int MAXV = 1000;//最大顶点数
const int INF = 10000000; // 设INF为一个很大的数 
//	邻接矩阵版DFS 
int n, G[MAXV][MAXV];	// n为顶点数，MAXV为最大顶点数 
bool vis[MAXV] = {false};	// 如果顶点i已被访问，则vis[i]==true,初值为false 

// u为当前访问的顶点标号,depth为深度 
void DFS(int u, int depth){
	vis[u] = true;	// 设置u已被访问
	// 如果需要对u进行操作，可以在这里进行
	// 下面对所有从u出发能到达的分支顶点进行枚举
	// 对每个顶点v 
	for(int v = 0; v < n; v++){
		// 如果v未被访问,且u可到达v 
		if(vis[v] == false && G[u][v] != INF){
			// 访问v，深度加1 
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

// 邻接表版
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



// Dijkstra算法
const int MAXV = 1000;
const int INF = 0x3fffffff; 

//邻接矩阵版
int n, G[MAXV][MAXV]; 	// n为顶点数，MAXV为最大顶点数 
int d[MAXV];		// 起点到达各点的最短路径长度 
bool vis[MAXV] = {false};	// 标记数组,vis[i] == true表示已访问。初值均为false 

void Dijkstra(int s){	// s为起点 
	fill(d,d+MAXV, INF);	// fill函数将整个d数组赋值为INF(慎用memset) 
	d[s] = 0;		// 起点到达自身的距离为0 
	for(int i = 0; i < n; i++){	// 循环n次 
		int u = -1; MIN = INF;	// u使d[u]最小，MIN存放该最小的d[u] 
		for(int j = 0; j < n; j++){
			// 找到未访问的顶点中d[]最小的 
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		// 找不到小于INF的d[u]，说明剩下的顶点和起点s不连通 
		if(u == -1) return ;
		// 标记u已访问 
		vis[u] = true;
		for(int v = 0; v<n; v++){
			// 如果v未访问&&u能到达v&&以u为中介点可以使d[v]更优 
			if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]){
				d[v] = d[u] + G[u][v];	//优化d[v] 
			}
		}
	}
} 


// 邻接表版
struct Node{
	int v, dis;	// v为边的目标顶点，dis为边权 
}; 

vector<Node> Adj[MAXV];	// 图G,Adj[u]存放从顶点u出发可以到达的所有顶点 
int n;		// n为顶点数,图G使用邻接表实现,MAXV为最大顶点数 
int d[MAXV];	// 起点到达各点的最短路径长度 
bool vis[MAXV] = {false};	// 标记数组,vis[i]==true表示已访问，初值均为false

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


// Bellman-Ford算法
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
	
	// 以下为判断负环的代码
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


// Floyd算法求全源最短路径
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

