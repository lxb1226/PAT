#include <stdio.h>

int main() {
    int exponent;
    char line[10000], *p = line;
    // [] scanf()连续吃进集合中的字符并放入对应的字符数组，直到发现不在集合中的字符为止
    // ^ 表示补集
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
