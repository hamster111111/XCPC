#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

// 定义节点类，用于表示每个分支
struct Node {
    vector<vector<int>> transport; // 运输矩阵
    vector<int> supplyLeft;        // 剩余供应
    vector<int> demandLeft;        // 剩余需求
    int cost;                      // 当前累计成本

    Node(vector<vector<int>> t, vector<int> s, vector<int> d, int c)
        : transport(t), supplyLeft(s), demandLeft(d), cost(c) {}

    // 重载操作符，用于优先队列按成本升序排序
    bool operator>(const Node &other) const {
        return cost > other.cost;
    }
};

// 全局变量
int m, n; // 产地数量和销地数量
vector<int> supply, demand; // 供应数组和需求数组
vector<vector<int>> cost; // 成本矩阵
vector<vector<int>> solution; // 解决方案矩阵
int minCost = INT_MAX; // 最小成本

// 函数声明
void solveTransportationProblem();
int greedyCost();
bool isComplete(const vector<int>& supplyLeft, const vector<int>& demandLeft);
void printSolution(const vector<vector<int>>& solution);
vector<vector<int>> copyMatrix(const vector<vector<int>>& original);

// 主程序入口
int main() {
    // 示例输入
    m = 3; // 产地数量
    n = 4; // 销地数量
    supply = {7, 4, 9}; // 每个产地的供应量
    demand = {3, 6, 5, 6}; // 每个销地的需求量
    cost = {
        {3, 11, 3, 10},
        {1, 9, 2, 8},
        {7, 4, 10, 5}
    };

    // 初始化解决方案
    solution = vector<vector<int>>(m, vector<int>(n, 0));

    // 开始解决问题
    solveTransportationProblem();

    // 输出解决方案
    cout << "最优运输成本: " << minCost << endl;
    printSolution(solution);

    return 0;
}

// 使用分支与限界法解决运输问题
void solveTransportationProblem() {
    // 使用简单的启发式方法（贪心法）初始化上界成本
    int upperBound = greedyCost();

    // 优先队列处理分支，使用最低成本作为优先级
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    // 创建初始节点（根节点）
    Node root(vector<vector<int>>(m, vector<int>(n, 0)), supply, demand, 0);
    pq.push(root);

    while (!pq.empty()) {
        Node currentNode = pq.top();
        pq.pop();

        if (currentNode.cost >= upperBound) {
            continue; // 剪枝
        }

        if (isComplete(currentNode.supplyLeft, currentNode.demandLeft)) {
            // 更新当前找到的最优解
            if (currentNode.cost < minCost) {
                minCost = currentNode.cost;
                solution = currentNode.transport;
            }
            upperBound = minCost; // 更新上界
            continue;
        }

        // 生成子节点（分支）
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (currentNode.supplyLeft[i] > 0 && currentNode.demandLeft[j] > 0) {
                    // 确定可运输的最大单位数
                    int units = min(currentNode.supplyLeft[i], currentNode.demandLeft[j]);

                    // 创建新的运输计划
                    vector<vector<int>> newTransport = copyMatrix(currentNode.transport);
                    newTransport[i][j] += units;

                    vector<int> newSupply = currentNode.supplyLeft;
                    vector<int> newDemand = currentNode.demandLeft;
                    newSupply[i] -= units;
                    newDemand[j] -= units;

                    int newCost = currentNode.cost + units * cost[i][j];

                    // 创建新节点并添加到队列
                    Node newNode(newTransport, newSupply, newDemand, newCost);
                    pq.push(newNode);
                }
            }
        }
    }
}

// 使用贪心法计算一个上界成本作为启发式方法
int greedyCost() {
    vector<vector<int>> tempSolution(m, vector<int>(n, 0));
    vector<int> tempSupply = supply;
    vector<int> tempDemand = demand;
    int totalCost = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int units = min(tempSupply[i], tempDemand[j]);
            tempSolution[i][j] = units;
            totalCost += units * cost[i][j];
            tempSupply[i] -= units;
            tempDemand[j] -= units;
        }
    }
    return totalCost;
}

// 检查所有的供应和需求是否都已满足
bool isComplete(const vector<int>& supplyLeft, const vector<int>& demandLeft) {
    return all_of(supplyLeft.begin(), supplyLeft.end(), [](int x) { return x == 0; }) &&
           all_of(demandLeft.begin(), demandLeft.end(), [](int x) { return x == 0; });
}

// 实用方法，用于深度复制二维数组
vector<vector<int>> copyMatrix(const vector<vector<int>>& original) {
    vector<vector<int>> copy = original;
    return copy;
}

// 实用方法，用于打印运输矩阵
void printSolution(const vector<vector<int>>& solution) {
    cout << "运输计划:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}