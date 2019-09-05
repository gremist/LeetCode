// LeetCode 171 Excel Sheet Column Number.cs

public class Solution {
    public int TitleToNumber(string s) {
        int ans = 0;
        foreach (char ch in s) {
            ans = 26 * ans + ch - 'A' + 1;
        }
        return ans;
    }
}