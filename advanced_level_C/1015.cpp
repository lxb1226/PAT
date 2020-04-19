#include<cstdio>


int tenTod(int n, int d){
    int nums[100] = {0};
    int len = 0, num = 0;
    while(n != 0){
        nums[len++] = n % d;
        n = n / d;
    }
    for(int i = 0; i < len; i++){
        num = num * d + nums[i];
    }
    return num;
}

bool isPrime(int n){
    if(n <= 1) return false;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    int n, d, reverse_num;
    scanf("%d", &n);
    while(n >= 0){
        scanf("%d", &d);
        reverse_num = tenTod(n, d);
        if(isPrime(n) && isPrime(reverse_num)) printf("Yes\n");
        else printf("No\n");
        scanf("%d", &n);
    }

    return 0;
}
