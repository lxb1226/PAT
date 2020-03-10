#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 510;
const int INF = 1000000000;
int n, m, st, ed, G[maxn][maxn], cost[maxn][maxn];
int d[maxn], minCost = INF;
bool vis[maxn] = {false};
vector<int> pre[maxn];
vector<int> tempPath, path;

void Dijkstra(int s){
	fill(d, d + maxn, INF);
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
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u] + G[u][v] == d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}

void DFS(int v){
	if(v == st){
		tempPath.push_back(v);
		int tempCost = 0;
		for(int i = tempPath.size() - 1; i > 0; i--){
			int id = tempPath[i], idNext = tempPath[i - 1];
			tempCost += cost[id][idNext];
		}
		if(tempCost < minCost){
			minCost = tempCost;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for(int i = 0; i < pre[v].size(); i++)
		DFS(pre[v][i]);
	tempPath.pop_back();
}


int main(){
	scanf("%d %d %d %d", &n, &m, &st, &ed);
	int a, b;
	fill(G[0], G[0] + maxn*maxn , INF);
	for(int i = 0; i < m; i++){
		scanf("%d%d", &a, &b);
		scanf("%d%d",&G[a][b], &cost[a][b]);
		G[b][a] = G[a][b];
		cost[b][a] = cost[a][b];
	}
	Dijkstra(st);
	DFS(ed);
	for(int i = path.size() - 1; i >= 0; i--)
		printf("%d ", path[i]);
	printf("%d %d\n",d[ed], minCost);
	return 0;
}
