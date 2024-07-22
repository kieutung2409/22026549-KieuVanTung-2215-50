#include <iostream>  
#include <vector>  
#include <algorithm>  
#include <set>  

using namespace std;  

void findTripletsWithZeroSum(const vector<int>& nums) {  
    set<vector<int>> result; // Sử dụng tập hợp để lưu các bộ ba duy nhất  

    for (size_t i = 0; i < nums.size(); i++) {  
        int left = i + 1;  
        int right = nums.size() - 1;  
        
        while (left < right) {  
            int sum = nums[i] + nums[left] + nums[right];  
            if (sum == 0) {  
                result.insert({nums[i], nums[left], nums[right]}); // Thêm bộ ba vào tập hợp  
                left++;  
                right--;  
            } else if (sum < 0) {  
                left++;  
            } else {  
                right--;  
            }  
        }  
    }  

    for (const auto& triplet : result) {  
        for (size_t j = 0; j < triplet.size(); j++) {  
            cout << triplet[j] << (j < triplet.size() - 1 ? " " : "");  
        }  
        cout << endl;  
    }  
}  

int main() {  
    int n;  
    cin >> n;  

    vector<int> nums(n);  
        
    for (int i = 0; i < n; i++) {  
         cin >> nums[i];  
    }  

    sort(nums.begin(), nums.end());
    findTripletsWithZeroSum(nums);  
     
    return 0;  
}