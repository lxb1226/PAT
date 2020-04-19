#include<cstdio>
#include<set>
#include<vector>

using namespace std;

int main(){
    int n, m;
    int num;
    scanf("%d", &n);
    vector<set<int> > v(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &m);
        for(int j = 0; j < m; j++){
            scanf("%d", &num);
            v[i].insert(num);
        }
    }
    int k, a, b;
    double res;
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf("%d %d", &a, &b);
        int nc = 0, nt;
        for(set<int>::iterator it = v[a-1].begin(); it != v[a-1].end(); it++){
            if(v[b-1].find(*it) != v[b-1].end())
                nc++;
        }
        nt = v[a-1].size() + v[b-1].size() - nc;
        res = (double)nc / nt * 100;
        printf("%.1f%%\n", res);
    }
    return 0;
}
