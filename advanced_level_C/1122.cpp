#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main(){
    int n, m;
    int e[210][210];
    scanf("%d %d", &n, &m);
    int a, b;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        e[a][b] = e[b][a] = 1;
    }
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        int len;
        cin >> len;
        vector<int> v(len);
        set<int> s;
        int flag1 = 1, flag2 = 1;
        for(int i = 0; i < len; i++){
            scanf("%d", &v[i]);
            s.insert(v[i]);
        }
        if(s.size() != n || len - 1 != n || v[0] != v[len-1]) flag1 = 0;
        for(int i = 0; i < len - 1; i++)
            if(e[v[i]][v[i+1]] == 0) flag2 = 0;
        printf("%s", flag1&&flag2 ? "YES\n":"NO\n");
    }

    return 0;
}
