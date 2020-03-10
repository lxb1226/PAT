#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 510;
const int INF = 1000000000;
int G[maxn][maxn] = {INF}, cost[maxn][maxn];
int d[maxn], c[maxn], pre[maxn];
bool vis[maxn] = {false};
int n, m, start, ed;

void Dijkstra(int s){
	fill(d, d + maxn, INF);
	fill(c, c + maxn, INF);
	for(int i = 0; i < n; i++) pre[i] = i;
	c[s] = 0;
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
		vis[u] = true;
		for(int v = 0; v < n; v++){
			if(vis[v] == false && G[u][v] != INF){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				}else if(d[u] + G[u][v] == d[v] && c[u] + cost[u][v] < c[v]){
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				}
			}
		}
	}
}

void DFS(int v){
	if(v == start){
		printf("%d ", v);
		return ;
	}
	DFS(pre[v]);
	printf("%d ", v);
}

int main(){
	scanf("%d %d %d %d", &n, &m, &start, &ed);
	int a, b;
	fill(G[0], G[0] + maxn*maxn , INF);
	for(int i = 0; i < m; i++){
		scanf("%d%d", &a, &b);
		scanf("%d%d",&G[a][b], &cost[a][b]);
		G[b][a] = G[a][b];
		cost[b][a] = cost[a][b];
	}
	Dijkstra(start);
	DFS(ed);
	printf("%d %d\n",d[ed], c[ed]);
	return 0;
}
