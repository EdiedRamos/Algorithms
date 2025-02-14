#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define eps 0.00000000001

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	double vTotal, vInitial, maxCur, curLength;
	int maxLength;
	while (cin >> vTotal >> vInitial && vTotal && vInitial)
	{
		maxCur = 0.0;
		maxLength = 0;
		for (int i = 1; (vTotal / i) > vInitial; i++)
		{
			curLength = 0.3 * sqrt(vTotal / i - vInitial) * i;
			if ((curLength - maxCur) > (abs(curLength) < abs(maxCur) ? abs(maxCur) : abs(curLength) * eps))
			{
				maxCur = curLength;
				maxLength = i;
			}
			else if (abs(curLength - maxCur) < eps)
			{
				maxLength = 0;
			}
		}

		cout << maxLength << endl;
	}
	return 0;
}
