//nums=[], target=0
class Solution_1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int left=0,right=nums.size()-1;

        if(nums[left]>target || nums[right]<target)
            return {-1,-1};

        while(nums[left]<target)
        {
            left++;
        }

        if(nums[left]>target)
            left=-1;

        while(nums[right]>target)
        {
            right--;
        }

        if(nums[right]<target)
            right=-1;

        if(left == -1 || right == -1)
        {
            return {-1,-1};
        }
        return {left,right};
    }
}