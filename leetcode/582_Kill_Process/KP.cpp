#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
	static vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
		queue<int> q;
		q.push(kill);
		unordered_map< int, vector<int> > m;
		vector<int> del;

		for (int i = 0; i < pid.size(); ++i)
			m[ppid[i]].push_back(pid[i]);

		while (!q.empty()) {
			int tmp = q.front();
			q.pop();
			del.push_back(tmp);
			for (int val : m[tmp]) {
				q.push(val);
			}
		}
		return del;
	}

	static vector<int> killProcess_recu(vector<int>& pid, vector<int>& ppid, int kill) {
		unordered_map< int, vector<int> > m;
		vector<int> del;

		for (int i = 0; i < pid.size(); ++i)
			m[ppid[i]].push_back(pid[i]);

		killchid(m, del, kill);
		return del;
	}

	static void killchid(unordered_map< int, vector<int> >& m , vector<int>& del, int kill) {
		del.push_back(kill);
		for (int val : m[kill])
			killchid(m, del, val);
	}
};

int main()
{
	int pid[] = {1, 3, 10, 5};
	int ppid[] = {3, 0, 5, 3};

	vector<int> v_pid(pid, pid + sizeof(pid)/sizeof(pid[0]));
	vector<int> v_ppid(ppid, ppid + sizeof(ppid)/sizeof(ppid[0]));
	vector<int> ret = Solution::killProcess(v_pid, v_ppid, 5);
	for (int val : ret)
			cout << val << endl;
	return 0;
}
