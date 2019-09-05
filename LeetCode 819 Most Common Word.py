# LeetCode 819 Most Common Word.py
# Environment: Python3

class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        words = re.findall(r'\w+', paragraph.lower())
        permitted = [w for w in words if w not in banned]
        return collections.Counter(permitted).most_common(1)[0][0]