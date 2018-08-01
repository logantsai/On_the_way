#include <iostream>
#include <queue>
using namespace std;

class MovingAverage {
	public:
		MovingAverage(int size) {
			this->window_size = size;
			sum = 0;
		}

		int next(int n) {
			if (q.size() >= window_size) {
				sum = sum - q.front();
				q.pop();
			}
			q.push(n);
			sum += n;
			return sum / q.size();
		}
	private:
		queue<int> q;
		int window_size;
		int sum;
};

int main()
{

	MovingAverage ma = MovingAverage(3);

	cout << ma.next(1) << endl;
	cout << ma.next(10) << endl;
	cout << ma.next(3) << endl;
	cout << ma.next(5) << endl;

	return 0;
}
