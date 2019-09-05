// LeetCode 168 Excel Sheet Column Title.cs

public class Solution {
    public string ConvertToTitle(int n) {
        string ans = string.Empty;
        while (n > 0) {
            ans = (char)('A' + (n - 1) % 26) + ans;
            n = (n - 1) / 26;
        }
        return ans;
    }
}