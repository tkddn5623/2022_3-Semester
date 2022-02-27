#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int isFail(list<int>* plist, int c, int K, int T);
int main()
{
	list<int> basket;
	int N, K, A;
	int T;
	int count = 0;

	cin >> N >> K >> T;
	for (int i = 0; i < N; i++) {
		cin >> A;
		if (A > 0)
			basket.push_front(A);
	}
	//sort(basket.begin(), basket.end());
	basket.sort();

	for (int i = 0; i < 2 * N; i++) {
		if (basket.size() == 0) {
			printf("YES");
			break;
		}
		/*if (basket.len == 1) {
			printf("NO");
			break;
		}*/
		if (basket.size() == 1 || isFail(&basket, count, K, T)) {
			printf("NO");
			break;
		}
		if (basket.front() < K - basket.back()) {
			count += basket.front();
			basket.back() = basket.front() + basket.back();
			basket.pop_front();
		}
		else {
			count += K - basket.back();
			*(basket.begin()) = basket.front() - (K - basket.back());
			*(basket.rbegin()) = K;
			basket.pop_back();
			if (basket.front() == 0) {
				basket.pop_front();
			}
		}
	}

}
int isFail(list<int>* plist, int c, int K, int T)
{
	int smaller = plist->front() <= K - plist->back() ? plist->front() : K - plist->back();
	if (smaller > T - c || T - c <= 0)
		return 1;
	else
		return 0;
}