// LeetCode 56 Merge Intervals.cpp

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [] (Interval &a, Interval &b) { return a.start < b.start; });
        
        vector<Interval> ans;
        for (Interval &itv : intervals) {
            if (!ans.empty() && itv.start <= ans.back().end) {
                ans.back().end = max(itv.end, ans.back().end);
            } else {
                ans.push_back(itv);
            }
        }
        return ans;
    }
};