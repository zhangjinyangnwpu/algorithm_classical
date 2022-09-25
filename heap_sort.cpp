#include<iostream>
#include<vector>
using namespace std;
void heapify(vector<int>& nums,int N, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = left + 1;
    if(left < N && nums[left] > nums[largest]){
        largest = left;
    }
    if(right < N && nums[right]>nums[largest]){
        largest = right;
    }
    if(largest != i){
        swap(nums[i], nums[largest]);
        heapify(nums, N, largest);
    }
}
void heap_sort(vector<int> &nums){
    int n = nums.size();
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(nums,n, i);
    }
    for (int i = n - 1; i >= 0; i--){
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }
}
int main(){
    vector<int> nums = {2,4,1,5,61000,-9,7,8,7,3,9,0};
    heap_sort(nums);
    for(auto num:nums){
        cout << num << " ";
    }
    return 0;
}
