#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);


#define rep(i, j) for(i = 0; i < j; i++)
// Complete the closestStraightCity function below.
vector<string> closestStraightCity(vector<string> c, vector<int> x, vector<int> y, vector<string> q) 
{
    map<string, int> x_mapper, y_mapper;
    int i, j;
    rep(i, c.size())
    {
        x_mapper[c[i]] = x[i];
        y_mapper[c[i]] = y[i];
    }
    int d, m = 10000;
    rep(i, q.size())
        rep(j, c.size())
            if(x_mapper[q[i]] == x_mapper[c[j]] || y_mapper[q[i]] == y_mapper[c[j]] && q[i] != c[j])
            {
                d = sqrt(pow(x_mapper[q[i]] - x_mapper[c[j]], 2) + pow(y_mapper[q[i]] - y_mapper[c[j]], 2));
                if(d < m)
                {
                    m = d;
                    q[i] = c[j];
                }
            }
    rep(i, q.size())
        cout<<q[i]<<endl;
    return q;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string c_count_temp;
    getline(cin, c_count_temp);

    int c_count = stoi(ltrim(rtrim(c_count_temp)));

    vector<string> c(c_count);

    for (int i = 0; i < c_count; i++) {
        string c_item;
        getline(cin, c_item);

        c[i] = c_item;
    }

    string x_count_temp;
    getline(cin, x_count_temp);

    int x_count = stoi(ltrim(rtrim(x_count_temp)));

    vector<int> x(x_count);

    for (int i = 0; i < x_count; i++) {
        string x_item_temp;
        getline(cin, x_item_temp);

        int x_item = stoi(ltrim(rtrim(x_item_temp)));

        x[i] = x_item;
    }

    string y_count_temp;
    getline(cin, y_count_temp);

    int y_count = stoi(ltrim(rtrim(y_count_temp)));

    vector<int> y(y_count);

    for (int i = 0; i < y_count; i++) {
        string y_item_temp;
        getline(cin, y_item_temp);

        int y_item = stoi(ltrim(rtrim(y_item_temp)));

        y[i] = y_item;
    }

    string q_count_temp;
    getline(cin, q_count_temp);

    int q_count = stoi(ltrim(rtrim(q_count_temp)));

    vector<string> q(q_count);

    for (int i = 0; i < q_count; i++) {
        string q_item;
        getline(cin, q_item);

        q[i] = q_item;
    }

    vector<string> res = closestStraightCity(c, x, y, q);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
