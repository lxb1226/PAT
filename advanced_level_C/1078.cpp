#include<cstdio>
#include<string>
using namespace std;
int flag[10001];
int n, m;

bool isPrime(int n){
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

void insert(int key){
    for(int step = 0; step < n; step++){
        int index = (key + step * step) % n;
        if(flag[index] == 0){
            flag[index] = 1;
            printf("%d", index % n);
            return ;
        }
    }
    printf("-");
}


int main(){
    scanf("%d %d", &n, &m);
    while(!isPrime(n)) n++;
    int temp;
    for(int i = 0; i < m; i++){
        scanf("%d", &temp);
        if(i != 0) printf(" ");
        insert(temp);
    }

    return 0;
}
