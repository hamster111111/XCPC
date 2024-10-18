#include <bits/stdc++.h>

int main()
{
    //求解集合大小为n的幂集
    int n;
    std::cin >> n;
    //存储集合以及集合中每个元素的状态
    std::vector<int> a(n + 1);
    std::vector<bool> state(n + 1);
    for(int i = 1; i <= n; i++) std::cin >> a[i];
    //dfs函数
    auto dfs = [&](auto self, int layer) -> void {
        if (layer == n + 1) {
            //到达n + 1层的时候，我们集合中所有元素的选择状态都处理完了
            std::cout << "{";
            for(int i = 1; i <= n; i++) if (state[i]) std::cout << a[i] << ",";
            std::cout << "}\n";
            return;
        }
        state[layer] = true;//决定选择集合中的这个元素
        self(self, layer + 1);
        state[layer] = false;//决定不选择集合中的这个元素
        self(self, layer + 1);
    };
    dfs(dfs, 1);
    std::next_permutation()
}