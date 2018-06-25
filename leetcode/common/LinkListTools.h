#define lengthArray(A) (sizeof(A) / sizeof(A[0]))

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(struct ListNode* head);

ListNode* createSequenceList(int start, int length);

ListNode* createListFromIntAarry(int ary[], int length);

ListNode* createListWithZero(int length);
