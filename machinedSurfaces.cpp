#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
#define rep(i, n) for(i = 0; i < n; i++)
int main()
{
	int N;
	while(1)
	{
		//cout<<"ACCepting!"<<endl;
		cin>>N;
		if(N != 0)
		{
			cin>>ws; // stream out any whitespace
			int i,j;
			string s;
			vector<string> r;
			rep(i, N)
			{
				//cout<<"Here!"<<endl;
				getline(cin, s);
				r.push_back(s);
			}
			vector<int> count;
			int bCount;
			for(vector<string>::iterator it = r.begin(); it != r.end(); it++)
			{
				bCount = 0;
				rep(j, 25)
				{
					//cout<<(*it)[j]<<endl;
					if((*it)[j] == ' ')
						bCount++;
				}/*cout<<"Here!"<<endl;
				cout<<bCount<<endl;*/
				count.push_back(bCount);
			}
			int minimum = count[0];
			rep(i, N)
			{
				if(count[i] < minimum)
					minimum = count[i];
			}
			rep(i, N)
				count[i] -= minimum;
			int total = 0;
			rep(i, N)
				total += count[i];
			cout<<total<<endl;
			// rep(i, N)
			// 	cout<<count[i]<<endl;
			/*rep(i, N)
				cout<<r[i]<<endl;*/
		}
		else
			return 0;
	}
}