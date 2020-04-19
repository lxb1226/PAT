#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>

using namespace std;
int n, m, mx = -1;
vector<int> vc[120];
int vis[120];

void dfs(int x, int le){
    if(vc[x].size() == 0){
        vis[le]++;
        mx = max(mx, le);
        return ;
    }
    for(int i = 0; i < vc[x].size();i++){
        dfs(vc[x][i], le+1);
    }
}

int main(void){
    int i,j,k,zi,fu;
    scanf("%d%d", &n, &m);
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= m; i++){
        scanf("%d%d", &fu, &k);
        for(j = 1; j <= k; j++){
            scanf("%d", &zi);
            vc[fu].push_back(zi);
        }
    }

    dfs(1,0);
    for(int i = 0; i <= mx; i++){
        if(i == 0) printf("%d", vis[i]);
        else printf(" %d", vis[i]);
    }

    return 0;
}

