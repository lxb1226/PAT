#include<cstdio>
#include<ctype.h>

/**

 ctype.h:ctype.h��C��׼�������е�ͷ�ļ���������һ��C�����ַ����ຯ����C character classification functions�������ڲ����ַ��Ƿ������ض����ַ��������ĸ�ַ��������ַ��ȵȡ���֧�ֵ��ֽ��ַ���Ҳ֧�ֿ��ַ���
 fgets��������Ϊ��ָ�������ж�ȡ���ݣ�ÿ�ζ�ȡһ�С���ԭ��Ϊ��char *fgets(char *str, int n, FILE *stream);��ָ������ stream ��ȡһ�У��������洢�� str ��ָ����ַ����ڡ�����ȡ (n-1) ���ַ�ʱ�����߶�ȡ�����з�ʱ�����ߵ����ļ�ĩβʱ������ֹͣ���������������
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
