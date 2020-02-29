#include<cstdio>
#include<string.h>

int main(){
	char str[81];
	scanf("%s", str);
	int length = strlen(str);
	int n1, n3, n2;
	n1 = n3 = (length + 2) / 3;
	n2 = (length + 2 - 2 * n1);
	for(int i = 0; i < n1; i++){
		printf("%c", str[i]);
		for(int j = 1; j < n2 - 1; j++){
			if(i == n1 - 1 ){
				printf("%c", str[i+j]);
			}else{
				printf(" ");
			}
		}
		printf("%c\n", str[length - 1 - i]);
	}
	
	return 0;
}
