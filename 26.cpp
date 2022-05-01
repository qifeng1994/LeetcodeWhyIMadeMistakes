//this is the correct answer but use C++11, so I recorded here
class Solution_0 {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0, save = 0;
        //C++11
        for(int select:nums)
        {
            if(select != nums[save])
            {
                save++;
                nums[save] = select;
            }            
        }
        return save+1;
    }
};