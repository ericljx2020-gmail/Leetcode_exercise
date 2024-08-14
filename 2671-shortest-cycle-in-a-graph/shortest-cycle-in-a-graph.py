from collections import deque, defaultdict

class Solution:
    def __init__(self):
        self.v = []
        self.res = float('inf')
        self.st = {}

    def findShortestCycle(self, n, edges):
        self.v = [[] for _ in range(n)]
        for e in edges:
            self.v[e[0]].append(e[1])
            self.v[e[1]].append(e[0])

        for i in range(n):
            self.st.clear()
            self.bfs(i, -1)
        if self.res == float('inf'):
            return -1
        return self.res

    def bfs(self, t, u):
        self.st[t] = 1
        q = deque()
        q.append((t, u, 1))

        while q:
            cur, f, step = q.popleft()

            for j in self.v[cur]:
                if j == f:
                    continue
                if j in self.st:
                    self.res = min(self.res, step + self.st[j] - 1)
                    continue
                self.st[j] = step + 1
                q.append((j, cur, step + 1))

