#include<cstdio>

int main(){
	int n;
	int pre = 0, now;
	int totaltime = 0;
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &now);
		if(now > pre) totaltime += 6 * (now - pre);
		else totaltime += 4 * (pre - now);
		totaltime += 5;
		pre = now;
	}
	printf("%d\n", totaltime);
	return 0;
}
