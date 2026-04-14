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
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        // cout << n << endl;
        if(n<3){
            return -1;
        }
        int low = 0;
        int high = n-1;
        int index=-1;
        while(low < high){
            int mid = low + (high-low)/2;
            int ele = mountainArr.get(mid);
            int ele1 = mountainArr.get(mid+1);
            if(ele < ele1){
               low = mid+1;
            }
            else{
                high = mid;
            }
        }
        index = low;
        // cout << index << endl;
        low = 0;
        high = index;
        while(low <= high){
            int mid = low + (high-low)/2;
            int ele = mountainArr.get(mid);
            if(ele == target){
                return mid;
            }
            else if(target > ele){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        low = index;
        high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            int ele = mountainArr.get(mid);
            if(ele == target){
                return mid;
            }
            else if(target > ele){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return -1;
    }
};