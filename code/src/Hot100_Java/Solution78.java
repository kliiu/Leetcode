package Hot100_Java;
import java.util.*;
class Solution78 {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans=new ArrayList<>();
        List<Integer> path=new ArrayList<>();
        dfs(ans, path,nums,0);
        return ans;

    }

    void dfs(List<List<Integer>> ans,List<Integer> path,int[]nums,int begin){
        //index表示path中最后一个元素在nums的下标
        ans.add(new ArrayList<Integer>(path));//copy
        for(int i=begin;i<nums.length;i++ ){
                path.add(nums[i]);
                dfs(ans, path,nums,i+1);//从下一层开始回溯 注意这里是i!! 不是begin
                path.remove(path.size()-1);//删除

        }
    }
}
class test78{
    public static void main(String[] args) {
        Solution78 s=new Solution78();
        s.subsets(new int[]{1,2,3});
    }
}