// BEGIN CUT HERE

// END CUT HERE
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#define isvowel(x) ( (x) == 'a' || (x) == 'e' || (x) == 'i' || (x) == 'o' || (x) == 'u' )
using namespace std;

class WordForm
        {
        public:
        string getSequence(string word)
            {
                bool vowel[word.size()];
                fill(vowel, vowel + word.size(), false);
                string ret = "";
                char c = word[0];
                c = tolower(c);
                if(isvowel(c)){
                    ret += 'V';
                    vowel[0] = true;
                }
                    else  ret += 'C';
                for(int i = 1; i < word.size(); i++) {
                    c = word[i];
                    c = tolower(c);
                        cout<<"upper: "<<word[i]<<endl;
                        cout<<c<<" ";
                    if(isvowel(c)) {
                        if(*ret.rbegin() != 'V') ret += 'V';
                        vowel[i] = true;
                    }
                    else{
                            if(c == 'y' && !vowel[i-1]) {
                                ret += 'V';
                                vowel[i] = true;
                            }
                            else if(*ret.rbegin() != 'C') ret += 'C';
                        }
                }
                return ret;

            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "WHEREABOUTS"; string Arg1 = "CVCVCVC"; verify_case(0, Arg1, getSequence(Arg0)); }
	void test_case_1() { string Arg0 = "yoghurt"; string Arg1 = "CVCVC"; verify_case(1, Arg1, getSequence(Arg0)); }
	void test_case_2() { string Arg0 = "YipPy"; string Arg1 = "CVCV"; verify_case(2, Arg1, getSequence(Arg0)); }
	void test_case_3() { string Arg0 = "AyYyEYye"; string Arg1 = "VCVCVCV"; verify_case(3, Arg1, getSequence(Arg0)); }
	void test_case_4() { string Arg0 = "yC"; string Arg1 = "C"; verify_case(4, Arg1, getSequence(Arg0)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        WordForm ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
