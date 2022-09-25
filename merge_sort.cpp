#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& nums,int left,int mid,int right){
    auto sub_one = mid - left + 1;
    auto sub_two = right - mid;
    vector<int> left_array(sub_one);
    vector<int> right_array(sub_two);
    for (int i = 0; i < sub_one; i++){
        left_array[i] = nums[left + i];
    }
    for (int i = 0; i < sub_two;i++){
        right_array[i] = nums[mid + 1 + i];
    }
    int index_one = 0, index_two = 0;
    int index_merge_array = left;
    while(index_one < sub_one && index_two <sub_two){
        if(left_array[index_one]< right_array[index_two]){
            nums[index_merge_array] = left_array[index_one];
            index_one++;
        }
        else{
            nums[index_merge_array] = right_array[index_two];
            index_two++;
        }
        index_merge_array++;
    }
    while(index_one < sub_one){
        nums[index_merge_array++] = left_array[index_one++];
    }
    while(index_two < sub_two){
        nums[index_merge_array++] = right_array[index_two++];
    }
}

void merge_sort(vector<int>& nums,int left,int right){
    if(left >= right)
        return;
    int mid = left + (right - left) / 2;
    merge_sort(nums, left, mid);
    merge_sort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

void merge_sort(vector<int> &nums){
    merge_sort(nums, 0, nums.size() - 1);
}
int main(){
    vector<int> nums = {2,4,1,5,61000,-9,7,8,7,3,9,0};
    merge_sort(nums);
    for(auto num:nums){
        cout << num << " ";
    }
    return 0;
}
