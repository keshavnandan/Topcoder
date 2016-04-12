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
int X[] = {1, 0, -1, 0};
int Y[] = {0, 1, 0, -1};

class Escape {
        public:
        int lowest(vector <string> harmful, vector <string> deadly)
        {
            int M[501][501];
            memset(M, 0, sizeof(M));
            for(string s : harmful){
                int a1, b1, a2, b2;
                sscanf(s.c_str(), "%d%d%d%d", &a1, &b1, &a2, &b2);
                if(a1 > a2) swap(a1, a2);
                if(b1 > b2) swap(b1, b2);
                for(int i = a1; i <= a2; i++)
                    for(int j = b1; j <= b2; j++)
                        M[i][j] = 1;
            }

            for(string s : deadly){
                int a1, b1, a2, b2;
                sscanf(s.c_str(), "%d%d%d%d", &a1, &b1, &a2, &b2);
                if(a1 > a2) swap(a1, a2);
                if(b1 > b2) swap(b1, b2);
                for(int i = a1; i <= a2; i++)
                    for(int j = b1; j <= b2; j++)
                        M[i][j] = 2;
            }


            deque<pair<pi, int> > Q;
            Q.push_back(make_pair(make_pair(0, 0), 0));
            int visited[501][501];
            memset(visited, 0, sizeof(visited));
            M[0][0] = 0;
            visited[0][0] = 1;

            while(!Q.empty()){

                pi p = Q.front().first;
                int l = Q.front().second;
                Q.pop_front();
                int px = p.first, py = p.second;
                l += M[px][py];
//                cout<<px<<" "<<py<<" "<<l<<endl;
                if(px == 500 && py == 500) return l;

                for(int k = 0; k < 4; k++)
                {
                    int i = X[k], j = Y[k];
                    int qx = px+i, qy = py+j;
                    if(0 <= qx && qx <= 500 && 0 <= qy && qy <= 500 && !visited[qx][qy] && M[qx][qy] < 2){
                        visited[qx][qy] = 1;
                        pi q = make_pair(qx, qy);
                        if(M[qx][qy] == 1) Q.push_back(make_pair(q, l));
                        else Q.push_front(make_pair(q, l));
                    }
                }
            }

            return -1;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, lowest(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"500 0 0 500"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 0 0 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; verify_case(1, Arg2, lowest(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"0 0 250 250","250 250 500 500"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 251 249 500","251 0 500 249"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; verify_case(2, Arg2, lowest(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"0 0 250 250","250 250 500 500"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 250 250 500","250 0 500 250"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, lowest(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"468 209 456 32",
 "71 260 306 427",
 "420 90 424 492",
 "374 253 54 253",
 "319 334 152 431",
 "38 93 204 84",
 "246 0 434 263",
 "12 18 118 461",
 "215 462 44 317",
 "447 214 28 475",
 "3 89 38 125",
 "157 108 138 264",
 "363 17 333 387",
 "457 362 396 324",
 "95 27 374 175",
 "381 196 265 302",
 "105 255 253 134",
 "0 308 453 55",
 "169 28 313 498",
 "103 247 165 376",
 "264 287 363 407",
 "185 255 110 415",
 "475 126 293 112",
 "285 200 66 484",
 "60 178 461 301",
 "347 352 470 479",
 "433 130 383 370",
 "405 378 117 377",
 "403 324 369 133",
 "12 63 174 309",
 "181 0 356 56",
 "473 380 315 378"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"250 384 355 234",
 "28 155 470 4",
 "333 405 12 456",
 "329 221 239 215",
 "334 20 429 338",
 "85 42 188 388",
 "219 187 12 111",
 "467 453 358 133",
 "472 172 257 288",
 "412 246 431 86",
 "335 22 448 47",
 "150 14 149 11",
 "224 136 466 328",
 "369 209 184 262",
 "274 488 425 195",
 "55 82 279 253",
 "153 201 65 228",
 "208 230 132 223",
 "369 305 397 267",
 "200 145 98 198",
 "422 67 252 479",
 "231 252 401 190",
 "312 20 0 350",
 "406 72 207 294",
 "488 329 338 326",
 "117 264 497 447",
 "491 341 139 438",
 "40 413 329 290",
 "148 245 53 386",
 "147 70 186 131",
 "300 407 71 183",
 "300 186 251 198",
 "178 67 487 77",
 "98 158 55 433",
 "167 231 253 90",
 "268 406 81 271",
 "312 161 387 153",
 "33 442 25 412",
 "56 69 177 428",
 "5 92 61 247"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 254; verify_case(4, Arg2, lowest(Arg0, Arg1)); }

// END CUT HERE

 };

// BEGIN CUT HERE
int main(){

        Escape ___test;
        ___test.run_test(-1);

}
// END CUT HERE
