#include<cstdio>

struct Stu{
	char name[15];
	char id[15];
	char gender;
	int score;
}stu[10010];

int main(){
	int n;
	int max_score = -1, min_score = 101;
	int max_index, min_index;
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s %c %s %d", stu[i].name, &stu[i].gender, stu[i].id, &stu[i].score);
		if(stu[i].gender == 'F'){
			if(stu[i].score > max_score){
				max_index = i;
				max_score= stu[i].score;
			}
		}else{
			if(stu[i].score < min_score){
				
				min_index = i;
				min_score = stu[i].score;
			}
		}
	}
	
	if(max_score != -1)
		printf("%s %s\n", stu[max_index].name, stu[max_index].id);
	else
		printf("Absent\n");
	if(min_score != 101)
		printf("%s %s\n", stu[min_index].name, stu[min_index].id);
	else
		printf("Absent\n");
	if(max_score == -1 || min_score == 101){
		printf("NA");
	}else{
		printf("%d", stu[max_index].score - stu[min_index].score);
	}
	
	return 0;
	
}
