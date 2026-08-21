class Solution {
    public boolean hasDuplicate(int[] nums) {
        HashSet<Integer> map = new HashSet<>();
        for(Integer num:nums){
            if(map.contains(num)) return true;
            map.add(num);
        }
        return false;
    }
}