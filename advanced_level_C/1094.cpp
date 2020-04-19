#include<cstdio>
#include<vector>
#include<map>
using namespace std;
vector<int> v[101];
map<int,int> mapp;

void dfs(int root, int level){
    mapp[level] += 1;
    for(int i = 0; i < v[root].size(); i++){
        dfs(v[root][i], level+1);
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++){
        int id, len, temp;
        scanf("%d %d", &id, &len);
        for(int j = 0; j < len; j++){
            scanf("%d", &temp);
            v[id].push_back(temp);
        }
    }

    dfs(1, 1);
    int maxn = 0, index = 0;
    for(map<int,int>::iterator it = mapp.begin(); it != mapp.end(); it++){
        if(it->second > maxn){
            maxn = it->second;
            index = it->first;
        }
    }
    printf("%d %d", maxn, index);
    return 0;
}
