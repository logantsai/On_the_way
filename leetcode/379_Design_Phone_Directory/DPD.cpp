#include <iostream>
#include <vector>
using namespace std;
class PhoneDirectory {
private:
	vector<bool> phoneNumState;	// true means that the number is avaliable
	vector<int> released;
	int cur;
	int max;
	int rel_idx;

public:
	/** Initialize your data structure here
	@param maxNumbers - The maximum numbers that can be stored in the phone directory. */
	PhoneDirectory(int maxNumbers) {
		max = maxNumbers;
		phoneNumState.resize(maxNumbers, true);
		released.resize(maxNumbers);
		cur = rel_idx = 0;
	}

	/** Provide a number which is not assigned to anyone.
	@return - Return an available number. Return -1 if none is available. */
	int get() {
		if (rel_idx <= 0 && cur == max) return -1;
		if (rel_idx > 0) {
			int t = released[--rel_idx];
			phoneNumState[t] = false;
			return t;
		}
		phoneNumState[cur] = false;
		return cur++;
	}

	/** Check if a number is available or not. */
	bool check(int number) {
		return number >= 0 && number < max && phoneNumState[number];
	}

	/** Recycle or release a number. */
	void release(int number) {
		if (phoneNumState[number] == false && number < max && number >= 0) {
			released[rel_idx++] = number;
			phoneNumState[number] = true;
		}
	}
};


int main()
{
	PhoneDirectory obj(10);
	cout << obj.get() << endl;
	cout << obj.get() << endl;
	cout << obj.get() << endl;
	cout << obj.get() << endl;
	cout << obj.get() << endl;
	cout << obj.get() << endl;
	cout << obj.get() << endl;
	cout << obj.get() << endl;
	obj.release(3);
	obj.release(5);
	cout << obj.get() << endl;
	cout << obj.get() << endl;
	return 0;
}









