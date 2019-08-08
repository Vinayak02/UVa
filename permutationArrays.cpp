#include<bits/stdc++.h>
using namespace std;
#define rep(i, j) for(i = 0; i < j; i++)
vector<int> extractNumbers_int(string s, vector<int> index)
{
	stringstream ss;
	ss<<s; // storing the whole string into stringstream
	string temp;
	int found;
	while(!ss.eof())
	{
		ss>>temp; //extracting word by word from stringstream
		if(stringstream(temp) >> found) // checking the given word is int
			index.push_back(found);
		temp = "";
	}
	return index;
}
vector<float> extractNumbers_float(string s, vector<float> number)
{
	stringstream ss;
	ss<<s;
	float found;
	string temp;
	while(!ss.eof())
	{
		//cout<<"indi"<<endl;
		ss>>temp;
		if(stringstream(temp) >> found)
			number.push_back(found);
		temp = "";
	}
	return number;
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		string ind, num;
		int i;
		cout<<endl;
		cin>>ws;
		getline(cin, ind);
		cin>>ws;
		getline(cin, num);
		vector<int> index;
		vector<float> number;
		index = extractNumbers_int(ind, index);
		number = extractNumbers_float(num, number);
		// rep(i, index.size())
		// 	cout<<index[i]<<endl;
		// cout<<endl;
		// rep(i, number.size())
		// 	cout<<number[i]<<endl;
		typedef pair<int, float> arr;
		arr a;
		vector<arr> arrangement;
		rep(i, index.size())
		{
			a = make_pair(index[i], number[i]);
			arrangement.push_back(a);
		}
		sort(arrangement.begin(), arrangement.end());
		rep(i, arrangement.size())
			printf("%f\n", arrangement[i].second);
	}
}