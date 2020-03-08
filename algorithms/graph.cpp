#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

// 2 ͼ�Ĵ洢
// 2.1 �ڽӾ���
// 2.2 �ڽӱ�
// ֻ��űߵ��յ��� 
vector<int> Adj[N];

// ��űߵ��յ��źͱ�Ȩ
struct Node{
	int v, w;
}; 
vector<Node> Adj[N];

// 3 ͼ�ı���
// 3.1 DFS����ͼ
// ��ͨ��������������ͼ�����еļ�����ͨ��ͼΪ��ͨ���� 
// ǿ��ͨ���� �� ��������ͼ�����еļ���ǿ��ͨ��ͼΪǿ��ͨ����
const int maxv = 1000;
const int INF = 1000000000;
// 1.�ڽӾ����
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

// 2.�ڽӱ��
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

// 3.2 BFS����ͼ
// 1.�ڽӾ����
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

// 2.�ڽӱ��
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


// �ڸ���BFS��ʼ��������,����Ҫ�������ͨ����������������Ĳ��
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

// 4.���·��
// ������·������ĳ����㷨��Dijkstra�㷨��Bellman-Ford�㷨��SPFA�㷨��Floyd�㷨

// 4.1 Dijkstra�㷨 
// �����Դ���·����
// ����˼���Ƕ�ͼG(V,E)���ü���S������ѱ����ʵĶ���,Ȼ��ÿ�δӼ���V-S��ѡ�������s����̾�����С��һ������(��Ϊu)�����ʲ����뼯��S��֮�����uΪ�н��,�Ż����s�����д�u�ܵ���
// ����v֮�����̾���.�����Ĳ���ִ��n�Σ�ֱ������S�Ѱ������ж���

// α����
/*
Dijkstra(G, d[], s){
	��ʼ����
	for(ѭ��n��){
		u = ʹd[u]��С�Ļ�δ�����ʵĶ���ı��;
		��u�ѱ�����;
		for(��u�����ܵ�������ж���v){
			if(vδ������&&��uΪ�н��ʹs������v����̾���d[v]����){
			�Ż�d[v]; 
		} 
		 
	} 
} 
*/ 

//  Dijkstra����ʵ��
const int maxv = 1000;
const int INF = 1000000000;

// 1.�ڽӾ����
// ʱ�临�Ӷȣ� O(V^2)
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

// 2.�ڽӱ��
struct Node{
	int v, dis;
}; 
vector<Node> Adj[maxv];
int n;
// pre[v]��ʾ����㵽����v�����·����v��ǰһ������
int d[maxv], pre[maxv];
bool vis[maxv] = {false};

void Dijkstra(int s){
	fill(d, d + maxv, INF);
	d[s] = 0;
	// ��ʼ״̬��ÿ�����ǰ��Ϊ���� 
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
// �������·��
void DFS(int s, int v){
	if(v == s){
		printf("%d\n", s);
		return ;
	}
	DFS(s, pre[v]);
	printf("%d\n", v);
} 

// ��ĳЩ�����У���Ŀ�л����һ���ڶ���ߣ���һ���Ϊ���룩��Ҫ��������·����ѡ��ڶ�������ŵ�һ��·��
// �����ĵڶ����
// 1.��ÿ����������һ����Ȩ������˵���ѣ�
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
// 2.��ÿ��������һ����Ȩ������ÿ���������ռ��������ʣ�
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
// 3.ֱ�����ж��������·��
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



// 4.3 Floyd�㷨 
// ���ȫԴ���·����
// �㷨����
/*
ö�ٶ���k ����[1,n]
	�Զ���k��Ϊ�н�㣬ö�����ж����i��j
		���dis[i][k] + dis[k][j]<dis[i][j]
			��ֵ dis[i][j] = dis[i][k] + dis[k][j]

*/ 

// ����ʵ��
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

// 5��С������
// 5.2 prim�㷨 
// ����˼��
/*
��ͼG(V,E)���ü���S������ѷ��ʵĶ���,Ȼ��ÿ�δӼ���V-S��ѡ���뼯��S����̾�����С��һ������(��Ϊu)�����ʲ����뼯��S��֮�����uΪ�н�㣬�Ż������ܵ���Ķ���v�뼯��S֮�����̾���.
�����Ĳ���ִ��n��(nΪ�������)��ֱ������S�Ѱ������ж��� 


α����
Prim(G,d[]){
	��ʼ��;
	for(ѭ��n��){
	u = ʹd[u]��С�Ļ�δ�����ʵĶ���ı��;
	��u�ѱ�����;
	for(��u�����ܵ�������ж���v){
		if(vδ������&&��uΪ�н��ʹ��v�뼯��S����̾���d[v]����){
			��G[u][v]��ֵ��v�뼯��S����̾���d[v];
		}
	}
}

*/ 

// ����ʵ�� 
const int maxv = 1000;
const int INF = 1000000000;

// 1.�ڽӾ����
int n, G[maxv][maxv];
//�����뼯��s����̾��� 
int d[maxv];
bool vis[maxv] = {false};

int prim(){
	fill(d, d+maxv,INF);
	d[0] = 0;			// ֻ��0�Ŷ��㵽����S�ľ���Ϊ0������ȫΪINF 
	int ans = 0;		// �����С�������ı�Ȩ֮�� 
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
		ans += d[u];	// ���뼯��S������С�ı߼�����С������ 
		for(int v = 0; v < n; v++){
			// vδ����&&u�ܵ���v&&��uΪ�н�����ʹv�뼯��S���� 
			if(vis[v] == false&& G[u][v] != INF && G[u][v] < d[v])
				d[v] = G[u][v];
		}
	}
	return ans;
}

// 2.�ڽӱ��
struct Node{
	int v, dis;
}; 
vector<Node> Adj[maxv];
int n;
int d[maxv];
bool vis[maxv] = {false};

int prim(){
	fill(d, d+maxv,INF);
	d[0] = 0;			// ֻ��0�Ŷ��㵽����S�ľ���Ϊ0������ȫΪINF 
	int ans = 0;		// �����С�������ı�Ȩ֮�� 
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
		ans += d[u];	// ���뼯��S������С�ı߼�����С������ 
		for(int j = 0; j < Adj[u].size(); j++){
			int  v = Adj[u][j].v;
			// vδ����&&u�ܵ���v&&��uΪ�н�����ʹv�뼯��S���� 
			if(vis[v] == false&& Adj[u][j].dis < d[v])
				d[v] = G[u][v];
		}
	}
	return ans;
}

// 5.3 Kruskal�㷨 
// α����
/*
int Kruskal(){
	����С�������ı�Ȩ֮��Ϊans����С�������ĵ�ǰ����Num_Edge;
	�����б߰���Ȩ��С��������;
	for(��С����ö�����б�){
		if(��ǰ���Աߵ������˵��ڲ�ͬ����ͨ��){
			���ò��Ա߼�����С������;
			ans += ���Աߵı�Ȩ;
			��С�������ĵ�ǰ����Num_Edge��1;
			������Num_Edge���ڶ�������1ʱ����ѭ��;
		}
	}
	return ans;
}

*/ 
 
// ����ʵ��
struct edge{
	int u, v;
	int cost;
}E[maxv];
bool cmp(edge a, edge b){
	return a.cost < b.cost;
}
// ���鼯���� 
int father[N];
// ���鼯��ѯ���� 
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


// 6.��������
// ����ʵ��
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
	// �����������еĶ�����Ϊn��˵������ɹ�������ʧ�� 
	if(num == n) return true;
	else return false;
} 

// �����������Ҫ��һ��Ӧ�þ����ж�һ��������ͼ�Ƿ��������޻�ͼ
// ���Ҫ���ж�����Ϊ0�Ķ��㣬ѡ������С�Ķ��㣬��ô��queue�ĳ�priority_queue�������ֶ���Ԫ��(�Ѷ�Ԫ��)�����ȶ�������С��Ԫ�ؼ���

// 7.3 �ؼ�·��
// �� 

 
 
