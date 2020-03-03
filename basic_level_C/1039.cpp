#include<cstdio>
#include<ctype.h>

int main(){
	int zhuzi[128] = {0};
	char c;
	while((c = getchar()) != '\n')
		zhuzi[c] += 1;
	int cnt1 = 0, cnt2 = 0;
	while((c = getchar()) != '\n'){
		zhuzi[c] -= 1;
	}
	for(int i = 0; i < 128; i++){
		if(zhuzi[i] >= 0) cnt1 += zhuzi[i];
		else cnt2 += zhuzi[i];
	}
	if(cnt2 != 0) 
		printf("No %d", -cnt2);
	else
		printf("Yes %d", cnt1);
	return 0;
}
