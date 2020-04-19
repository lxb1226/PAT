#include<cstdio>
#include<map>

using namespace std;

int main(){
    int m,n, temp;
    map<int, int> colors;
    scanf("%d %d", &m, &n);
    int half = m * n /2;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &temp);
            colors[temp]++;
            if(colors[temp] > half){
                printf("%d", temp);
                return 0;
            }
        }
    }
    return 0;
}
