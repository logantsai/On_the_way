#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static vector<ListNode*> splitListToParts(ListNode* root, int k) {
		int length = 0;

		for (ListNode *ptr = root; ptr != nullptr; ptr = ptr->next)
			length++;
		cout << "Element number " << length << endl;

		/* legnth < k */
		if (length < k) {
			int i;
			cout << "Element number smaller than group " << k << endl;
			vector<ListNode*> retAry(k, nullptr);
			for (i = 0; i < k; i++) {
				retAry[i] = root ? root : nullptr;
				if (root) {
					root = root->next;
					retAry[i]->next = nullptr;
				}
			}

			return retAry;
		}

		/* 2. length > k */
		int Remainder = length % k;
		int Quotient = length / k;
		vector<ListNode*> retAry(k, nullptr);
		cout << "R : " << Remainder << endl;
		cout << "Q : " << Quotient << endl;

		int j;
		int Group = 0;
		ListNode *dummy;

		while (root) {
			retAry[Group++] = root;
			for (j = 1; j < Quotient; j++)
				root = root->next;

			if (Remainder > 0) {
				root = root->next;
				Remainder--;
			}
			dummy = root;
			root = root->next;
			dummy->next = nullptr;
		}
		return retAry;
    }

	static vector<ListNode*> splitListToParts_leetcode(ListNode* root, int k) {
		int length = 0;

		for (ListNode *ptr = root; ptr != nullptr; ptr = ptr->next)
			length++;

		int R = length % k;
		int Q = length / k;
		vector<ListNode*> retAry(k, nullptr);

		cout << "R : " << R << endl;
		cout << "Q : " << Q << endl;

		int i = 0;
		int j = 0;
		ListNode *cur = root;
		ListNode *pre;

		for (i = 0; cur && i < k; i++, R--) {
			retAry[i] = cur;
			for (j = 0; j < Q + (R > 0); j++) {
				pre = cur;
				cur = cur->next;
			}
			pre->next = nullptr;
		}

		return retAry;
	}
};

void printList(struct ListNode* head)
{
	for (; head != nullptr; head = head->next)
        cout << head->val << "->";

    cout << "NULL\n";
}

#define self 0
int main()
{

	int i;
	struct ListNode *tmp[11];	// a array of pointer to int.
	for (i = 0; i < 11; i++) {	// assume list already sorted.
		tmp[i] = new ListNode(i);
		if (i > 0) tmp[i-1]->next = tmp[i];
	}
	printList(tmp[0]);
#if self
	vector<ListNode*> ary = Solution::splitListToParts(tmp[0], 15);
#else
	vector<ListNode*> ary = Solution::splitListToParts_leetcode(tmp[0], 3);
#endif

	ListNode *Group;
	for (vector<ListNode*>::iterator it = ary.begin(); it != ary.end(); ++it) {
		if (*it == nullptr) {
			cout << "null" << endl; continue;
		}
		for (Group = *it; Group != nullptr; Group =  Group->next)
			cout << Group->val << " ";
		cout << endl;
	}

	return 0;
}
