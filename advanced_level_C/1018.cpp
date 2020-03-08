#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 501;
const int INF = 10000000000;
int G[maxn][maxn] = {0};
bool vis[maxn] = {false};
int bikes[maxn] = {0};
int d[maxn], w[maxn], pre[maxn];
int n;

Dijkstra(int s){
	fill(d, d + maxn, INF);
	d[s] = 0;
	for(int i = 0; i < n; i++) pre[i] = i;
	for(int i = 0; i < n; i++){
		int u = -1, MIN = INF;
		for(int j = 0; j < n; j++){
			if(vis[j] == false && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1) return ;
		vis[u] == true;
		for(int v = 0; v < n; v++){
			if(vis[v] == false && G[u][v] != INF){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + bikes[v];
					pre[v] = u;
				}else if(d[u] + G[u][v] == d[v] && w[u] + bikes[v] > w[v]){
					w[v] = w[u] + bikes[v];
					pre[v] = u;
				}
				
			}
		}
	}
}


int main(){
	
}
