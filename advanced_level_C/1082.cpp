#include<cstdio>
#include<cstring>


// TODO:δ�� 
char num[10][5] = {"ling","yi", "er","san", "si","wu","liu","qi","ba", "jiu"};
char wei[5][5] = {"Shi", "Bai", "Qian", "Wan", "Yi"};

int main(){
	char str[15];
	scanf("%s", str);
	int len = strlen(str);
	int left = 0, right = len - 1;
	if(str[0] == '-'){
		printf("Fu");
		left++;
	}
	while(left + 4 <= right){
		right -= 4;		// ��rightÿ������4λ��ֱ��left��right��ͬһ�� 
	}
	while(left < len){		// ѭ������ÿ�δ������ֵ�һ�ڣ�4λ��С��4λ�� 
		bool flag = false;	// flag==false��ʾû���ۻ���0 
		bool isPrint = false;	// isPrint==false��ʾ�ý�û����������е��� 
		while(left < right){	// �������Ҵ���������ĳ�ڵ�ÿһλ 
			if(left > 0 && str[left] == '0') flag = true;	// �����ǰλΪ0������Ϊtrue 
			else{	// �����ǰλ��Ϊ0�� 
				if(flag == true){	// ��������ۻ���0 
					printf(" ling");
					flag = false;
				}
				// ֻҪ��ʾ��λ���������ţ��������ÿһλǰ��Ҫ����ո� 
				if(left > 0) printf(" ");
				printf("%s", num[str[left] - '0']);
				isPrint = true;
				if(left != right)	printf(" %s", wei[right - left - 1]);
			}
			left++;
		}
		if(isPrint == true && right != len - 1) printf(" %s",wei[(len - 1 - right) /4 + 2]);
		right += 4;
	}
	return 0;
	

}
