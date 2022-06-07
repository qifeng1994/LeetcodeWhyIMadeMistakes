//there is smthing wrong in max_element
class Solution_0 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int slow = 0, fast = 0, count = 0, sum = 0;
        vector<int>answer;
        while(fast < nums.size())
        {
            if(sum < target)
            {
                sum += nums[fast];
                fast++;
                count++;
            }
            else
            {
                answer.push_back(count);
                sum -= nums[slow];
                slow++;
                count--;
            }
        }

        if(sum >= target) answer.push_back(count);

        if(answer.empty()) 
        {
            return 0;
        }
        else
        {
            
            return max_element(answer.begin(),answer.end());
        } 

    }
};

//correct solution, no sure the for loop 
class Solution_1 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int slow = 0, count = nums.size()+1, sum = 0;
        for(int& fast : nums)
        {
            sum += fast;
            while(sum >= target)
            {              
                count = min(count, (int)(&fast - &nums[slow])+1);
                target += nums[slow];
                slow++;
            }
        }
        return count% (nums.size()+1);
    }
};