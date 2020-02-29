#include<stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int n1 = n / 100;
	int n2 = n % 100 / 10;
	int n3 = n % 10;
	for(int i = 0; i < n1; i++){
		printf("B");
	}
	for(int i = 0; i < n2; i++){
		printf("S");
	}
	for(int i = 1; i <= n3; i++){
		printf("%d", i);
	}
	return 0;
}
