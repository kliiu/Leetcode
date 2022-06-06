import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

 class Main46{
    public static void main(String[] args) {
    int[] nums={1,2,3};
    Solution46 solution46=new Solution46();
        List<List<Integer>> ans=solution46.permute(nums);
    }
}
//46全排列
class Solution46 {
    public List<List<Integer>> permute(int[] nums) {
    int len=nums.length;
    List<List<Integer>> ans=new ArrayList<>();
    if (len==0){
        return ans;
    }
    boolean[] used=new boolean[len];//默认全为false
    Deque<Integer> path=new ArrayDeque<>();
    dfs(ans,nums,0,len,used,path);
    return ans;
    }
    //递归
    void dfs(List<List<Integer>> ans,int[] nums, int depth, int len, boolean[] used, Deque<Integer> path){
        if(depth==len){
            ans.add(new ArrayList<>(path));//拷贝
            //如果不拷贝，扔进去的就是引用，最终会变成空
            return;
        }
        for (int i = 0; i < len; i++) {
            if(used[i])continue;
            path.addLast(nums[i]);
            used[i]=true;
            //下一层
            dfs(ans,nums,depth+1,len,used,path);
            //回溯
            used[i]=false;
            path.removeLast();

        }

    }
}