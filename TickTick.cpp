// BEGIN CUT HERE

// END CUT HERE
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

class TickTick
        {
        public:
        int count(vector <string> events)
            {
                int n = events.size();
                if(n == 1){
                    if(atof(events[0].c_str()) >= 1.0) return 1;
                    return 2;
                }
                double r = 0.00000000;
                long double a;
                set<string> st;
                for(int i = 0; i <= n; i++){
                    string s = "";
                    long double t = modfl(r+0.00000001, &a);
//                    cout<<"t = "<<t<<endl;
                    double x = 0.00000000;
                    for(int j = 0; j < n; j++){
                        double y = atof(events[j].c_str());
//                        cout<<"x = "<<x<<", y = "<<y<<endl;
                        if(y >= x+1.0)  s += "D";
                        else{
                            double tx = floor(x);
                            double ty = floor(y);
                            if(tx == ty){
                                if(x-tx < t && t < y-ty) s += "D";
                                else s += "S";
                            }
                            else{
                                if(x-tx < t || t < y-ty) s += "D";
                                else s += "S";
                            }
                        }
                        x = y;
                    }
                    if(i != n)
                    r = atof(events[i].c_str());
//                    cout<<"s = "<<s<<endl;
                    st.insert(s);
                }
                return st.size();
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".222","00.223","1.221","4.220"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"4.220112","4.221","4.222","4.223"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {".0000001",".0000002"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, count(Arg0)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        TickTick ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
