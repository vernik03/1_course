#include <string>
#include <math.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	string  input;
	cin >> input;
	//cout << input;	
	vector<int> nums;	
	vector<char> ops;
	while (input.size()>0) {
		/*cout << *input.begin() << " ";*/
		if (isdigit(input[0]))
		{
			int temp = int(input[0] - '0');
			input.erase(input.begin());
			while (isdigit(input[0]))
			{
				temp *= 10;
				temp += int(input[0] - '0');
				input.erase(input.begin());
			}
			nums.push_back(temp);
		}
		else
		{
			ops.push_back(input[0]);
			input.erase(input.begin());
		}		
	}

	while (!ops.empty()) {
		int elem1 = nums.back();
		nums.pop_back();
		int elem2 = nums.back();
		nums.pop_back();
		switch (ops.back()) {
		case '+': {
			elem2 += elem1;
			break;
		}
		case '-': {
			elem2 -= elem1;
			break;
		}
		default: {
			cout << "Error" << endl;
		}
		}
		ops.pop_back();
		nums.push_back(elem2);

	}
	cout << nums.back();
	/*while (!nums.empty())
	{
		cout << nums.back();
		nums.pop_back();
	}
	while (!ops.empty())
	{
		cout << ops.back();
		ops.pop_back();
	}*/


}

