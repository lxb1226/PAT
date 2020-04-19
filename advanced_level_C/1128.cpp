#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int k, n;
    scanf("%d", &k);
    while(k--){
        scanf("%d", &n);
        vector<int> v(n);
        bool flag = true;
        for(int j = 0; j < n; j++){
            scanf("%d", &v[j]);
            for(int t = 0; t < j; t++){
                if(v[j] == v[t] || abs(v[j] - v[t]) == abs(j - t)){
                    flag = false;
                    break;
                }
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;
}
