#include <iostream>
#include <vector>
#include <stack>
#include <TreeTools.h>

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
    static vector<int> postorder(Node* root) {
        if (!root) return {};
        stack<Node *> st;
        vector<int> res;
        vector<Node *> empty_v;
        st.push(root);
        while (!st.empty()) {
            Node *tmpNode = st.top();
            if (!tmpNode->children.empty()) {    // 若有children
                for (auto itr = tmpNode->children.rbegin();
                        itr != tmpNode->children.rend(); ++itr) {
                    st.push(*itr);
                }
                tmpNode->children = empty_v;
            } else {
                st.pop();
                res.push_back(tmpNode->val);
            }
        }
        return res;
    }

    vector<int> postorder_GoingMyWay(Node* root) {
        stack<Node*> s; s.push(root);
        vector<int> result;
        while (!s.empty() && root) {
            Node * n = s.top(); s.pop();
            result.insert(result.begin(), n->val);
            for (auto & ch : n->children) s.push(ch);
        }
        return result;
    }
};

int main() {
    vector<Node *> empty_v;
    Node *five = new Node(5, empty_v);
    Node *six = new Node(6, empty_v);

    Node *three = new Node(3, {five, six});
    Node *two = new Node(2, empty_v);
    Node *four = new Node(4, empty_v);
    Node *one = new Node(1, {three, two, four});

    vector<int> res = Solution::postorder(one);
    for (auto a : res)
        cout << a << ' ';
    cout << endl;
    return 0;
}
