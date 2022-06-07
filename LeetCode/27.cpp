//nums=[],val=0
class Solution_0 {
public:
    int removeElement(vector<int>& nums, int val) {
        
        //save指针指向修改后的数据，select指针指向需要判断的数据
        int* save = &nums[0];
        int* select = &nums[0];
        int count = 0;
        for(select; select<&nums[nums.size()]; select++)
        {
            if(*select != val)
            {
                *save = *select;
                save++;
                count++;
            }
        }
        return count;
    }
};
