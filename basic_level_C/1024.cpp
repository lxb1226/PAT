#include <stdio.h>

int main() {
    int exponent;
    char line[10000], *p = line;
    // [] scanf()�����Խ������е��ַ��������Ӧ���ַ����飬ֱ�����ֲ��ڼ����е��ַ�Ϊֹ
    // ^ ��ʾ����
    scanf("%[^E]E%d", line, &exponent);
    if(*p++ == '-') putchar('-');
    if(exponent >= 0){
        putchar(*p);
        for(p += 2; exponent; exponent--){
            putchar(*p ? *p++ : '0');
        }
        if(*p){
            putchar('.');
            while(*p) putchar(*p++);
        }
    }
    if(exponent < 0){
        printf("0.");
        for(exponent++; exponent; exponent++)
            putchar('0');
        for(; *p; p++) if(*p != '.') putchar(*p);
    }


    return 0;
}
