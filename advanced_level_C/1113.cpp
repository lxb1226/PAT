#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;


int main(){
    int n;
    int s1 = 0, s2 = 0;
    scanf("%d", &n);
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    for(int i = 0; i < n/2; i++)
        s1 += v[i];
    for(int i = n/2; i < n; i++)
        s2 += v[i];
    if(n % 2 == 0) printf("0 ");
    else printf("1 ");
    printf("%d", abs(s1 - s2));
    return 0;
}
