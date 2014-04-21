#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class WordFind
        {
        public:
        vector <string> findWords(vector <string> grid, vector <string> wordList)
            {
                vector<string> ret;
                int n = grid.size(), m = grid[0].size();
                for(int t = 0; t < wordList.size(); t++){
                    char s[10] = {'\0'};
                    string w = wordList[t];
                    int l = w.size();
                    for(int i = 0; i < n; i++)
                    for(int j = 0; j < m; j++){
                        string ss;
                        bool done = false;
                        if(j+l-1 < m) ss = grid[i].substr(j, l);
                        if(ss == w) done = true;
                        if(i+l-1 < n){
                            string tt;
                            for(int ii = i; ii < i+l; ii++)
                                tt.push_back(grid[ii][j]);
                            if(tt == w) done = true;
                        }
                        if(i+l-1 < n && j+l-1 < m){
                            string tt;
                            for(int ii = i, jj = j; ii < i+l; ii++, jj++)
                                tt.push_back(grid[ii][jj]);
                            if(tt == w)
                                done = true;
                        }
                        if(done){
                            sprintf(s, "%d %d", i, j);
                            i = n; j = m;
                        }
                    }
                    ret.push_back(string(s));
                }
                return ret;
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"TEST",
 "GOAT",
 "BOAT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"GOAT", "BOAT", "TEST"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "1 0",
  "2 0",
  "0 0" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, findWords(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"SXXX",
 "XQXM",
 "XXLA",
 "XXXR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"SQL", "RAM"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "0 0",
  "" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, findWords(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"EASYTOFINDEAGSRVHOTCJYG",
 "FLVENKDHCESOXXXXFAGJKEO",
 "YHEDYNAIRQGIZECGXQLKDBI",
 "DEIJFKABAQSIHSNDLOMYJIN",
 "CKXINIMMNGRNSNRGIWQLWOG",
 "VOFQDROQGCWDKOUYRAFUCDO",
 "PFLXWTYKOITSURQJGEGSPGG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"EASYTOFIND", "DIAG", "GOING", "THISISTOOLONGTOFITINTHISPUZZLE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "0 0",
  "1 6",
  "0 22",
  "" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, findWords(Arg0, Arg1)); }

// END CUT HERE

        };

// BEGIN CUT HERE
     int main()
     {
        WordFind ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
