#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
struct E{
    string name;
    int g, s, b;
    E(string n = "", int g = 0, int s = 0, int b = 0): name(n), g(g), s(s), b(b){}
};


    bool operator<(const E &a, const E &b){
        if(a.g != b.g)
            return a.g < b.g;
        if(a.s != b.s)
            return a.s < b.s;
        if(a.b != b.b)
            return a.b < b.b;
        return a.name > b.name;
    }

class MedalTable
        {
        public:

        vector <string> generate(vector <string> results)
            {
                map<string, E> M;
                for(int i = 0; i < results.size(); i++){
                    stringstream ss(results[i]);
                    string s;
                    ss>>s;
                    if(M.find(s) == M.end())
                         M[s] = E(s, 1, 0, 0);
                    else M[s].g++;
                    ss>>s;
                    if(M.find(s) == M.end())
                         M[s] = E(s, 0, 1, 0);
                    else M[s].s++;
                    ss>>s;
                    if(M.find(s) == M.end())
                         M[s] = E(s, 0, 0, 1);
                    else M[s].b++;
                }
                vector<E> V;
                for(map<string, E>::iterator it = M.begin(); it != M.end(); it++) V.push_back(it->second);
                sort(V.rbegin(), V.rend());
                vector<string> R;
                for(int i = 0; i < V.size(); i++){
                    stringstream st;
                    st<<V[i].name<<" "<<V[i].g<<" "<<V[i].s<<" "<<V[i].b;
                    cout<<st.str()<<endl;;
                    R.push_back(st.str());
                }
                return R;
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"ITA JPN AUS", "KOR TPE UKR", "KOR KOR GBR", "KOR CHN TPE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "KOR 3 1 0",  "ITA 1 0 0",  "TPE 0 1 1",  "CHN 0 1 0",  "JPN 0 1 0",  "AUS 0 0 1",  "GBR 0 0 1",  "UKR 0 0 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, generate(Arg0)); }
	void test_case_1() { string Arr0[] = {"USA AUT ROM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "USA 1 0 0",  "AUT 0 1 0",  "ROM 0 0 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, generate(Arg0)); }
	void test_case_2() { string Arr0[] = {"GER AUT SUI", "AUT SUI GER", "SUI GER AUT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "AUT 1 1 1",  "GER 1 1 1",  "SUI 1 1 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, generate(Arg0)); }

// END CUT HERE

        };

// BEGIN CUT HERE
     int main()
     {
        MedalTable ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
