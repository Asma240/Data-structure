class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] Lp = new int[n];
        Lp[0]= 1;

        for(int i=1;i<n;i++){
            Lp[i]=Lp[i-1]*nums[i-1];

        }
        int rp=1;
        for(int i=n-1;i>=0;i--){
            Lp[i]=rp*Lp[i];
            rp=rp*nums[i];
        }
        return Lp;

    }
}