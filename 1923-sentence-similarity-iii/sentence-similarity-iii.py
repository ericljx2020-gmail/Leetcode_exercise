class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        l1 = sentence1.split(" ")
        l2 = sentence2.split(" ")
        # l1 is longer than l2
        if len(l1) < len(l2): l1, l2 = l2, l1
        
        # match front
        idx = 0
        for i in range(len(l1)):
            if idx < len(l2) and l1[i] == l2[idx]:
                idx += 1
            else:
                break
        # print('1'+str(idx))
        if idx == len(l2): return True

        # match back
        idx = len(l2)-1
        for i in range(len(l1)-1, -1, -1):
            if idx < len(l2) and l1[i] == l2[idx]:
                idx -= 1
            else:
                break
        # print('2'+str(idx))
        if idx == -1: return True

        # match middle
        idx = 0
        for i in range(len(l1)):
            if idx < len(l2) and l1[i] == l2[idx]:
                idx += 1
            else:
                break
        
        a = len(l1)-(len(l2)-idx)
        # print(a)
        for i in range(a, len(l1)):
            if idx < len(l2) and l1[i] == l2[idx]:
                idx += 1
            else:
                break
        # print('3'+str(idx))
        if idx == len(l2): return True

        return False