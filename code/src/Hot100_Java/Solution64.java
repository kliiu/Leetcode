package Hot100_Java;

import java.util.*;
class Solution64_1 {
    //超时
    public int minPathSum(int[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        List<Integer> ans=new ArrayList<>();
        ans.add(-1);

        dfs(0,0,ans,grid,m,n,0);
        return ans.get(0);
    }
    void dfs(int i,int j,List<Integer> minLen,int[][] grid,int m,int n,int pathLengh){

        if(i>m-1||j>n-1)return;
        pathLengh+=grid[i][j];
        if(i==m-1&&j==n-1){
            if(minLen.get(0)>pathLengh||minLen.get(0)<0)
                minLen.set(0,pathLengh);//替换最小路径
            return;
        }
        dfs(i+1,j,minLen,grid,m,n,pathLengh);//向下
        dfs(i,j+1,minLen,grid,m,n,pathLengh);//向右
    }
}
class Solution64 {
    public int minPathSum(int[][] grid) {
        int m= grid.length;//row
        int n=grid[0].length;//column
        int[][]dp=new int[m][n];
        dp[0][0]=grid[0][0];//初始条件
        for (int i = 1; i < m; i++) {
            dp[i][0]=dp[i-1][0]+grid[i][0];//计算第一列
        }
        for (int i = 1; i < n; i++) {
            dp[0][i]=dp[0][i-1]+grid[0][i];//计算第一行
        }
        for(int i=1;i<m;i++){
            for (int j = 1; j < n; j++) {
                dp[i][j]=Math.min(dp[i-1][j],dp[i][j-1])+grid[i][j];//状态转移
            }
        }
        return dp[m-1][n-1];
    }

}

 class Test64 {
     public static void main(String[] args) {
         int[][]t= {

                 {
                         1, 2, 3
                 },

                 {
                         4, 5, 6
                 }};
         Solution64 s=new Solution64();
         int a=s.minPathSum(t);
     }

}
