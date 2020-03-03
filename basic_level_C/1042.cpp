#include<cstdio>
#include<ctype.h>

int main(){
	int str[128] = {0};
	char c;
	while((c = getchar()) != '\n')
		str[tolower(c)] += 1;
	int max = 0, s;
	for(int i = 0; i < 128; i++){
		if(isalpha(i) && str[i] > max){
			max = str[i];
			s = i;
		}
	}
	printf("%c %d", s, max);
	return 0;
}
