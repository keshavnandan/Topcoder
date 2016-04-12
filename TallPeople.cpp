// BEGIN CUT HERE

// END CUT HERE
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class TallPeople
        {
        public:
        vector <int> getPeople(vector <string> people)
            {
                int n = people.size();
                vector<vector<int> > a;
                a.resize(n);
                for(int i = 0; i < n; i++){
                    stringstream ss(people[i]);
                    int j = 0;
                    while(ss>>j) a[i].push_back(j);
                    cout<<endl;
                 }
                 int m = a[0].size();
                 vector<int> row(n), col(m);
                 fill(col.begin(), col.end(), 0);
                 for(int i = 0; i < n; i++){
                    int min = 2000;
                    for(int j = 0; j < m; j++){
                        cout<<a[i][j]<<" ";
                        if(col[j] < a[i][j]) col[j] = a[i][j];
                        if(min > a[i][j]) min = a[i][j];
                    }
                    row[i] = min;
                    cout<<"\n";
                 }
                 int row_max = *max_element(row.begin(), row.end()), col_min = *min_element(col.begin(), col.end());
                 vector<int> v;
                 v.push_back(row_max);
                 v.push_back(col_min);
                 return v;
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"9 2 3",
 "4 8 7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 4,  7 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getPeople(Arg0)); }
	void test_case_1() { string Arr0[] = {"1 2",
 "4 5",
 "3 6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 4,  4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getPeople(Arg0)); }
	void test_case_2() { string Arr0[] = {"1 1000",
 "1000 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  1000 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getPeople(Arg0)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        TallPeople ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
