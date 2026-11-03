class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        for (int i = 0; i < nums.size(); i++) {
            hashmap[nums[i]]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& p : hashmap) {
            buckets[p.second].push_back(p.first);
        }

        vector<int> result;
        for (int freq = nums.size(); freq >= 0 && result.size() < k; freq--) {
            for (int num : buckets[freq]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }
        return result;
    }
};
