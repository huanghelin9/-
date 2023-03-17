//
// Created by 21551 on 2023/3/17.
//

#include<bits/stdc++.h>
using namespace std;
const int N=20,M=1<<20;
int w[N][N],dp[M][N];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>w[i][j];
        }
    }
    memset(dp,0x3f,sizeof dp);
    dp[1][0]=0;
    for(int i=0;i<1<<n;i++){
        if(i&1){
            for(int j=0;j<n;j++){
                if(i>>j&1){
                    for(int k=0;k<n;k++)
                        if(i-(1<<j)&1){
                            dp[i][j]=min(dp[i][j],dp[i-(1<<j)][k]+w[k][j]);
                    }
                }
            }
        }
    }
    cout<<dp[(1<<n)-1][n-1];
    return 0;
}