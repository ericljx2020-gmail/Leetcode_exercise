/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int target;
    int findInMountainArray(int _target, MountainArray & a) {
        target = _target;
        int n = a.length();
        int l = 0, r = n-1;
        while (l < r) {
            int mid = l + r >> 1;
            int x = a.get(mid);
            int y = a.get(mid+1);
            if (y > x){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        
        int xx = find1(0, r, a);
        if (a.get(xx) == target) return xx;

        xx = find2(r, n-1, a);
        if (a.get(xx) == target) return xx;

        return -1;
    
    }

    int find1(int l, int r, MountainArray & a){
        while (l < r){
            int mid = l + r + 1 >> 1;
            if (a.get(mid) <= target){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        return r;
    }

    int find2(int l, int r, MountainArray & a){
        while (l < r){
            int mid = l + r + 1 >> 1;
            if (a.get(mid) >= target){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        return r;
    }
};