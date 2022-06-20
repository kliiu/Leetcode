package Hot100_Java;

class Solution48 {

    public void rotate_assist(int[][] matrix) {
        //辅助数组
        if(matrix.length==1)return;//1×1
        int[][] assist=new int[matrix.length][matrix[0].length];//辅助数组
        for(int i=0;i<matrix.length;i++){
            for(int j =matrix.length-1;j>=0;j--){
                assist[i][matrix.length-1-j]= matrix[j][i];
            }
        }
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix.length;j++){
                matrix[i][j]=assist[i][j];
            }
        }
    }

    public void rotate(int[][] matrix){
        //水平翻转
        for(int i=0;i< matrix.length;i++){
            if(i>=matrix.length-1-i)break;
            int [] temp=matrix[i];
            matrix[i]=matrix[matrix.length-1-i];
            matrix[matrix.length-1-i]=temp;
        }
        //中心对称翻转
        for(int i=0;i< matrix.length;i++){
            for (int j=i;j<matrix.length;j++){
                if(i!=j){
                    int temp=matrix[i][j];
                    matrix[i][j]=matrix[j][i];
                    matrix[j][i]=temp;
                }
            }
        }
    }

}

class TestDrive{
    public static void main(String[] args) {
        Solution48 s=new Solution48();
        int [][]m={{5,1,9,11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
        s.rotate(m);
    }
}