#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<int> findMinLengthSubarray(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> all_subarrays;

    for (int i = 0; i < n; i++) {
        vector<int> current_subarray;
        for (int j = i; j < n; j++) {
            current_subarray.push_back(arr[j]);
            all_subarrays.push_back(current_subarray);
        }
    }

    vector<pair<vector<int>, int>> valid_pairs;

    for (const auto& sub : all_subarrays) {
        int current_sum = 0;
        for (int x : sub) {
            current_sum += x;
        }

        if (current_sum >= target) {
            valid_pairs.push_back({sub, sub.size()});
        }
    }

    vector<int> result_subarray;
    int min_len = n + 1;

    for (const auto& p : valid_pairs) {
        if (p.second < min_len) {
            min_len = p.second;
            result_subarray = p.first;
        }
    }

    return result_subarray;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int target = 5;
    
    vector<int> result = findMinLengthSubarray(arr, target);
    
    return 0;
}












