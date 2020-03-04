#include<cstdio>

using namespace std;

int main(void){
	int nums[10];
	for(int i = 0; i<10; i++)
		scanf("%d", &nums[i]);
	for(int j = 0; j<10; j++){
		if(j!=0 && nums[j] != 0){
			printf("%d",j);
			nums[j]--;
			break;
		}
	}
	for(int i = 0; i<10; i++){
		if(nums[i] != 0){
			for(int j = 0; j < nums[i]; j++)
				printf("%d", i);
		}
	}
	
	return 0;
}
