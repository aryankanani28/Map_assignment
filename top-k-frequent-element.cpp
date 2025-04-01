class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num: nums) {
            freq[num]++;
        }
        vector<pair<int, int>>elements(freq.begin(),freq.end());
        sort(elements.begin(),elements.end(),[](auto &a,auto &b) {
            return a.second > b.second;
        });

        vector<int>result;
        for (int i =0; i<k; i++) {
            result.push_back(elements[i].first);
        }
        return result;
    }
};
