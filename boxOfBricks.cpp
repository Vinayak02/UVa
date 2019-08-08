#include<bits/stdc++.h>
using namespace std;
#define rep(i, j) for(i = 0; i < j; i++)
int main()
{
	int count = 1;
	while(1)
	{
		int n;
		cin>>n;
		if(n != 0)
		{
			int i, h, total = 0;
			vector<int> bricks;
			rep(i, n)
			{
				cin>>h;
				bricks.push_back(h);
				total += h;
			}
			int ideal = total / n;
			int moves = 0;
			vector<int>::iterator lower, it;
			sort(bricks.begin(), bricks.end());
			lower = lower_bound(bricks.begin(), bricks.end(), ideal);
			for(it = bricks.begin(); it != lower; it++)
			{
				// cout<<*it<<endl;
				int diff = ideal - *it;
				moves += diff;
			}
			cout<<"Set #"<<count++<<endl;
			cout<<"The minimum number of moves is "<<moves<<"."<<endl<<endl;
		}
		else
			break;
	}
	return 0;
}