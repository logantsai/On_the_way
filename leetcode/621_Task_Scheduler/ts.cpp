#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static int leastInterval(vector<char>& tasks, int n) {
		vector<int> cnt(26, 0);
		for (char task : tasks)
			cnt[task - 'a']++;
		int len = tasks.size();
		sort(cnt.begin(), cnt.end());

		int i = 0;
		for (int val : cnt) {
			if (val == cnt[25]) ++i;
		}
		cout << "Max have: " << i << endl;

		return max(len, (n + 1) * (cnt[25] - 1) + i);
    }
};

int main()
{
	char tmp[] = {'a', 'a', 'a', 'b', 'b', 'c'};
	vector<char> tasks(tmp, tmp + sizeof(tmp) / sizeof(char));
	cout << "tasks size: " << tasks.size() << endl;
	int ret = Solution::leastInterval(tasks, 2);
	cout << "leastInterval: " << ret << endl;
	return 0;
}
