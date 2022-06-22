package Hot100_Java;

import java.util.ArrayList;
import java.util.List;
public  class Solution62{
    //动态规划
    public int uniquePaths( int m, int n){
        int[][] f=new int[m][n];
        for(int i=0;i<n;i++)
        {
            f[0][i]=1;
        }
        for (int i = 0; i < m; i++) {
            f[i][0]=1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                f[i][j]=f[i-1][j]+f[i][j-1];
            }
        }
        return f[m-1][n-1];
    }
}
class Solution62_2{
    //组合数学
    public int uniquePaths( int m, int n){
        long ans=1;
        for (int x = 1,y=1; y < m; x++,y++) {
            ans=ans * x / y;
        }
        return (int)ans;
        
    }
}
class Solution62_1{
    //dfs超时
    public int uniquePaths( int m, int n) {

        List<Integer> pathNum= new ArrayList<>();
        pathNum.add(0);
        int x=1,y=1;
        walk(x,y,pathNum,m,n);
        return pathNum.get(0);

    }
    void walk(int x,int y,List<Integer> pathNum,int m, int n){
        if(x==n&&y==m){
            pathNum.set(0,pathNum.get(0)+1);
            return;}
        if(x<n)walk(x+1,y,pathNum,m,n);
        if(y<m)walk(x,y+1,pathNum,m,n);
    }

}

class test62 {

    public static void main(String[] args) {
        Solution62 s=new Solution62();
        s.uniquePaths(3,7);
    }
}