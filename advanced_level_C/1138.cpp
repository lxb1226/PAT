#include<cstdio>
#include<vector>

using namespace std;

vector<int> pre, in;
int n;

int postOrder(int inL, int inR, int preL, int preR){
    if(inL == inR) return in[inL];
    int k;
    for(k = inL; k <= inR; k++)
        if(in[k] == pre[preL])
            break;
    int numL = k - inL;
    if(k == inL)
        return postOrder(k+1, inR, preL+1,preR);
    else
        return postOrder(inL, k - 1, preL+1, preL + numL);

}

int main(){
    scanf("%d", &n);
    pre.resize(n);
    in.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    printf("%d", postOrder(0,n-1,0,n-1));
    return 0;
}
