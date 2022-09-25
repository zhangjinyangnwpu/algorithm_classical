#include<iostream>
#include<vector>
using namespace std;

bool binary_search(vector<int>& nums,int key){
    int left = 0, right = nums.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(nums[mid]==key){
            cout << "find " << key << " at " << mid << endl;
            return true;
        }
        else if(nums[mid] > key){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return false;
}

int main(){
    vector<int> nums = {2,4,1,5,61000,-9,7,8,8,7,3,9,0};
    sort(nums.begin(), nums.end());
    for(auto num:nums)
        cout << num << " ";
    cout << endl;
    auto res = binary_search(nums, 8);
    cout << res << endl;
    return 0;
}
