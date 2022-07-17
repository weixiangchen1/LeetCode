class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * 
     * @param nums int����vector 
     * @param target int���� 
     * @return int����
     */
    int search(vector<int>& nums, int target) {
        // write code here
        int left = 0;
        int right = nums.size()-1;
        
        if(nums.size() == 0)
        {
            return -1;
        }
        
        while(left <= right)
        {
            int mid = (left + right) / 2;
            
            if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
            
        }
        
        return -1;
        
    }
};
