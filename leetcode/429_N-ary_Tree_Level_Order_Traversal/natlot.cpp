#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> result;
        if (!root) return result;
        while (!q.empty()) {
            int cur_sizeof_q = q.size();
            vector<int> tempV;

            for (int i = 0; i < cur_sizeof_q; ++i) {
                Node *tmpN = q.front();
#if 0
                int child_num = tmpN->children.size();

                for (int j = 0; j < child_num; ++j) {
                    q.push(tmpN->children[j]);
                }
#else
                vector<Node*> io = tmpN->children;
                for (vector<Node*>::iterator iv=io.begin(); iv!=io.end(); ++iv) {
                    q.push(*iv);
                }
#endif
                q.pop();
                tempV.push_back(tmpN->val);
            }
            result.push_back(tempV);
        }
        return result;
    }
};


int main()
{

    vector<vector<int>> vv;
    vector<Node*> v_empty;
    Node *five = new Node(5, v_empty);
    Node *six = new Node(6, v_empty);
    Node *three = new Node(3, {five, six});

    Node *two = new Node(2, v_empty);
    Node *four = new Node(4, v_empty);
    Node *one = new Node(1, {three, two, four});

    Solution s;
    vv = s.levelOrder(one);

    for (auto a : vv) {
        vector<int> tmpV = a;
        for (auto b : tmpV) {
            cout << b << " ";
        }
        cout << endl;
    }

    return 0;
}
