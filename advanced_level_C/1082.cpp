#include<cstdio>
#include<cstring>


// TODO:未完 
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
		right -= 4;		// 将right每次左移4位，直到left与right在同一节 
	}
	while(left < len){		// 循环处理每次处理数字的一节（4位或小于4位） 
		bool flag = false;	// flag==false表示没有累积的0 
		bool isPrint = false;	// isPrint==false表示该节没有输出过其中的数 
		while(left < right){	// 从左至右处理数字中某节的每一位 
			if(left > 0 && str[left] == '0') flag = true;	// 如果当前位为0，令标记为true 
			else{	// 如果当前位不为0， 
				if(flag == true){	// 如果存在累积的0 
					printf(" ling");
					flag = false;
				}
				// 只要表示首位（包括负号），后面的每一位前都要输出空格 
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
