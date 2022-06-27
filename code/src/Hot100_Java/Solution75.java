package Hot100_Java;

public class Solution75 {
    public void sortColors(int[] nums) {
        int p0=0;
        int p1=0;
        for (int i = 0; i < nums.length; i++) {//要从0开始
            if(nums[i]==0){//找到0
                nums[i]=nums[p0];
                nums[p0]=0;
                if(p0<p1){//当p0<p1，交换i和p0的后，会把1交换出去，因此需要再把1交换回来
                    int temp=nums[i];
                    nums[i]=nums[p1];
                    nums[p1]=temp;
                }
                p0++;
                p1++;

            }
            else if(nums[i]==1){//找到1
                nums[i]=nums[p1];
                nums[p1]=1;
                p1++;
            }
        }
    }
}
class Test675 {
    public static void main(String[] args) {
        int[]t= {0,1};
        Solution75 s=new Solution75();
        s.sortColors(t);
    }

}
