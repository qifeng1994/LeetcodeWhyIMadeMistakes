//nums=[], target=0
class Solution_0 {
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

class Solution_1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = LeftBound(nums,target);
        int right = LeftBound(nums,target+1)-1;

        //why must be if(left<nums.size() && nums[left]==target) ???
        if(nums[left]==target && left<nums.size() )       
            return {left,right};
        else
            return {-1,-1};
    }

    int LeftBound(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size()-1;
        while(left<=right)
        {
            int middle = left+(right-left)/2;
            if(nums[middle] < target)           
                left = middle+1;
            else
                right = middle-1;
        }
        return left;
    }
};