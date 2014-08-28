#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef set<pi> sp;
vs A;
int cnt;
int n, m;
int B[51][51];
int I[8] = {1, -1, 1, -1, 1, 0, -1, 0};
int J[8] = {1, -1, -1, 1, 0, 1, 0, -1};


class TopographicalImage {

        public:
        void dfs(int i, int j){
            cnt++;
            B[i][j] = 1;
            for(int a = 0; a < 8; a++){
                int ii = i+I[a], jj = j+J[a];
                if(ii >= 0 && jj >= 0 && ii < n && jj < m)
                    if(A[ii][jj] <= A[i][j] && !B[ii][jj]) dfs(ii, jj);
            }
        }

        vi calcPeakAreas(vs AA)
        {
            A = AA;
            n = A.size(); m = A[0].size();
            cnt = 0;
            for(int i = 0; i <= 50; i++)
                for(int j = 0; j <= 50; j++) B[i][j] = 0;

            int sum = 0;
            vi ret;
            while(sum < n*m){
                int x = -1, y = -1, maxv = 0;
                for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                if(B[i][j] == 0 && A[i][j] > maxv){
                    maxv = A[i][j];
                    x = i; y = j;
                }
                if(x != -1){
                    cnt = 0;
                    dfs(x, y);
                    ret.push_back(cnt);
                    sum += cnt;
                }
            }
            return ret;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {
"............",
"....i..i....",
"....i..i....",
".o..i..i..o.",
".o........o.",
"..oooooooo..",
"............"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 78,  3,  3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, calcPeakAreas(Arg0)); }
	void test_case_1() { string Arr0[] = {
"............",
"....i..i....",
"....i..i....",
".S..i..i..Y.",
".M........E.",
"..ILEYSMIL..",
"............"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 69,  3,  2,  5,  3,  1,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, calcPeakAreas(Arg0)); }
	void test_case_2() { string Arr0[] = {
"zzzzzzzzzzzzz",
"z...........z",
"z...c.b.c...z",
"z....bab.b..z",
"z...c.b.c...z",
"z...........z",
"zzzzzzzzzzzzz"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 81,  6,  2,  1,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, calcPeakAreas(Arg0)); }
	void test_case_3() { string Arr0[] = {"!"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, calcPeakAreas(Arg0)); }
	void test_case_4() { string Arr0[] = {
"AAAAAAABBBBCCCDEFGHHIIJIIHGFEDDCCCBBBBBBBBBBAAAAAA",
"AAAAABBBBBCCDDEEFGHIJJJJIIHGFEDDCCCCCCCCCBBBBBAAAA",
"AAAABBBBCCCDDEEFGHIIJJJJJIHGFEDDDDDDDDDCCCCBBBBAAA",
"AAABBBBCCDDEEFFGHHIJJJJJJIHGFEEDDDDDEEDDDDCCBBBBAA",
"AABBBCCDDEEFFGGHHIIJJJJJIHHGFEEEEEEEFFFEEDDCCBBBAA",
"BBBBCCDDEFFGHHHIIIIJJJIIIHGFFEEEEFFGGGGGFEEDCCBBBA",
"BBBCCDEEFGHIIIJJJJIIIIIHHGGFFEEFFGGHHHHHGGFEDCCBBB",
"BBCCDEEGHIJJKKKKJJJIIHHGGFFEEEEFGGHIIJJIIHGFEDCCBB",
"CCCDEEFHIJKLMMMLKKJIHHGGFFEEEEFFGHIJJKKJJIHGFEDCBB",
"CDDEEFHIJLMNNNNMLKJIHGFFEEEDEEFFGIJKKLLLKJIHFEDCCB",
"DDEFFGIJLMNOPPONMLJIHGFEEDDDDEFGHIJKLMMMLKJIGFEDCB",
"EEFFGHIKMNOQQQPONLKIHFEEDDDDDEFGHIKLMMNMMLKIHGEDCC",
"FFGGHIJLMOPQRRQPNMKIGFEDDCCDDEFGHIKLMNNNNMLJIGFEDC",
"GHHHIJKLNOQRRRQPOMKIGFEDDCCDDEFGHIKLMNNNNMLKIHFEDC",
"HIIIJJKLNOPQRRQPNLKIGFEDDCCDDEFGHJKLMNOONNMKJHGFDC",
"IJJJJJKLMOPQQQPONLJHGFEDDDDDEEFGIJKLMNOONNMLJIGFED",
"JJJJJKKLMNOOPPONMKJHGFEDDDDEEFGHIJKLMNNONNMLJIGFED",
"JKKJJJKKLMMNNNNMLJIHFFEEEEEFGGHIJKLMMNNNNMMKJIGFED",
"KKKJJJJJKKLLMLLKJIHGFFEEEFFGHIJKKLMMNNNNNMLKJHGFED",
"JJJJIIIIIJJJKKJJIIHGFFFFFGHIJKLMMNNNNNNMMLKJIHGEDC",
"JJJIIHHHHHHIIIIIHHGGGGGGHIJKLMNOOOOONNMMLKJIHGFEDC",
"IIIHHGGGGGGGGHHHGGGGGGHIIJLMNOPQQQQPONMLKJIHGFEDDC",
"HHHGGFFFFFFFFFGGGGGGHHIJKMNOQRSSSSRQPNMLKIHGFFEDCC",
"GGGFFEEEEEEEEFFFGGGHIJKLMOPRSTUUUTSRPNMKJHGFFEDCCB",
"FFFEEEEDDDDEEEEFGGHIJKLNOQRTUVWWWVTRPNLJIHFEEDCCBB",
"EEEEDDDDDDDDEEEFGHIJKLNOQRTVWXYYXWUSPNLJHGFEDCCBBB",
"DDDDDDDDDDDEEEFFGHIKLNOQRTVWXYZYYWURPMKIGFEDCCBBBB",
"CDDDDDDEEEEEEFFGHIJKMOPRSUWXYZZZXWTROMJHGEDCCBBBBA",
"CCDDDEEEFFFFFGGHHJKLNOQRTVWXYZZYXVTQNLIGFEDCBBBAAA",
"CCDDEFFGGGGHHHHIIJKMNPQSTVWXYYYXVURPMKIGEDCBBBAAAA",
"CDDEFGGHIIIIIIIJJKLMOPQSTUVWWXWVUSQNLJHFECCBBBAAAA",
"CDEFGHIJKKKKKKKKKLMNOPQRSTUVVVUTSQOMJHGEDCBBBAAAAA",
"CDEGHIKLMMMMMMLLLMMNOPQRSSTTTTSRQOMKIGFDCCBBAAAAAA",
"DEFGIKLMNOOOONNMMMNNOPQQRRRRRRQPNMKIHFEDCBBBAAAAAA",
"DEGHJLMOPQQQPPOONNNOOPPPQQQPPONMLKIHFEDCBBBAAAAAAA",
"DEGIKMNPQRRRRQPOOOOOOOPPPOOONMLKJIHFEDCCBBAAAAAAAA",
"DFGIKMOQRSSSRRQPOOOOOOOOONMMLKJIHGFEDCCBBBAAAAAAAA",
"DFGIKMOQRSSSRRQPOOOOONNNMMLKJIIHGFEDCCBBBAAAAAAAAA",
"DEGIJLNPQRRRRQPOONNNNNMMLLKJIHGFEEDCCBBBAAAAAAAAAA",
"DEFHJKMOPQQQQPOONNMMMMLLKJIHGGFEDDCCBBBAAAAAAAAAAA",
"CDFGIJLMNOOOONNMMLLLLLKKJIHGFEEDCCCBBBAAAAAAAAAAAA",
"CDEFGIJKLMMMMMLLKKKKKJJIIHGFEDDCCBBBBAAAAAAAAAAAAA",
"CCDEFGHIJKKKKKJJJIIIIIHHGGFEDDCCBBBBAAAAAAAAAAAAAA",
"BCCDEFGHHIIIIIHHHHHHHGGGFFEDDCCBBBAAAAAAAAAAAAAAAA",
"BBCCDEEFFGGGGGGFFFFFFFFEEDDCCCBBBAAAAAAAAAAAAAAAAA",
"BBBCCDDEEEEEEEEEEEEEEEEDDDCCBBBBAAAAAAAAAAAAAAAAAA",
"ABBBCCCCDDDDDDDDDDDDDDDCCCCBBBBAAAAAAAAAAAAAAAAAAA",
"AABBBBBCCCCCCCCCCCCCCCCCCBBBBBAAAAAAAAAAAAAAAAAAAA",
"AAABBBBBBBBBBBBBBBBBBBBBBBBBAAAAAAAAAAAAAAAAAAAAAA",
"AAAAAABBBBBBBBBBBBBBBBBBBBAAAAAAAAAAAAAAAAAAAAAAAA"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1918,  65,  483,  5,  5,  24 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, calcPeakAreas(Arg0)); }

// END CUT HERE

 };

// BEGIN CUT HERE
int main(){

        TopographicalImage ___test;
        ___test.run_test(-1);

}
// END CUT HERE
