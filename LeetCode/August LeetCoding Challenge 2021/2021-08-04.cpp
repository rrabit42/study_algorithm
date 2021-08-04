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
