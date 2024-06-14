class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        st = {}
        q = deque()
        for a in nums:
            if a not in st:
                st[a] = 1
            else:
                st[a] += 1
        res = 0
        for i in range(200005):
            if i not in st:
                if len(q):
                    res += i-q[0]
                    # print(res, i, q[0])
                    q.popleft()     
            while i in st and st[i] > 1:
               q.append(i)
               st[i] -= 1

        return res
            