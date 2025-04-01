class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map;
        int longestStreak = 0;

        for (int num : nums) {
            if (map.find(num) == map.end()) {
                int left = (map.find(num -1) != map.end()) ? map[num- 1] : 0;
                int right = (map.find(num+1) != map.end()) ? map[num + 1] : 0;
                int sequenceLength = left+1 + right;

                map[num] = sequenceLength;
                map[num-left] =sequenceLength;
                map[num+right]=sequenceLength;

                longestStreak =max(longestStreak, sequenceLength);
            }
        }

        return longestStreak;
    }
};
