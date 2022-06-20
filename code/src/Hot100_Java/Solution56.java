package Hot100_Java;

import java.util.*;

public class Solution56 {
    public int[][] merge(int[][] intervals) {
        //比较第一个数进行排序
        //重写操作符
        Arrays.sort(intervals, (o1, o2) -> o1[0]-o2[0]);
        List<int []> ans=new ArrayList<>();
        ans.add(intervals[0]);
        for(int i =1;i<intervals.length;i++){
            int L=intervals[i][0];
            int R=intervals[i][1];
            if(L>ans.get(ans.size()-1)[1]){//get(ans.size()-1)
                //直接加入
                ans.add(intervals[i]);
            }
            else {
                //更新为两者更大值
                ans.get(ans.size()-1)[1]=Math.max(R,ans.get(ans.size()-1)[1]);
            }
        }
        return ans.toArray(new int[ans.size()][]);
    }
}
class Test56{
    public static void main(String[] args) {
        Solution56 s= new Solution56();
        int[][] a= {{1, 3},{8, 10},{2, 6},{15, 18}};
        s.merge(a);
    }
}