#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <sstream>
/*
 Trần Nhật Quang 20224456
 */
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Hàm tạo cây nhị phân từ đầu vào dưới dạng BFS
TreeNode* buildTree() {
    cout << "Nhập các giá trị nút (dùng -1 cho nút null, cách nhau bởi khoảng trắng): ";
    string input;
    getline(cin, input);
    stringstream ss(input);
    vector<int> values;
    int val;
    while (ss >> val) {
        values.push_back(val);
    }

    if (values.empty() || values[0] == -1) {
        return nullptr;
    }

    // Khởi tạo cây từ giá trị đầu tiên
    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < values.size()) {
        TreeNode* current = q.front();
        q.pop();
        if (i < values.size() && values[i] != -1) {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;
        if (i < values.size() && values[i] != -1) {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Hàm tính tổng dọc của cây nhị phân
vector<int> verticalSum(TreeNode* root) {
    if (!root) return {};
    map<int, int> columnSum;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto [node, col] = q.front();
        q.pop();
        columnSum[col] += node->val;
        if (node->left) q.push({node->left, col - 1});
        if (node->right) q.push({node->right, col + 1});
    }

    vector<int> result;
    for (auto& [col, sum] : columnSum) {
        result.push_back(sum);
    }

    return result;
}

// Hàm hỗ trợ in danh sách kết quả
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

// Hàm chính
int main() {
    TreeNode* root = buildTree();
    vector<int> result = verticalSum(root);
    cout << "Tổng dọc của cây nhị phân là: ";
    printVector(result);

    return 0;
}
