#include<cstdio>




int main(){
	int A, B, D,sum;
	int ans[40], num = 0;
	scanf("%d %d %d", &A, &B, &D);
	sum = A + B;
	// 十进制转其他进制 
	do{
		ans[num++] = sum % D;
		sum = sum / D;
	}while(sum != 0);
	for(int i = num - 1; i >= 0; i--){
		printf("%d", ans[i]);
	}
	
}
