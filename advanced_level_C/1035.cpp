#include<cstdio>
#include<cstring>

// Todo 
const int MAXN = 1001;
struct Stu{
	char name[11];
	char password[11];
	bool flag;
}stu[MAXN];

int main(){
	int n, m = 0;
	int len = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		bool flag = true;
		scanf("%s %s", stu[i].name, stu[i].password);
		len = strlen(stu[i].password);
//		printf("len:%d\n", len);
		for(int j = 0; j < len; j++){
			if(stu[i].password[j] == '1') {
				stu[i].password[j] = '@';
				flag = false;
			}
			if(stu[i].password[j] == '0') {
				stu[i].password[j] = '%';
				flag = false;
			}
			if(stu[i].password[j] == 'l') 
			{
				stu[i].password[j] = 'L';
				flag = false;
			}
			if(stu[i].password[j] == 'O') 
			{
				stu[i].password[j] = 'o';
				flag = false;
			}
			stu[i].flag = flag;
			
		}
		if(stu[i].flag == false) m++;
		
	}
	if(m == 0)
		if(n == 1)
			printf("There is %d account and no account is modified", n);
		else
			printf("There are %d accounts and no account is modified", n);
	else{
		printf("%d\n", m);
		for(int i = 0; i < n; i++){
			if(!stu[i].flag){
				printf("%s %s\n", stu[i].name, stu[i].password);
			}
		}
	}
	return 0;
}
