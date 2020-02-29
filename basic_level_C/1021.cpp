#include<cstdio>
#include<cstring>

int main(){
	char num[1001];
	int cnt[10] = {0};
	scanf("%s", num);
	int len = strlen(num);
	for(int i = 0; i < len; i++){
		cnt[num[i] - '0']++;
	}
	for(int i = 0; i < 10; i++){
		if(cnt[i] != 0) printf("%d:%d\n", i, cnt[i]);
	}
	return 0;
}
