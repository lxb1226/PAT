#include<cstdio>

char d[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};

int parse_13(int n, char ans[]){
	int num = 0;
	do{
		ans[num++] = d[n % 13];
		n = n / 13;
	}while(n != 0);
	return num;
}

int main(){
	int n;
	char ans[2];
	int len = 0;
	printf("#");
	for(int i = 0; i < 3; i++){
		scanf("%d", &n);
		len = parse_13(n, ans);
		if(len == 1) printf("0");
		for(int j = len - 1; j >= 0; j--){
			printf("%c", ans[j]);
		}
	}
	return 0;
	
}
