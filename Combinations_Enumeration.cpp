#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 示例数组改为 {3, 1, 4, 1, 5}
    vector<int> arr = {3, 1, 4, 1, 5};
    // m 修改为数组长度
    int m = arr.size();
    // 组合中选取的元素个数 n 保持不变，此处设为3
    int n = 3;
    
    // 存储组合中元素的索引
    vector<int> indices(n);
    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }
    
    while (true) {
        // 输出当前组合
        for (int i = 0; i < n; i++) {
            cout << arr[indices[i]] << " ";
        }
        cout << endl;
        
        // 从后向前寻找可以递增的索引位置
        int pos = n - 1;
        while (pos >= 0 && indices[pos] == m - n + pos) {
            pos--;
        }
        
        // 如果所有位置都无法递增，则组合枚举结束
        if (pos < 0) break;
        
        // 增加该位置的索引，并更新后续位置
        indices[pos]++;
        for (int i = pos + 1; i < n; i++) {
            indices[i] = indices[i - 1] + 1;
        }
    }
    
    return 0;
}
