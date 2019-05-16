"""
884. Uncommon Words from Two Sentences
"""

class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        wordcount = {}
        for word in A.split():
            wordcount[word] = wordcount.get(word, 0) + 1
        for word in B.split():
            wordcount[word] = wordcount.get(word, 0) + 1
        uncommon_words = []
        for key in wordcount.keys():
            if wordcount.get(key) == 1:
                uncommon_words.append(key)
                
        return uncommon_words
