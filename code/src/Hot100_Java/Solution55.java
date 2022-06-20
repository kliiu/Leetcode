package Hot100_Java;

 class Solution55 {
    public boolean canJump(int[] nums) {
        int max_len=nums.length;
        int len=1;
        for(int i=1;i<=nums.length;i++){
            if(len>=i)
            {
                if(i+nums[i-1]>len)//注意 当len已经大于要更新的值，不用更新
                    len=i+nums[i-1];//当前位置可达，更新最远距离
            }
            if(len>=max_len)return true;
        }
        return false;
    }
}

class Test55{
    public static void main(String[] args) {
        Solution55 s=new Solution55();
        int nums[]= {3,0,8,2,0,0,1};
        s.canJump(nums);
    }
}