#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 3;  // 设置集合大小为3
    vector<int> arr = {1, 2, 3};  // 示例数组
    // 枚举所有子集，mask 范围是 0 到 (1 << n) - 1
    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<int> subset;
        // 检查 mask 的每一位，选择相应的元素
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subset.push_back(arr[i]);
            }
        }
        // 输出当前子集
        cout << "子集: ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
