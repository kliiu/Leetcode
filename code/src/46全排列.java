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
//46ȫ����
class Solution46 {
    public List<List<Integer>> permute(int[] nums) {
    int len=nums.length;
    List<List<Integer>> ans=new ArrayList<>();
    if (len==0){
        return ans;
    }
    boolean[] used=new boolean[len];//Ĭ��ȫΪfalse
    Deque<Integer> path=new ArrayDeque<>();
    dfs(ans,nums,0,len,used,path);
    return ans;
    }
    //�ݹ�
    void dfs(List<List<Integer>> ans,int[] nums, int depth, int len, boolean[] used, Deque<Integer> path){
        if(depth==len){
            ans.add(new ArrayList<>(path));//����
            //������������ӽ�ȥ�ľ������ã����ջ��ɿ�
            return;
        }
        for (int i = 0; i < len; i++) {
            if(used[i])continue;
            path.addLast(nums[i]);
            used[i]=true;
            //��һ��
            dfs(ans,nums,depth+1,len,used,path);
            //����
            used[i]=false;
            path.removeLast();

        }

    }
}