#include<cstdio>

int main(){
	int scores[1001] = {0};
	int n;
	scanf("%d", &n);
	int index, number, score;
	for(int i = 0; i < n; i++){
		scanf("%d-%d %d", &index, &number, &score);
		scores[index] += score;
	}
	int max = 0, max_id;
	for(int i = 1; i <= 1000; i++){
		if(scores[i] > max){
			max = scores[i],
			max_id = i;
		}
	}
	printf("%d %d", max_id, max);
	return 0;
}
