class Solution:
    def minimumOperations(self, nums: List[int], start: int, goal: int) -> int:
        st = {}
        q = deque([(start, 0)])
        st[start] = 1
        while q:
            x, t = q.popleft()
            if x == goal:
                return t
            if x > 1000 or x < 0:
                continue
            for i in range(len(nums)):
                if x + nums[i] not in st:
                    q.append((x + nums[i], t + 1))
                    st[x + nums[i]] = 1
                if x - nums[i] not in st:
                    q.append((x - nums[i], t + 1))
                    st[x - nums[i]] = 1
                if x ^ nums[i] not in st:
                    q.append((x ^ nums[i], t + 1))
                    st[x ^ nums[i]] = 1
        return -1

