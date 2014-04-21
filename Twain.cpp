// BEGIN CUT HERE

// END CUT HERE
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class Twain
        {
        public:
        string getNewSpelling(int year, string phrase)
            {
                if(phrase == "") return "";
                stringstream ss(phrase);
                string s;
                string ret = "";
                while(ss>>s){

                    int n = s.size();
                    if(year>0){
                        if(s[0] == 'x') s[0] = 'z';
                        for(int i = 1; i < n; i++)
                            if(s[i] == 'x') s = s.substr(0,i) + "ks" + s.substr(i+1);
                    }
                    if(year>1){
                        for(int i = 0; i < n; i++)
                            if(s[i] == 'y') s[i] = 'i';
                    }
                    if(year>2){
                        for(int i = 0; i < n-1; i++)

                            if(s[i] == 'c'){
                                if(s[i+1] == 'e' || s[i+1] == 'i')
                                    s[i] == 's';
                            }
                    }
                    if(year>3){
                        bool done = true;
                        while(done){
                            done = false;
                            for(int i = 0; i < s.size()-1; i++){
                                if(s[i] == 'c' && s[i+1] == 'k'){
                                    done = true;
                                    s = s.substr(0,i) + s.substr(i+1);
                                }
                            }
                        }
                    }
                    if(year>4){
                        if(s.substr(0,3) == "sch") s = "sk" + s.substr(3);
    //                    cout<<"phrase = "<<phrase<<endl;
                        for(int i = 0; i < n-2; i++){
                            if(s.substr(i,3) == "chr") s = s.substr(0,i) + "k" + s.substr(i+2);
                        }
                        for(int i = 0; i < n; i++){
                            if(s[i] == 'c'){
                                s[i] = 'k';
                                if(i < n-1 && s[i+1] == 'h')   s[i] = 'c';
                            }
                        }
                    }
                    if(year>5){
                        if(s.substr(0,2) == "kn") s = "n" + s.substr(2);
                    }
                  ret += (s+" ");
//                    ss<<s;
                }
                return ret;
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arg1 = "i fixed the chrome xerox by the cyclical church"; string Arg2 = "i fiksed the chrome zeroks by the cyclical church"; verify_case(0, Arg2, getNewSpelling(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; string Arg1 = "i fixed the chrome xerox by the cyclical church"; string Arg2 = "i fiksed the chrome zeroks bi the ciclical church"; verify_case(1, Arg2, getNewSpelling(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 0; string Arg1 = "this is unchanged"; string Arg2 = "this is unchanged"; verify_case(2, Arg2, getNewSpelling(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; string Arg1 = "sch kn x xschrx cknnchc cyck xxceci"; string Arg2 = "sk n z zskrks nchk sik zksesi"; verify_case(3, Arg2, getNewSpelling(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 7; string Arg1 = "  concoction   convalescence   cyclical   cello   "; string Arg2 = "  konkoktion   konvalesense   siklikal   selo   "; verify_case(4, Arg2, getNewSpelling(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 7; string Arg1 = ""; string Arg2 = ""; verify_case(5, Arg2, getNewSpelling(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 7; string Arg1 = "cck xzz aaaaa"; string Arg2 = "k z aaaaa"; verify_case(6, Arg2, getNewSpelling(Arg0, Arg1)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        Twain ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
