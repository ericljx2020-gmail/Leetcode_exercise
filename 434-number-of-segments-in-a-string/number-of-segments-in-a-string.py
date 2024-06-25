class Solution:
    def countSegments(self, s: str) -> int:
        ll = s.split(" ")
        while '' in ll:
            ll.remove('')
            # ll.remove('')
        # print(ll)
        # if not all(ll):
        #     return 0
        return len(ll)