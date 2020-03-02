#include<cstdio>

int main(){
	char c;
	int sum = 0, len = 0;
	int digit[10];
	char digits[10][10] = {"zero","one", "two", "three", "four","five","six", "seven", "eight", "nine"};
	while((c = getchar()) != '\n'){
		sum += c - '0';
	}
	if(sum == 0)
		printf("zero");
	else{
		while(sum != 0){
			digit[len++] = sum % 10;
			sum /= 10;
		}
		for(int i = len - 1; i >= 0; i--){
			printf("%s", digits[digit[i]]);
			if(i != 0) printf(" ");
		}
	}
	
	return 0;
	
}
