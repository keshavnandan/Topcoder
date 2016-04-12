#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class FoxAndWord
        {
        public:
        bool fun(string x, string y){
            int n = x.size();
            for(int i = 1; i < n; i++)
                if(x.substr(i) == y.substr(0, n-i) && x.substr(0, i) == y.substr(n-i)){
                    cout<<x<<" "<<y<<" "<<x.substr(i)<<" "<<y.substr(0, n-i)<<endl;
                    return true;
                }

            return false;
        }
        int howManyPairs(vector <string> words)
            {
                int ans = 0;
                for(int i = 0; i < words.size(); i++){
                    for(int j = i+1; j < words.size(); j++)
                        if(fun(words[i], words[j])) ans++;
                }
                return ans;
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"tokyo", "kyoto"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, howManyPairs(Arg0)); }
	void test_case_1() { string Arr0[] = {"aaaaa", "bbbbb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, howManyPairs(Arg0)); }
	void test_case_2() { string Arr0[] = {"ababab","bababa","aaabbb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, howManyPairs(Arg0)); }
	void test_case_3() { string Arr0[] = {"eel", "ele", "lee"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, howManyPairs(Arg0)); }
	void test_case_4() { string Arr0[] = {"aaa", "aab", "aba", "abb", "baa", "bab", "bba", "bbb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(4, Arg1, howManyPairs(Arg0)); }
	void test_case_5() { string Arr0[] = {"top","coder"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(5, Arg1, howManyPairs(Arg0)); }

// END CUT HERE

        };

// BEGIN CUT HERE
     int main()
     {
        FoxAndWord ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
