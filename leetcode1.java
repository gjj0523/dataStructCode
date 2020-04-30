package cn.xmy.problem1;

public class Problem1 {
	public static void main(String[] args) {
		int[] nums = {1,2,3,4,5,6,7};
		int target = 9;
		Solution s = new Solution();
		s.twoSum(nums, target);
	}
}

//class Solution {
//    public int[] twoSum(int[] nums, int target) {
//		for(int i = 0; i < nums.length; i++)
//		{
//			for(int j = i + 1; j < nums.length; j++)
//			{
//				if(nums[i] + nums[j] == target)
//				{
//					int[] result = new int[2];
//					result[0] = i;
//					result[1] = j;
//					for (int n : result) {
//						System.out.println(n+",");
//					}
//					return result;
//				}
//			}
//			
//		}
//    	return null;
//    }
//}

class Solution {
    public int[] twoSum(int[] nums, int target) {
        for(int i = 0; i < nums.length; i++)
        {
        	for(int j = i + 1; j < nums.length; j++)
        	{
        		if(nums[i] + nums[j] == target)
        		{
        			int[] result = new int[2];
        			result[0] = i;
        			result[1] = j;
        			System.out.println(result[0] +"----" + result[1]);
        			return result;
        		}
        	}
        }
        
        return null;
    }
}