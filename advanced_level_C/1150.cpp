#include<cstdio>
#include<map>
#include<algorithm>
#include<vector>

const int INF = 10000000;
const int maxn = 220;
using namespace std;

int main(){
    int n, m, u, v, dist;
    int G[maxn][maxn];
    vector<int> total;
    scanf("%d %d", &n, &m);
    fill(G[0], G[0] + maxn*maxn,INF);
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &u, &v, &dist);
        G[u][v] = G[v][u] = dist;
    }
    scanf("%d", &m);
    int k, a, b;
    for(int i = 0; i < m; i++){
        map<int,int> Map;
        bool flag = true;
        int sum = 0, first;
        scanf("%d %d", &k, &a);
        first = a;
        Map[a] += 1;

        for(int j = 1; j < k; j++){
            scanf("%d", &b);
            Map[b] += 1;
            if(G[a][b] == INF)
                flag = false;
            else
                sum += G[a][b];
        }
        total.push_back(sum);
        if(flag == false)
            printf("Path %d: NA (Not a TS cycle)", i);
        else if(first != b || Map.size() < n)
            printf("Path %d: %d (Not a TS cycle)", i, sum);
        else if()
    }


}



