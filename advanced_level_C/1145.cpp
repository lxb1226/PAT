#include<cstdio>
#include<vector>
using namespace std;

bool isPrime(int n){
    if(n == 0 || n == 1) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    int mSize, m, n, a;
    scanf("%d%d%d", &mSize, &n, &m);
    while(!isPrime(mSize))mSize++;
    vector<int> v(mSize);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        int flag = 0;
        for(int j = 0; j < mSize; j++){
            int pos = (a + j*j) % mSize;
            if(v[pos] == 0){
                v[pos] = a;
                flag = 1;
                break;
            }
        }
        if(!flag) printf("%d cannot be inserted.\n", a);
    }
    int ans = 0;
    for(int i = 0; i < m; i++){
        scanf("%d", &a);
        for(int j = 0; j <= mSize; j++){
            ans++;
            int pos = (a + j * j) %mSize;
            if(v[pos] == a || v[pos] == 0)break;
        }
    }
    printf("%.1lf\n", ans * 1.0 / m);
    return 0;
}
