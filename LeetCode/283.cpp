// && nums[slow]==0 is useless
class Solution_0 {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0, fast = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[fast]!=0 && nums[slow]==0)
            {
                swap(nums[fast], nums[slow]);
                slow++;
            }
            fast++;
        }
    }
};