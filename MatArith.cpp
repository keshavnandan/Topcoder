#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <numeric>
#include <climits>
#include <cstdio>
#include <string>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<long> vl;
typedef vector<vl>  vvl;
map<char, vvl> M;

vvl operator+(vvl a, vvl b){
    if(a.empty() || b.empty()) return vvl();
    vvl r;
    int n = a.size(), m = a[0].size();
    if(b.size() != n || b[0].size() != m) return r;
    r = a;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
        r[i][j] = a[i][j]+b[i][j];
        if(r[i][j] > INT_MAX || r[i][j] < INT_MIN) return vvl();
    }
    return r;
}
vvl operator*(vvl a, vvl b){
    if(a.empty() || b.empty()) return vvl();
    vvl r;
    int n = a.size(), m = a[0].size();
    if(b.size() != m) return r;
    int p = b[0].size();
    r.resize(n);
    for(int i = 0; i < n; i++){
        r[i].resize(p);
        fill(r[i].begin(), r[i].end(), 0);
    }
    for(int i = 0; i < n; i++)
    for(int j = 0; j < p; j++){
        for(int k = 0; k < m; k++){
            r[i][j] += a[i][k]*b[k][j];
        }
        if(r[i][j] > INT_MAX || r[i][j] < INT_MIN) return vvl();
    }

    return r;
}
vvl to(vs a){
    if(a.empty()) return vvl();
    vvl aa;
    int n = a.size(), m = a[0].size();
    aa.resize(n);
    for(int i = 0; i < n; i++){
        stringstream ss(a[i]);
        ll k;
        while(ss>>k) aa[i].push_back(k);
    }
    return aa;
}
vs from(vvl a){
    if(a.empty()) return vs();
    vs aa;
    int n = a.size(), m = a[0].size();
    aa.resize(n);
    for(int i = 0; i < n; i++){
        string s;
        for(int j = 0; j < m; j++)
        if(j == 0) s += to_string(a[i][j]);
            else s += " " + to_string(a[i][j]);
        aa[i] = s;
    }
    return aa;
}
vvl cal(string s){
    if(s.empty()) return vvl();
    char op;
    if(s.size() == 1) return M[s[0]];
    if(s.size() == 3){
        op = s[1];
        vvl a = M[s[0]], b = M[s[2]];
        if(op == '+') return a+b;
        return a*b;
    }
    int p = -1;
    for(int i = 0; i < s.size(); i++) if(s[i] == '+') { p = i;}
    vvl a, b;
    if(p != -1){
        a = cal(s.substr(0, p)); b = cal(s.substr(p+1));
        return a+b;
    }
    else{
        int n = s.size();
        a = cal(s.substr(0, n-2)); b = cal(s.substr(n-1));
        return a*b;
    }
}

class MatArith {
        public:
        vector <string> calculate(vs A, vs B, vs C, string eq)
        {
            vvl a = to(A), b = to(B), c = to(C);
            M['A'] = a; M['B'] = b; M['C']  = c;
            vvl v = cal(eq);
            //vvl v = a*b;
            for(int i = 0; i < v.size(); i++){
                for(int j = 0; j < v[i].size(); j++)
                    cout<<v[i][j]<<" ";
                cout<<endl;
            }
            return from(v);
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"1 2 3","2 3 4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 2","3 4","5 6"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "A*B"; string Arr4[] = { "22 28",  "31 40" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, calculate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"1 2 3","2 3 4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 2","3 4","5 6"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "A+B+C"; string Arr4[] = { }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, calculate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"3 5 7","5 4 3","-2 3 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 1 1","2 5 2","3 5 -3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "A+C"; string Arr4[] = { "4 6 8",  "7 9 5",  "1 8 -1" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, calculate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"10 0","0 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "A*A*A*A*A*A*A*A*A"; string Arr4[] = { "1000000000 0",  "0 0" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, calculate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {"10 0","0 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "A*A*A*A*A*A*A*A*A*A"; string Arr4[] = { }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, calculate(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
     int main()
     {
        MatArith ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
