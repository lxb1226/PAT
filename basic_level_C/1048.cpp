#include <stdio.h>
#include <string.h>


int main() {
    char A[101], B[101];
    char encrypt[] = "0123456789JQK";

    scanf("%s %s", A, B);
    int lenA = strlen(A);
    int lenB = strlen(B);

    int maxLen = lenA > lenB ? lenA : lenB;
    int a, b;

    for(int i = 0; i < maxLen; i++){
        a = lenA + i - maxLen < 0 ? 0 : A[lenA + i - maxLen] - '0';
        b = lenB + i - maxLen < 0 ? 0 : B[lenB + i - maxLen] - '0';

        if((maxLen - i) % 2)
            putchar(encrypt[(a + b) % 13]);
        else
            putchar('0' + (b - a < 0 ? b - a + 10 : b - a));
    }


    return 0;
}
