//
// Created by 21551 on 2023/3/17.
//
#include<bits/stdc++.h>
using namespace std;
const int N=12;
long long dp[N][1<<N];
bool st[1<<N];
int main()
{
    int n,m,cnt;
    while (cin >> n >> m, n | m) {
        for (int i = 0; i < 1 << n; i++) { // n位  n - 1个
            int cnt = 0;
            st[i] = true;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    if(cnt & 1 ) // 如果连续得0得个数位奇数是    这是因为竖放得位置个数要为2
                        st[i] = false;
                }
                else {
                    cnt++;
                }
            }
            // 处理最高为的0的个数
            if (cnt & 1) st[i] = false;
        }
        memset(dp,0,sizeof dp);
        dp[0][0]=1;
        for(int i=1;i<=m;i++){
            for(int j=0;j<1<<n;j++){
                for(int k=0;k<1<<n;k++){
                    if(st[k|j]&&(j&k)==0){
                        dp[i][j]+=dp[i-1][k];
                    }
                }
            }
        }
        cout<<dp[m][0]<<endl;
    }
    return 0;
}