#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

// 2 图的存储
// 2.1 邻接矩阵
// 2.2 邻接表
// 只存放边的终点编号 
vector<int> Adj[N];

// 存放边的终点编号和边权
struct Node{
	int v, w;
}; 
vector<Node> Adj[N];

// 3 图的遍历
// 3.1 DFS遍历图
// 连通分量：对于无向图，其中的极大连通子图为连通分量 
// 强连通分量 ： 对于有向图，其中的极大强连通子图为强连通分量
const int maxv = 1000;
const int INF = 1000000000;
// 1.邻接矩阵版
int n, G[maxv][maxv];
bool vis[maxv] = {false};

void DFS(int u, int depth){
	vis[u] = true;
	for(int v = 0; v < n; v++){
		if(vis[v] == false && G[u][v] != INF)
			DFS(v,depth+1);
	}
}

void DFSTrave(){
	for(int u = 0; u < n; u++)
		if(vis[u] == false)
			DFS(u,1);
}

// 2.邻接表版
vector<int> Adj[maxv];
int n;
bool vis[maxv] = {false};
void DFS(int u, int depth){
	vis[u] = true;
	for(int i = 0; i < Adj[u].size(); i++){
		int v = Adj[u][i];
		if(vis[v] == false)
			DFS(v,depth+1);
	}
} 

void DFSTrave(){
	for(int u = 0; u < n; u++){
		if(vis[u] == false)
			DFS(u,1);
	}
}

// 3.2 BFS遍历图
// 1.邻接矩阵版
int n, G[maxv][maxv];
bool inq[maxv] = {false};
void BFS(int u){
	queue<int> q;
	q.push(u);
	inq[u] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v = 0; v < n; v++){
			if(inq[v] == false && G[u][v] != INF){
				q.push(v);
				inq[v] = true;
			}
		}
	}
} 

void BFSTrave(){
	for(int u = 0; u < n; u++)
		if(inq[u] == false)
			BFS(q);
}

// 2.邻接表版
vector<int> Adj[maxv];
int n;
bool inq[maxv] = {false};

void BFS(int u){
	queue<int> q;
	q.push(u);
	inq[u] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 0; i < Adj[u].size(); i++){
			int v = Adj[u][i];
			if(inq[v] == false){
				q.push(v);
				inq[v] = true;
			}
		}
	}
} 

void BFSTrave(){
	for(int u = 0; u < n; u++)
		if(inq[u] == false)
			BFS(q);
}


// 在给定BFS初始点的情况下,可能要输出该连通块内所有其他顶点的层号
struct Node{
	int v;
	int layer;
}; 

vector<Node> Adj[N];

void BFS(int s){
	queue<Node> q;
	Node start;
	start.v = s;
	start.layer = 0;
	q.push(start);
	inq[start.v] = true;
	while(!q.empty()){
		Node topNode = q.front();
		q.pop();
		int u = topNode.v;
		for(int i = 0; i < Adj[u].size(); i++){
			Node next = Adj[u][i];
			next.layer = topNode.layer + 1;
			if(inq[next.v] == false){
				q.push(next);
				inq[next.v] = true;
			}
		}
	}
}

// 4.最短路径
// 解决最短路径问题的常用算法有Dijkstra算法、Bellman-Ford算法、SPFA算法和Floyd算法

// 4.1 Dijkstra算法 
// 解决单源最短路问题
// 基本思想是对图G(V,E)设置集合S，存放已被访问的顶点,然后每次从集合V-S中选择与起点s的最短距离最小的一个顶点(记为u)，访问并加入集合S。之后，令顶点u为中介点,优化起点s与所有从u能到达
// 顶点v之间的最短距离.这样的操作执行n次，直到集合S已包含所有顶点

// 伪代码
/*
Dijkstra(G, d[], s){
	初始化：
	for(循环n次){
		u = 使d[u]最小的还未被访问的顶点的标号;
		记u已被访问;
		for(从u出发能到达的所有顶点v){
			if(v未被访问&&以u为中介点使s到顶点v的最短距离d[v]更优){
			优化d[v]; 
		} 
		 
	} 
} 
*/ 

//  Dijkstra代码实现
const int maxv = 1000;
const int INF = 1000000000;

// 1.邻接矩阵版
// 时间复杂度： O(V^2)
int n, G[maxv][maxv];
int d[maxv];
bool vis[maxv] = {false};

void Dijkstra(int s){
	fill(d, d + maxv, INF);
	d[s] = 0;
	for(int i = 0; i < n; i++){
		int u = -1, MIN = INF;
		for(int j = 0; j < n; j++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		
		if(u == -1) return;
		vis[u] == true;
		for(int v = 0; v < n; v++){
			if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v])
				d[v] = d[u] + G[u][v];
		}
	}
} 

// 2.邻接表版
struct Node{
	int v, dis;
}; 
vector<Node> Adj[maxv];
int n;
// pre[v]表示从起点到顶点v的最短路径上v的前一个顶点
int d[maxv], pre[maxv];
bool vis[maxv] = {false};

void Dijkstra(int s){
	fill(d, d + maxv, INF);
	d[s] = 0;
	// 初始状态设每个点的前驱为自身 
	for(int i = 0; i < n; i++) pre[i] = i;
	for(int i = 0; i < n; i++){
		int u = -1, MIN = INF;
		for(int j = 0; j < n; j++)
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		
		if(u == -1) return;
		vis[u] = true;
		for(int j = 0; j < Adj[u].size(); j++){
			int v = Adj[u][j].v;
			if(vis[v] == false && d[u] + Adj[u][v].dis < d[v]){
				d[v] = d[u] + Adj[u][j].dis;
				pre[v] = u;
			}
		}
	}
	
}
// 输出完整路径
void DFS(int s, int v){
	if(v == s){
		printf("%d\n", s);
		return ;
	}
	DFS(s, pre[v]);
	printf("%d\n", v);
} 

// 在某些场景中，题目中会给出一个第二标尺（第一标尺为距离），要求在所有路径中选择第二标尺最优的一条路径
// 常见的第二标尺
// 1.给每条边再增加一个边权（比如说花费）
for(int v = 0; v < n; v++){
	if(vis[v] == false && G[u][v] != INF){
		if(d[u] + G[u][v] < d[v]){
			d[v] = d[u] + G[u][v];
			c[v] = c[u] + cost[u][v];
		}else if(d[u] + G[u][v] == d[v] && c[u] + cost[u][v] < c[v]){
			c[v] = c[u] + cost[u][v];
		}
	}
}
// 2.给每个点增加一个点权（例如每个城市能收集到的物资）
for(int v = 0; v < n; v++){
	if(vis[v] == false && G[u][v] != INF){
		if(d[u] + G[u][v] < d[v]){
			d[v] = d[u] + G[u][v];
			w[v] = w[u] + weight[v];
		}else if(d[u] + G[u][v] == d[v] && w[u] + weight[v] > w[v]){
			w[v] = w[u] + weight[v];
		}
	}
}
// 3.直接问有多少条最短路径
for(int v = 0; v < n; v++){
	if(vis[v] == false && G[u][v] != INF){
		if(d[u] + G[u][v] < d[v]){
			d[v] = d[u] + G[u][v];
			num[v] = num[u];
		}else if(d[u] + G[u][v] == d[v]){
			num[v] += num[u];
		}
	}
}



// 4.3 Floyd算法 
// 解决全源最短路问题
// 算法流程
/*
枚举顶点k 属于[1,n]
	以顶点k作为中介点，枚举所有顶点对i和j
		如果dis[i][k] + dis[k][j]<dis[i][j]
			赋值 dis[i][j] = dis[i][k] + dis[k][j]

*/ 

// 代码实现
const int INF = 1000000000;
const int maxv = 200;
int n, m;
int dis[maxv][maxv];

void Floyd(){
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(dis[i][k] != INF && dis[k][j] != INF && dis[i][k] + dis[k][j]<dis[i][j])
					dis[i][j] = dis[i][k] + dis[k][j];
} 

// 5最小生成树
// 5.2 prim算法 
// 基本思想
/*
对图G(V,E)设置集合S，存放已访问的顶点,然后每次从集合V-S中选择与集合S的最短距离最小的一个顶点(记为u)，访问并加入集合S。之后，令顶点u为中介点，优化所有能到达的顶点v与集合S之间的最短距离.
这样的操作执行n次(n为顶点个数)，直到集合S已包含所有顶点 


伪代码
Prim(G,d[]){
	初始化;
	for(循环n次){
	u = 使d[u]最小的还未被访问的顶点的标号;
	记u已被访问;
	for(从u出发能到达的所有顶点v){
		if(v未被访问&&以u为中介点使得v与集合S的最短距离d[v]更优){
			将G[u][v]赋值给v与集合S的最短距离d[v];
		}
	}
}

*/ 

// 代码实现 
const int maxv = 1000;
const int INF = 1000000000;

// 1.邻接矩阵版
int n, G[maxv][maxv];
//顶点与集合s的最短距离 
int d[maxv];
bool vis[maxv] = {false};

int prim(){
	fill(d, d+maxv,INF);
	d[0] = 0;			// 只有0号顶点到集合S的距离为0，其余全为INF 
	int ans = 0;		// 存放最小生成树的边权之和 
	for(int i = 0; i < n; i++){
		int u = -1, MIN = INF;
		for(int j = 0; j < n; j++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1) return -1;
		vis[u] = true;
		ans += d[u];	// 将与集合S距离最小的边加入最小生成树 
		for(int v = 0; v < n; v++){
			// v未访问&&u能到达v&&以u为中介点可以使v离集合S更近 
			if(vis[v] == false&& G[u][v] != INF && G[u][v] < d[v])
				d[v] = G[u][v];
		}
	}
	return ans;
}

// 2.邻接表版
struct Node{
	int v, dis;
}; 
vector<Node> Adj[maxv];
int n;
int d[maxv];
bool vis[maxv] = {false};

int prim(){
	fill(d, d+maxv,INF);
	d[0] = 0;			// 只有0号顶点到集合S的距离为0，其余全为INF 
	int ans = 0;		// 存放最小生成树的边权之和 
	for(int i = 0; i < n; i++){
		int u = -1, MIN = INF;
		for(int j = 0; j < n; j++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1) return -1;
		vis[u] = true;
		ans += d[u];	// 将与集合S距离最小的边加入最小生成树 
		for(int j = 0; j < Adj[u].size(); j++){
			int  v = Adj[u][j].v;
			// v未访问&&u能到达v&&以u为中介点可以使v离集合S更近 
			if(vis[v] == false&& Adj[u][j].dis < d[v])
				d[v] = G[u][v];
		}
	}
	return ans;
}

// 5.3 Kruskal算法 
// 伪代码
/*
int Kruskal(){
	令最小生成树的边权之和为ans、最小生成树的当前边树Num_Edge;
	将所有边按边权从小到大排序;
	for(从小到大枚举所有边){
		if(当前测试边的两个端点在不同的连通块){
			将该测试边加入最小生成树;
			ans += 测试边的边权;
			最小生成树的当前边数Num_Edge加1;
			当边数Num_Edge等于顶点数减1时结束循环;
		}
	}
	return ans;
}

*/ 
 
// 代码实现
struct edge{
	int u, v;
	int cost;
}E[maxv];
bool cmp(edge a, edge b){
	return a.cost < b.cost;
}
// 并查集数组 
int father[N];
// 并查集查询函数 
int findFather(int x){
	while(x != father[x])
		x = father[x];
	return x;
}

int Kruskal(int n, int m){
	int ans = 0, Num_edge = 0;
	for(int i = 1; i <= n; i++)
		father[i] = i;
	sort(E, E+m, cmp);
	for(int i = 0; i < m; i++){
		int faU = findFather(E[i].u);
		int faV = findFather(E[i].v);
		if(faU != faV){
			father[faU] = faV;
			ans += E[i].cost;
			Num_edge++;
			if(Num_edge == n - 1)break;
		}
	}
	if(Num_edge != n - 1) return -1;
	els return ans;
}


// 6.拓扑排序
// 代码实现
vector<int> G[maxv];
int n, m, inDegree[maxv];
bool topologicalSort(){
	int num =  0;
	queue<int> q;
	for(int i = 0; i < n; i++)
		if(inDegree[i] == 0)
			q.push(i);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 0; i < G[u].size()); i++){
			int v = G[u][i];
			inDegree[v]--;
			if(inDegree[v] == 0)
				q.push(v);
		}
		G[u].clear();
		num++;
	}
	// 加入拓扑序列的顶点数为n，说明排序成功，否则失败 
	if(num == n) return true;
	else return false;
} 

// 拓扑排序很重要的一个应用就是判断一个给定的图是否是有向无环图
// 如果要求有多个入度为0的顶点，选择编号最小的顶点，那么把queue改成priority_queue，并保持队首元素(堆顶元素)是优先队列中最小的元素即可

// 7.3 关键路径
// 略 

 
 
