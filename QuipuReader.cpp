// BEGIN CUT HERE

// END CUT HERE
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class QuipuReader
        {
        public:
        typedef pair<int, int> pi;
        int cal(pi pos, pi curr){
            if(pos.second < curr.first) return -1;
            if(pos.first > curr.second) return 1;
            return 0;
        }
        vector <int> readKnots(vector <string> knots)
            {
                list<pi> A[11], T;
                int n = knots[0].size();
                T.push_back(make_pair(-1,-1));
                T.push_back(make_pair(n,n));
                for(int i = 0; i < knots.size(); i++){
                    cout<<knots[i]<<endl;
                    list<pi> &B = A[i];
                    int j = 0;
                    while(j < n){
                        while(j < n && knots[i][j] == '-') j++;
                        int k = j;
                        while(k < n && knots[i][k] == 'X') k++;
                        if(j < n) B.push_back(make_pair(j, k-1));
                        j=k;
                    }
                for(list<pi>::iterator it = A[i].begin(); it != A[i].end(); it++) cout<<"<"<<it->first<<","<<it->second<<"> ";
                cout<<endl;

                }
                return vector<int>();
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = { "-XXXXXXX--XX-----XXXXX---",
  "---XX----XXX-----XXXX----",
  "-XXXXX---XXXXX--XXXXXXXX-" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 725,  234,  558 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, readKnots(Arg0)); }
	void test_case_1() { string Arr0[] = { "XX---XXXX",
  "XXX-----X" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 24,  31 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, readKnots(Arg0)); }
	void test_case_2() { string Arr0[] = { "-XXX---XX----X",
  "--X----X-XXXXX",
  "-XX--XXXX---XX" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 321,  115,  242 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, readKnots(Arg0)); }
	void test_case_3() { string Arr0[] = { "-------X--------",
  "--XXX----XXXX---",
  "--------------XX" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 100,  3040,  2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, readKnots(Arg0)); }
	void test_case_4() { string Arr0[] = { "--XXX-XXXXXXXX----------XXXXXXXXX--XXXXXXXX-",
  "--XX----XXXX-----XXXXXX---XXX------XXXXXXXX-",
  "--------------------X----XXXXXXXX--XXXXXXXX-",
  "--XX-------X------XXXX----XXX-------XXXXXX--",
  "--XXX---XXXXX-------X------XX--------X------",
  "-XXXX--XXXXXXX-----------XXXXXXX----XXXXX---",
  "-----------X---XXXXXXXX----XX--------XXX----",
  "-----------X---XXXXXXXX----X----------------",
  "---X--XXXXXXXX--XXXXXXX---XXX---------------",
  "--XX---XXXXXXX--XXXXXXX----XX-------XXXXX---" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 38098,  24638,  188,  21436,  35121,  47075,  1823,  1810,  18730,  27725 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, readKnots(Arg0)); }
	void test_case_5() { string Arr0[] = {"X","-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, readKnots(Arg0)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        QuipuReader ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
