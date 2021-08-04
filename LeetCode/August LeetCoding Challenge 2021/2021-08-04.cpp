class Solution {
public:
    vector<vector<int>> result;
    vector<int> subset;
    
    void dfs(vector<int>& nums, int idx){
        if(idx == nums.size())
            return;
        
        subset.push_back(nums[idx]);    // 해당 원소 포함 부분집합
        result.push_back(subset);
        dfs(nums, idx+1);
        
        subset.pop_back();              // 해당 원소 제외 부분집합
        result.push_back(subset);
        dfs(nums, idx+1);
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()), result.end());
        return result;
    }
};

/////////////////////////////////////
// 더 나은 풀이
class Solution {
public:
    vector<vector<int>> result;
    
    void dfs(vector<int>& nums, vector<int> subset){
        result.push_back(subset);
        
        for(int i=0; i<nums.size(); i++){
            if(i > 0 && (nums[i-1] == nums[i]))
                continue;
            subset.push_back(nums[i]);
            vector<int> tmp = vector<int>(nums.begin()+i+1, nums.end());
            dfs(tmp, subset);
            subset.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        dfs(nums, subset);
        
        return result;
    }
};
