/**
  * We are given head, the head node of a linked list containing unique
  * integer values. We are also given the list G, a subset of the values
  * in the linked list. Return the number of connected components in G,
  * where two values are connected if they appear consecutively in the linked list.
  */
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    static int numComponents(ListNode* head, vector<int>& G) {
		vector<int>::iterator it = G.begin();
		int num_cpnts = 0;	//number of connected components
		bool pre_result = false;	//indicate previous compare result.

		while(head) {
			if (*it == head->val) {
				it++;
				pre_result = true;
			} else {
				num_cpnts = (pre_result == true) ? ++num_cpnts : num_cpnts;
				pre_result = false;
			}
			head = head->next;
		}
		num_cpnts = (pre_result == true) ? ++num_cpnts : num_cpnts;
		return num_cpnts;
    }

    static int numComponents_unordered_set(ListNode* head, vector<int>& G) {
		unordered_set<int> setG(G.begin(), G.end());
		int num_cpnts = 0;
		while(head) {
			if (setG.count(head->val) &&
				(!head->next || setG.count(head->next->val)))
			num_cpnts++;
			head = head->next;
		}
		return num_cpnts;
    }
};


void printList(struct ListNode* head)
{
    while(head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {

	int G[] = {4, 3, 1, 0, 6};
	//int G[] = {0, 6};
	vector<int> vG(G, G + sizeof(G)/sizeof(G[0]));
	sort(vG.begin(), vG.end());
	for (vector<int>::iterator it = vG.begin(); it != vG.end(); ++it)
		cout << *it << " ";
	cout << endl;
	int i;
	struct ListNode *tmp[7];	// a array of pointer to int.
	for (i = 0; i < 7; i++) {	// assume list already sorted.
		tmp[i] = new ListNode(i);
		if (i > 0) tmp[i-1]->next = tmp[i];
	}
	printList(tmp[0]);

	int num_cpnts = Solution::numComponents(tmp[0], vG);
	int num_cpnts2 = Solution::numComponents_unordered_set(tmp[0], vG);

	cout << "Components : " << num_cpnts << endl;
	cout << "Components : " << num_cpnts2 << endl;


	return 0;
}
