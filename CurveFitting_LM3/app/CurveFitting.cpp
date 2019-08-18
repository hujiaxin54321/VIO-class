#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;
int res = 0;
int N;
vector<int> Li, Wi;
vector<bool> visited;
bool check(int L, int W, int Li, int Wi){
    if(Li > L && Wi < 7*W)
        return true;
    return false;
}

void dfs(const int &height, int L, int W)
{
    if(height > res)
        res = height;

    for(int i=0;i<N;i++){
        if(visited[i] || !check(L,W,Li[i],Wi[i])) continue;
        visited[i] = true;
        dfs(height+1,Li[i],Wi[i]);
        visited[i] = false;
    }
    return;
}

int main()
{
    cin >> N;
    int minL = INT_MAX;
    int minLV = INT_MAX;
    int minW = INT_MAX;
    int minWV = INT_MAX;
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        Li.push_back(tmp);
        minLV = min(minLV, tmp);
        if(tmp == minLV)
            minL = i;
    }
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        Wi.push_back(tmp);
        minWV = min(minWV, tmp);
        if(tmp == minWV)
            minW = i;
    }
    visited = vector<bool>(N,false);
    int res1=0;
    int res2 = 0;
    int height = 0;
    visited[minL] = true;
    dfs(height+1,Li[minL],Wi[minL]);
    visited[minL] = false;

    height = 0;
    visited[minW] = true;
    dfs(height+1,Li[minL],Wi[minL]);
    visited[minW] = false;
    /*for(int i=0;i<N;i++){
        visited[i] = true;
        dfs(height+1,Li[i],Wi[i]);
        visited[i] = false;
    }*/
    cout << res << endl;
    return 0;
}