#include<cstdio>
#include<ctype.h>

/**

 ctype.h:ctype.h是C标准函数库中的头文件，定义了一批C语言字符分类函数（C character classification functions），用于测试字符是否属于特定的字符类别，如字母字符、控制字符等等。既支持单字节字符，也支持宽字符。
 fgets函数功能为从指定的流中读取数据，每次读取一行。其原型为：char *fgets(char *str, int n, FILE *stream);从指定的流 stream 读取一行，并把它存储在 str 所指向的字符串内。当读取 (n-1) 个字符时，或者读取到换行符时，或者到达文件末尾时，它会停止，具体视情况而定
*/

int main(){
	int printed[128] = {0};
	char c, line[82];
	scanf("%s", line);
	getchar();
	while((c = getchar()) != '\n')
		printed[toupper(c)]++;
	for(char *p = line; *p; p++){
		c = toupper(*p);
		if(printed[(int)c] == 0){
			putchar(c);
			printed[(int)c] = -1;
		}
	}
	return 0;
}
