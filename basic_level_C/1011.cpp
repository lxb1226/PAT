#include<cstdio>

using namespace std;

int main(){
	int n;
	long long A, B, C;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld %lld %lld", &A, &B, &C);
		if(A + B > C){
			printf("Case #%d: true\n", i);
		}else{
			printf("Case #%d: false\n", i);
		}
	}
	return 0;
} 
