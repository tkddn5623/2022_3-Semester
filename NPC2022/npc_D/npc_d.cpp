#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	multiset<char> Set;
	multiset<char> Set2;
	string String;
	int m = 1, m0 = 0;
	while (1) {
		cin >> m;
		m0 = 0;
		if (m == 0)
			return 0;
		cin.ignore();
		getline(cin, String);
		for (auto x : String)
			Set.erase(x);
		//Set = Set2;
		//cout << "str is:" << String << endl;
		//for (auto x : String) 
		//	Set.insert(x);
		//cout << Set.count('a') << endl; 

		//Above the input part.
		int start = 0, end = -1; //In fact 2 pointers
		int max = 0;
		int temp = 0;

		//Set.insert(String.front());
		while (end + 1 < String.length()) {
			while (m0 <= m && end + 1 < String.length()) {
				if (Set.count(String.at(end + 1)) == 0) { //If element DOES NOT exist
					if (m0 == m)
						break;
					else {
						m0++;
					}
				}
				end++;
				Set.insert(String.at(end));

			}
			if (end - start + 1 > max) {
				max = end - start + 1;
			}
			while (m0 >= m && end + 1 < String.length()) {
				//Set.erase(String.at(start));
				temp = Set.count(String.at(start)); //e.g.3
				Set.erase(String.at(start));
				for (int i = 0; i < temp - 1; i++) {
					Set.insert(String.at(start));
				}
				if (temp == 0) {
					m0--;
				}
				start++;
			}
		}
		cout << max << endl;


	}
}
