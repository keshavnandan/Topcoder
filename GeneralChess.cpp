#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
typedef pair<int, int> pi;
class GeneralChess
        {
        public:
        vector <string> attackPositions(vector <string> pieces)
        {
            vector<pi> pos;
            for(int i = 0; i < pieces.size(); i++){
                int j = 0, a, b;
                sscanf(pieces[i].c_str(), "%d,%d", &a, &b);
                cout<<a<<" "<<b<<endl;
                pos.push_back(make_pair(a, b));
            }
            int move[8][2] = {{1,2},{-1,2},{-1,-2},{1,-2},{2,1},{-2,1},{-2,-1},{2,-1}};
            vector<pi> res;

            for(int i = 0; i < pos.size(); i++){
                vector<pi> v1, v2(10);
                int x, y;
                for(int j = 0; j < 8; j++){
                    x = pos[i].first; y = pos[i].second;
                    x += move[j][0]; y += move[j][1];
                    v1.push_back(make_pair(x, y));
                    sort(v1.begin(), v1.end());
                    if(i == 0) res = v1;
                }
                vector<pi>::iterator it = set_intersection(res.begin(), res.end(), v1.begin(), v1.end(), v2.begin());
                v2.resize(it - v2.begin());
                res = v2;
            }
//            for(int i = 0; i < res.size(); i++) cout<<res[i].first<<","<<res[i].second<<endl;
            vector<string> sol;
            for(int i = 0; i < res.size(); i++){
                char s[50];
                sprintf(s, "%d,%d", res[i].first, res[i].second);
                //cout<<s<<endl;
                sol.push_back(string(s));
            }
            return sol;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"0,0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "-2,-1",  "-2,1",  "-1,-2",  "-1,2",  "1,-2",  "1,2",  "2,-1",  "2,1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, attackPositions(Arg0)); }
	void test_case_1() { string Arr0[] = {"2,1", "-1,-2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "0,0",  "1,-1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, attackPositions(Arg0)); }
	void test_case_2() { string Arr0[] = {"0,0", "2,1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, attackPositions(Arg0)); }
	void test_case_3() { string Arr0[] = {"-1000,1000", "-999,999", "-999,997"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "-1001,998" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, attackPositions(Arg0)); }

// END CUT HERE

        };

// BEGIN CUT HERE
     int main()
     {
        GeneralChess ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
