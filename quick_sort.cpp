#include<iostream>
#include<vector>
using namespace std;
int partation(vector<int>& nums, int left,int right){
    int p = nums[left];
    int count = 0;
    for (int i = left + 1; i <= right;i++){
        if(nums[i]<=p)
            count++;
    }
    int p_index = left + count;
    swap(nums[left], nums[p_index]);
    int i = left, j = right;
    while(i < p_index && j > p_index){
        while(nums[i]<=p)
            i++;
        while(nums[j]>p)
            j--;
        if(i<p_index && j > p_index){
            swap(nums[i++], nums[j--]);
        }
    }
    return p_index;
}
void quick_sort(vector<int>& nums,int left,int right){
    if(left >= right)
        return;
    int pi = partation(nums, left, right);
    quick_sort(nums, left, pi - 1);
    quick_sort(nums, pi + 1, right);
}

void sort(vector<int> &nums){
    quick_sort(nums, 0, nums.size() - 1);
}
int main(){
    vector<int> nums = {2,4,1,5,61000,-9,7,8,7,3,9,0};
    sort(nums);
    for(auto num:nums){
        cout << num << " ";
    }
    return 0;
}
