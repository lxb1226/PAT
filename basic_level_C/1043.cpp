#include <stdio.h>

int main() {
    int nums[128] = {0};
    char c;
    while((c = getchar()) != '\n'){
        nums[c]++;
    }

    while(1){
        if(nums['P'])   {putchar('P'); nums['P']--;}
        if(nums['A'])   {putchar('A'); nums['A']--;}
        if(nums['T'])   {putchar('T'); nums['T']--;}
        if(nums['e'])   {putchar('e'); nums['e']--;}
        if(nums['s'])   {putchar('s'); nums['s']--;}
        if(nums['t'])   {putchar('t'); nums['t']--;}
        if(nums['P'] == 0 && nums['A'] == 0 && nums['T'] == 0 && nums['e'] == 0 && nums['s'] == 0 && nums['t'] == 0)
            break;
    }
    return 0;
}
