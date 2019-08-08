#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
#include<iostream>
int main()
{
	vector<string> s, command;
	string end = "END";
	string d;
	int sCount = -1, cCount = -1;
	int i = -1;
	do
	{
		getline(cin, d);
		s.push_back(d);
		sCount++;
	}
	while(end.compare(d) != 0);
	s.erase(s.end());
	do
	{
		getline(cin, d);
		if(d.compare("SHELVE") == 0)
			d = "SHELVE Algorithms";
		command.push_back(d);
		cCount++;
	}
	while(end.compare(d) != 0);
	command.erase(command.end());
	typedef pair<pair<string, string>, int> collection;
	collection g;
	vector<collection> c;
	string delimeter = "by";
	//cout<<"sCount : "<<sCount<<endl;
	for(int j = 0; j < sCount; j++)
	{
		g = make_pair(make_pair(s[j].substr(s[j].find(delimeter) + 3, s[j].length()), s[j].substr(0, s[j].find(delimeter) - 1)), j);
		c.push_back(g);
	}
	// for(int j = 0; j < sCount; j++)
	// 	printf("Id: %d, Book: %s, Author: %s\n", c[j].second, ((string)c[j].first.second).c_str(), ((string)c[j].first.first).c_str());
	vector<collection> borrowed, returned;
	int rCount = 0, bC = 0, bc = 0;
	for(int j = 0; j < cCount; j++)
	{
		string com = command[j].substr(0, 6);
		//cout<<com<<endl;
		if(com.compare("SHELVE") != 0)
		{
			string bk = command[j].substr(7, command[j].length());
			if(com.compare("BORROW") == 0)
			{
				bc++;
				//cout<<bc<<endl;
				for(int i = 0; i < sCount; i++)
				{
					bC++;
					string pos = ((string)c[i].first.second).c_str();
					//cout<<pos<<" = " <<bk<<" , "<<pos.compare(bk)<<endl;
					if(pos.compare(bk) < 3 && pos.compare(bk) > -3)
					{
						//cout<<"inside"<<endl;
						borrowed.push_back(c[i]);
						c.erase(find(c.begin(), c.end(), c[i]));
						sCount--;
						break;
					}
				}
				//cout<<*(c.begin() + bC)<<endl;
				// for(int k = 0; k < sCount; k++)
				// 	printf("%s", ((string)c[k].first.second).c_str());
			}
			else if(com.compare("RETURN") == 0)
			{
				for(int i = 0; i < bc; i++)
				{
					//cout<<borrowed[i].first.second.compare(bk)<<endl;
					if(borrowed[i].first.second.compare(bk) < 3 && borrowed[i].first.second.compare(bk) > -3)
					{
						returned.push_back(borrowed[i]);
						borrowed.erase(find(borrowed.begin(), borrowed.end(), borrowed[i]));
						rCount++;
						bc--;
						break;
					}
				}
			}
		}
		else
		{
			if(rCount == 0)
				cout<<"END"<<endl;
			else
			{
				std::sort(returned.begin(), returned.end());
				// for(int k = 0; k < rCount; k++)
				// 	printf("%s\n", ((string)returned[k].first.second).c_str());
				while(rCount != 0)
				{
					//printf("%s\n", ((string)returned[1].first.second).c_str());
					//cout<<rCount<<endl;
					c.push_back(returned[0]);
					sCount++;
					// cout<<sCount<<endl;
					std::sort(c.begin(), c.end());
					// for(int k = 0; k < sCount; k++)
					// 	printf("%s\n", ((string)c[k].first.second).c_str());
					for(int j = 0; j < sCount; j++)
					{
						if(returned[0].first.second.compare(c[j].first.second) < 3 && returned[0].first.second.compare(c[j].first.second) > -3)
						{
							//cout<<returned[0].first.second<<" = "<<c[j].first.second<<" , "<<returned[0].first.second.compare(c[j].first.second)<<endl;
							if(j != 0)
								printf("Put %s after %s\n", ((string)returned[0].first.second).c_str(), ((string)c[j - 1].first.second).c_str());
							else
								printf("Put %s first\n", ((string)c[j].first.second).c_str());
							returned.erase(find(returned.begin(), returned.end(), returned[0]));
							rCount--;
							// for(int k = 0; k < rCount; k++)
							// 	printf("%s\n", ((string)returned[k].first.second).c_str());
						}
					}
				}
				printf("END\n");
			}
		}
	}
	// string s = "The Canterbury Tales by Chaucer, G.";
	// string delimeter = "by";
	// string token = s.substr(s.find(delimeter) + 3, s.length());
	// cout<<token<<endl;
	return 0;
}