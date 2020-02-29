#include<cstdio>

int main(){
	int n,b;
	bool flag = true;
	scanf("%d %d", &n, &b);
	int ans[40], num = 0;
	do{
		ans[num++] = n % b;
		n = n / b;
	}while(n != 0);
	for(int i = 0; i < num / 2; i++){
		if(ans[i] != ans[num - 1 - i]) flag = false;
	}
	if(flag == false) printf("No\n");
	else printf("Yes\n");
	for(int i = num - 1; i >= 0; i--){
		if(i == 0) printf("%d", ans[i]);
		else printf("%d ", ans[i]);
	}
	return 0;
} 
