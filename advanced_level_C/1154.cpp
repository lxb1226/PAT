#include<cstdio>
#include<vector>
#include<set>

using namespace std;

int main(){
    int n, m, k;
    scanf("%d %d",&n, &m);
    vector<int> G[10010];
    int a, b;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        bool flag = true;
        vector<int> color(n);
        set<int> s;
        for(int j = 0; j < n; j++){
            scanf("%d", &color[j]);
            s.insert(color[j]);
        }

        for(int j = 0; j < n; j++){
            for(int z = 0; z < G[j].size(); z++){
                if(color[j] == color[G[j][z]]){
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            printf("%d-coloring\n", s.size());
        }else{
            printf("No\n");
        }
    }
    return 0;

}
