class Solution:
    def countSegments(self, s: str) -> int:
        ll = s.split(" ")
        while '' in ll:
            ll.remove('')
        return len(ll)