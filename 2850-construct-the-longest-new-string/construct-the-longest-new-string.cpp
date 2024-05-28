class Solution {
public:
    int mem[55][55][55];
    int longestString(int x, int y, int z) {
        //这里是假装前面有一个AA或者BB，这样就可以包含0-2个字符为BB ｜ AB ｜ AA的三种情况了
        memset(mem, -1, sizeof mem);
        return max(dfs(x,y,z,0), dfs(x,y,z,1));
    }

    int dfs(int x, int y, int z, int k){
        if (mem[x][y][z] != -1) return mem[x][y][z];
        if (k == 0){
            //如果上一个是AA只能接BB
            if (y){
                return dfs(x,y-1,z,1)+2;
            }else{
                return 0;
            }
        }
        int res1 = 0, res2 = 0;
        //这里是指前面是BB | AB的情况，后面都可以接AB or AA所以求一个最大值
        if (x){
            res1 = dfs(x-1,y,z,0) + 2;
        }
        if (z){
            res2 = dfs(x,y,z-1,2) + 2;
        }
        mem[x][y][z] = max(res1, res2);
        return max(res1, res2);
    }
};
//AA -> BB
//BB -> AB | AA
//AB -> AA | AB