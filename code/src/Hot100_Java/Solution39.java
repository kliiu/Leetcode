package Hot100_Java;

import java.util.*;

 class Main39 {
    public static void main(String[] args) {
       Solution39 solution39=new Solution39();
        int[] candidates={2,3,7};
        List<List<Integer>> ans=solution39.combinationSum(candidates,7);
    }
}
class Solution39{
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        HashSet<ArrayList<Integer>> ans=new HashSet<>();
        Deque<Integer> path=new ArrayDeque<>();
        ArrayList<Integer> candidates_sorted=new ArrayList<>();
        //将int[]转为ArrayList
        for (int i = 0; i < candidates.length; i++) {
            candidates_sorted.add(candidates[i]);
        }
        Collections.sort(candidates_sorted);//排序
        dfs(ans,path,target,candidates_sorted);
        return new ArrayList<>(ans);
    }

    private void dfs(HashSet<ArrayList<Integer>> ans, Deque<Integer> path, int target,ArrayList<Integer> candidates) {
        if(target==0){
            ArrayList<Integer> temp=new ArrayList<>(path);//拷贝
            Collections.sort(temp);//排序
            ans.add(temp);
            return;
        }
        for (int i = 0; i <candidates.size() ; i++) {
            if(target-candidates.get(i)>=0){
                path.addLast(candidates.get(i));
                dfs(ans,path,target-candidates.get(i),candidates);
                path.removeLast();
            }
        }
    }


}