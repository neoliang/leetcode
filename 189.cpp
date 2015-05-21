class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k = k % n;
        if (k==0){
            return;
        }
        int* temp = new int [n];
        int ti = 0;
        for(int i = n-k;i<n;++i)
        {
            temp[ti++]=nums[i];
        }
        for(int i =0 ;i< n-k;++i)
        {
            temp[ti++] = nums[i];
        }
        for (int i=0; i<n; ++i) {
            nums[i] = temp[i];
        }
        delete [] temp;
    }
};
