#include<cstdio>
#include<algorithm>

using namespace std;
struct people{
    int id, talent, virtue,total;
    int status;
}peoples[100001];
int n, l, h, cnt = 0;

bool cmp(people a, people b){
    if(a.status != b.status) return a.status < b.status;
    else if(a.total != b.total) return a.total > b.total;
    else if(a.virtue != b.virtue) return a.virtue > b.virtue;
    else return a.id < b.id;
}

int main(){
    scanf("%d %d %d", &n, &l, &h);
    for(int i = 0; i < n; i++){
        int id, a, b,status;
        scanf("%d %d %d",&id, &b, &a);
        if(a >= l && b >= l){
            peoples[cnt].id = id;
            peoples[cnt].talent = a;
            peoples[cnt].virtue = b;
            peoples[cnt].total = a + b;
            if(a >= h && b >= h)
                status = 1;
            else if(a < h && b >= h)
                status = 2;
            else if(a < h && b < h && b >= a)
                status = 3;
            else
                status = 4;
            peoples[cnt].status = status;
            cnt++;
        }
    }

    sort(peoples, peoples+cnt, cmp);

    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++){
        printf("%d %d %d\n", peoples[i].id, peoples[i].virtue, peoples[i].talent);
    }
    return 0;
}
