#include <iostream>
#include <map>

using namespace std;


struct RandomListNode {
    int val;
    RandomListNode *next, *random;
    RandomListNode(int x) : val(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    static RandomListNode *copyRandomList(RandomListNode *head) {
		map< RandomListNode*, RandomListNode* > maptable;

		RandomListNode* dummy = new RandomListNode(-1);
		RandomListNode* cur = head;
		RandomListNode* pre = dummy;
		while (cur) {
			pre->next = new RandomListNode(cur->val);
			maptable.insert(pair< RandomListNode*, RandomListNode* >(cur, pre->next));

			pre = pre->next;
			cur = cur->next;
		}

		cur = head;
		pre = dummy->next;
		while (cur && pre) {
			pre->random = maptable[cur->random];
			cur = cur->next;
			pre = pre->next;
		}

		return dummy->next;
    }
};

int main()
{
	RandomListNode *a1 = new RandomListNode(1);
	RandomListNode *a2 = new RandomListNode(2);
	RandomListNode *a3 = new RandomListNode(3);

	a1->next = a2;
	a2->next = a3;
	a1->random = a3;
	a3->random = a2;


	RandomListNode *head = Solution::copyRandomList(a1);
	cout << "node: " << head->val << " random: "<< head->random->val << endl;
	return 0;
}
