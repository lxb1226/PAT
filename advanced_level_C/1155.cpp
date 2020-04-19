#include<cstdio>
#include<vector>
using namespace std;

vector<int> temp;
int n;
int nums[1002];
bool minflag = true, maxflag = true;
void dfs(int s){
    temp.push_back(nums[s]);
    // 没有节点
    if(2*s > n){
        for(int i = 0; i < temp.size(); i++){
            if(i != temp.size() - 1)
                printf("%d ", temp[i]);
            else
                printf("%d\n", temp[i]);
        }
        temp.pop_back();
        return ;
    }else if(2*s+1 <= n){
        // 有左右节点
        if(nums[s] < nums[2*s] || nums[s] < nums[2*s+1])
            maxflag = false;
        if(nums[s] > nums[2*s] || nums[s] > nums[2*s+1])
            minflag = false;
        dfs(2*s + 1);
        dfs(2*s);
    }else {
        // 只有左节点
        if(nums[s] < nums[2*s])
            maxflag = false;
        if(nums[s] > nums[2*s])
            minflag = false;
        dfs(2*s);
    }
    temp.pop_back();
}

int main(){

    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", nums+i);
    dfs(1);
    if(maxflag == true && minflag == false)
        printf("Max Heap\n");
    else if(maxflag == false && minflag == true)
        printf("Min Heap\n");
    else
        printf("Not Heap\n");
    return 0;
}
