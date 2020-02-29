#include<stdio.h>


int main(){
	char c;
	char pinyin[10][10] = {"ling","yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	int sum = 0;
	while((c = getchar()) != '\n'){
		sum += c - '0';
	}
	if(sum / 100 != 0)
        printf("%s ",pinyin[sum/100]);
    if(sum / 10 != 0)
        printf("%s ", pinyin[sum/10%10]);
   	printf("%s",pinyin[sum%10]);
   	return 0;
}
