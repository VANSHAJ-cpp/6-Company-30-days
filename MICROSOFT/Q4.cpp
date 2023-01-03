// Q 396. Rotate Function (https://leetcode.com/problems/rotate-function/)

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int r0 = 0;
        int max1 = INT_MIN;

        for(int i=0 ; i<n ; i++){
            sum = sum + nums[i];
        }

        for(int i=0 ; i<n ; i++){
            r0 =  r0 + (i*nums[i]);
        }

        int ar[n];
        ar[0] = r0;
        max1 = r0 ;

        for(int i=1 ; i<n ; i++){
          
        /* As F(k) - F(k-1) = summation of array - (n*nums[n-k]) */
          
            ar[i] = ar[i-1] + sum - (n * nums[n-i]);
            max1 = max(max1 , ar[i]);
            
        }

        return max1;

        /*  O(N^2) Approach :- ( WILL GIVE TLE )
        
        int ar[2*n];

        for(int i=0;i<n;i++ ){
            ar[i] = ar[n+i] = nums[i];
        }

        for(int i = 0 ; i < n ; i++ ){
            int a = 0;
            for(int j = i ; j < n+i ; j++){
                sum = sum + ((a) * ar[j]);
                a = a + 1 ;
            }
            max1 = max(max1,sum);
            sum = 0;
        }
        return max1; */

    }
};
