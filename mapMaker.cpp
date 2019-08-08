#include<iostream>
#include<algorithm>
#include<vector>
#define REP(i, n) for(i = 0; i < n; i++)
using namespace std;
struct Array
{
	string name;
	int B, D, size;
	vector<int> lb, ub;
	vector<int> constant;
	int value;
};
int main()
{
	int N, R;
	cin>>N;
	cin>>R;
	Array* array = new Array[N];
	int i, j, k;
	REP(i, N)
	{
		cin>>array[i].name;
		cin>>array[i].B;
		cin>>array[i].size;
		cin>>array[i].D;
		REP(j, array[i].D)
		{
			int lbound, ubound;
			cin>>lbound;
			cin>>ubound;
			array[i].lb.push_back(lbound);
			array[i].ub.push_back(ubound);
		}
	}
	REP(i, N)
	{
		array[i].constant.push_back(array[i].size);
		REP(j, array[i].D - 1)
		{
			int c;
			int s = array[i].D - 1 - j;
			//cout<<"Here!"<<endl;
			c = (array[i].constant.back()) * (array[i].ub[s] - array[i].lb[s] + 1);
			//cout<<array[i].constant.back()<<endl;
			array[i].constant.push_back(c);
		}
		std::reverse(array[i].constant.begin(), array[i].constant.end());
		int c = array[i].B;
		REP(k, array[i].D)
		{
			//cout<<"Here!"<<endl;
			//cout<<array[i].constant[k]<<"   "<<array[i].lb[k]<<endl;
			c -= (array[i].constant[k] * array[i].lb[k]);
			//cout<<c<<endl; 
		}
		array[i].constant.insert(array[i].constant.begin(), c);
	}
	typedef pair<string, int> values;
	vector<values> v;
	/*REP(i, array[1].constant.size())
		cout<<array[1].constant[i]<<endl;*/
	int reference[R][100];
	REP(i, R)
	{
		string array_name;
		cin>>array_name;
		//cout<<array_name;
		REP(j, N)
		{
			if(array_name == array[j].name)
			{
				REP(k, array[j].D)
				{
					int r;
					cin>>r;
					reference[i][k] = r;
				}
				/*REP(k, array[j].D)
					cout<<reference[i][k]<<endl;*/
				int value = array[j].constant[0];
				REP(k, array[j].D)
				{
					value += (array[j].constant[k + 1] * reference[i][k]);
				}
				//cout<<array[j].name<<" "<<value<<endl;
				values a = make_pair(array[j].name, value);
				v.push_back(a);
			}
		}
	}
	/*REP(i, N)
	{
		cout<<array[i].name<<endl;
		REP(j, array[i].constant.size())
			cout<<array[i].constant[j]<<endl;
	}*/
	REP(i, R)
	{
		cout<<((string)v[i].first).c_str();
		cout<<"[";
		REP(k, N)
		{
			if(array[k].name == ((string)v[i].first).c_str())
			{
				REP(j, array[k].D - 1)
					cout<<reference[i][j]<<", ";
				cout<<reference[i][array[k].D - 1]<<"]"<<" = "<<v[i].second<<endl;
			}
		}
	}
	return 0;
}