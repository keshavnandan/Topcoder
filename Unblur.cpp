#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <climits>
#include <cstdio>
using namespace std;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

class Unblur{ 
        public: 
        vector <string> original(vector <string> blurred) {
          int n = blurred.size(), m = blurred[0].size();
          vvi M(n, vi(m, 0)), A = M;
          vs R(n, string(m, '.'));

          for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
              M[i][j] = blurred[i][j]-'0';
          
          for(int i = 1; i <= n-2; i++)
            for(int j = 1; j <= m-2; j++){
              int f = 0;              
              for(int ii = max(0, i-2); ii <= i; ii++)
                for(int jj = max(0, j-2); jj <= j; jj++)
                  f += A[ii][jj];

              f = M[i-1][j-1]-f;
              if(f == 1){
               R[i][j] = '#';
               A[i][j] = 1;
              }
            }

          return R;
        } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = { "1221",
  "1221",
  "1221" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "....",  ".##.",  "...." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, original(Arg0)); }
	void test_case_1() { string Arr0[] = { "00000",
  "00000",
  "00000",
  "00000" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { ".....",  ".....",  ".....",  "....." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, original(Arg0)); }
	void test_case_2() { string Arr0[] = { "0011212121100",
  "0123333333210",
  "0123333333210",
  "1233333333321",
  "1233333333321",
  "1233333333321",
  "0112121212110" } ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { ".............",  "...#.#.#.#...",  "..#.#.#.#.#..",  ".............",  ".#.#.#.#.#.#.",  "..#.#.#.#.#..",  "............." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, original(Arg0)); }
	void test_case_3() { string Arr0[] = { "1233321000000000123332100000000000000000000",
  "1244422233222332334343323322232112332223321",
  "1255523344343443545343434434343233432334432",
  "0033303455465775633011445546454355753457753",
  "0033303333364543533011433336333364521346542",
  "0033303455464532445343545546454355753446542",
  "0022202344342200234343434434343233432323221",
  "0011101233221100123332223322232112332211111" } ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "...........................................",  ".#####...........#####.....................",  "...#...####.####.#...#.####.###..####.####.",  "...#...#..#.#..#.#.....#..#.#..#.#....#..#.",  "...#...#..#.####.#.....#..#.#..#.###..####.",  "...#...#..#.#....#...#.#..#.#..#.#....#.#..",  "...#...####.#....#####.####.###..####.#..#.",  "..........................................." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, original(Arg0)); }
	void test_case_4() { string Arr0[] = { "0000123210000",
  "0012456542100",
  "0135789875310",
  "0258988898520",
  "1479865689741",
  "2589742479852",
  "2589742479852",
  "1479865689741",
  "0258988898520",
  "0135789875310",
  "0012456542100",
  "0000123210000" }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { ".............",  ".....###.....",  "...#######...",  "..#########..",  "..####.####..",  ".####...####.",  ".####...####.",  "..####.####..",  "..#########..",  "...#######...",  ".....###.....",  "............." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, original(Arg0)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        Unblur ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
