// static 이어야해서
bool compare(const pair<int, int> &a, const pair<int, int> &b){
    return a.second < b.second;
}

class Solution {
public:
    // !!주어진 인덱스대로 줘야함!!
    vector<int> twoSum(vector<int>& nums, int target) {
        // first: index, second; value
        vector<pair<int,int>> nums_pair;
        for(int i=0; i<nums.size(); i++){
            nums_pair.push_back(make_pair(i, nums[i]));
        }
        
        sort(nums_pair.begin(), nums_pair.end(), compare);
        
        // 와 양수만 있는줄....
        // // value 이전인 index만 검색
        // int start_idx = -1;
        // for(int i=nums_pair.size()-1; i>=0; i--){
        //     if(target >= nums_pair[i].second){
        //         start_idx = i;
        //         break;
        //     }
        // }
        
        // 그 중에서 target 구해서 뺀거 find 하기
        vector<int> result;
        // for(int i=start_idx; i>=1; i--){
        for(int i=nums_pair.size()-1; i>=1; i--){
            int left = target - nums_pair[i].second;
            
            // 밑에거 중에서 찾으면 좋겠는데 함수가..없다.. for 돌릴까...
            if(left < nums_pair[0].second) continue; // 있으면 안됨
            int left_idx = find(nums.begin(), nums.end(), left) - nums.begin();
            // int left_idx = find(nums_pair.begin(), nums_pair[i], left) - nums.begin();
            
            if(left_idx < nums.size()){
                result.push_back(nums_pair[i].first);
                result.push_back(left_idx);
                break;
            }
        }
        
        return result;
    }
};
