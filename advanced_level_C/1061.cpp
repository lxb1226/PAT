#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int main(){
	char s1[61], s2[61];
	char c;
	char weekday[7][7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	scanf("%s", s1);
	scanf("%s", s2);
	int len = min(strlen(s1), strlen(s2));
	int i = 0;
	for(i = 0; i < len; i++){
		if(s1[i] >= 'A' && s1[i] <= 'G' && s1[i] == s2[i]){
			c = s1[i];
			printf("%s ", weekday[c - 'A']);
			break;
		}
	}
	
	for(int j = i+1; j < len; j++){
		if(s1[j] == s2[j]){
			c = s1[j];
			if(c >= '0' && c <= '9'){
				printf("0%c:",c);
				break;
			}
				
			else if(c >= 'A' && c <= 'N'){
				printf("%d:", c - 'A' + 10);
				break;
			}
		}
	}
	
	scanf("%s", s1);
	scanf("%s", s2);
	len = min(strlen(s1), strlen(s2));
	for(i = 0; i < len; i++){
		if((s1[i] >= 'A' && s1[i] <= 'Z') || (s1[i] >= 'a' && s1[i] <= 'z') && s1[i] == s2[i]){
			printf("%02d", i);
			break;
		}
	}
	return 0;
	
}
