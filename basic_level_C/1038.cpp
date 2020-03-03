#include <stdio.h>

int main() {
    int N;
    int n;
    int scores[101] = {0};
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &n);
        scores[n]++;
    }
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &n);
        printf("%d", scores[n]);
        if(i != N - 1)
            printf(" ");
    }

    return 0;
}
