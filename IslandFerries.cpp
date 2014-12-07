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
struct  state
{
    int pos;
    int cost;
    vi tickets;
    state(int p = 0, int c = 0, vi t = vector<int>(10, 0)){
        pos = p;
        cost = c;
        tickets = t;
    }
};
bool operator<(state a, state b){
    return a.cost > b.cost;
}
int num = 0;
class IslandFerries{ 
        int dfs(int s, vvi &M, vi &vis){
            num++;
            vis[s] = true;
            for(int j = 0; j < 50; j++)
                if(!vis[j] && M[s][j] > 0) dfs(j, M, vis);
        }
        public: 
        vector <int> costs(vector <string> legs, vector <string> prices) {
            num = 0;
            vvi M(50, vi(50, 0)), P = M;
            int m = legs.size(), n = prices.size();
            for(int i = 0; i < legs.size(); i++){
                stringstream ss(legs[i]);
                string s;
                while(ss>>s){
                    int a, b;
                    sscanf(s.c_str(), "%d-%d", &a, &b);
                    M[a][b] |= (1<<i);
                }
            }
            for(int i = 0; i < n; i++){
                int j = 0, t = 0;
                stringstream ss(prices[i]);
                while(ss>>t) P[i][j++] = t;
            }   

            vi vis(50, 0);
            dfs(0, M, vis);
            cout<<"num = "<<num<<endl;
            priority_queue<state> Q;
            state s;
            Q.push(s);
            vi done(50, -1);
            int count = 0;
            set<pair<int, vi> > visited;

            while(!Q.empty()){
                state p = Q.top();
                Q.pop();
                int pos = p.pos, cost = p.cost;
                vi tickets = p.tickets;

                if(visited.find(make_pair(pos, tickets)) != visited.end()) continue;
                visited.insert(make_pair(pos, tickets));

                if(done[pos] == -1){
                    done[pos] = cost;
                    count++;
                    if(count == num) break;
                }
                int nt = 0;
                for(int t : tickets) if(t > 0) nt++;
                //buy more tickets if it is possible
                if(nt < 3){
                    for(int i = 0; i < m; i++)
                        if(tickets[i] == 0){
                            tickets[i] = P[pos][i];
                            Q.push(state(pos, cost+P[pos][i], tickets));
                            tickets[i] = 0;
                        }
                }

                //Go to some other island utilising any one of the tickets in kitty
                for(int i = 0; i < m; i++)
                    if(tickets[i] > 0){
                        //visit all islands to check if ferry i can help to go from pos to j
                        for(int j = 0; j < n; j++)
                            if(M[pos][j] & (1<<i)){
                                int t = tickets[i];
                                tickets[i] = 0;
                                Q.push(state(j, cost, tickets));
                                tickets[i] = t;
                            }
                    }
            }   
            return vi(done.begin()+1, done.begin()+n);
        }
        
// BEGIN CUT HERE
    public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
    private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
    void test_case_0() { string Arr0[] = { "0-1 0-3", "0-2" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "5 7", "1000 1000", "1000 1000", "1000 1000" }; 
    vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
    int Arr2[] = { 5,  7,  5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, costs(Arg0, Arg1)); }
    void test_case_1() { string Arr0[] = { "0-1 1-2 2-3", "0-1 2-3" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "1 10", "20 25", "50 50", "1000 1000", "1000 1000" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1,  11,  31,  -1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, costs(Arg0, Arg1)); }
    void test_case_2() { string Arr0[] = { "0-1", "1-0", "0-2", "2-3" }; 
    vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "1 1 1000 1000", "1000 1000 10 100", "1000 1000 1000 1000", "1000 1000 1000 1000" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1,  12,  112 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, costs(Arg0, Arg1)); }
    void test_case_3() { string Arr0[] = {"22-19 29-33 25-32 21-30 24-30 35-31 4-8 9-7 18-3", 
    "3-16 18-14 32-2 27-29 2-16 3-15 7-14 17-19 9-32", 
    "24-32 11-13 19-9 13-26 28-31 13-3 24-10 19-36", 
    "16-27 5-27 11-14 23-5 1-28 25-21 30-4 33-30 6-18", 
    "26-36 34-29 28-8 9-19 29-36 36-17 30-4 36-34 9-1", 
    "20-15 32-10 26-1 2-27 14-19 18-32 0-36 19-12 21-17", 
    "34-28 17-20 16-17 33-36 1-29 2-33 27-15 4-27 5-11", 
    "26-17 0-21 11-5 2-13 0-2 32-27 28-8 33-25 35-11", 
    "11-12 28-8 3-21 2-0 11-2 29-14 4-11 9-24 14-7", 
    "5-12 16-29 1-27 35-8 10-33 36-1 30-0 36-6 18-30"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = 
{"586 591 10 693 87 8 5 26 30 576", "931 923 84 516 461 99 501 7 929 1", "649 57 104 6 880 715 671 845 554 6", "20 2 495 489 71 610 764 36 580 17", 
"517 504 8 270 43 205 36 52 339 228", "5 97 7 93 998 30 8 78 41 37", "18 88 25 34 4 573 277 7 968 2", "52 7 544 551 3 33 8 5 176 53", 
"3 50 7 796 10 319 947 746 3 79", "290 487 96 675 52 739 31 5 723 89", "8 6 9 91 9 419 11 762 90 34", "612 9 10 98 77 870 271 472 95 811", 
"30 96 656 641 906 3 6 430 4 930", "48 353 7 34 7 491 1 7 52 426", "128 10 12 262 314 446 946 842 7 86", "198 445 10 481 4 993 276 814 3 4", 
"11 161 56 964 466 179 938 52 3 28", "1 935 398 492 10 59 150 43 6 720", "63 3 5 49 8 2 3 19 69 6", "4 6 38 747 109 43 18 9 15 2", 
"859 592 91 704 775 12 841 34 3 3", "997 8 1 769 682 639 9 2 799 1", "60 620 8 5 10 72 250 37 798 8", "615 816 25 4 1 146 352 1 44 4", 
"2 10 280 8 17 3 553 404 37 76", "4 73 55 362 5 9 120 7 99 727", "819 999 10 48 4 519 467 522 12 8", "3 513 85 531 10 99 8 3 896 825", 
"804 112 848 507 4 100 5 947 5 11", "120 68 304 9 83 685 374 860 8 6", "7 9 5 275 3 5 34 917 87 2", "66 942 8 1 7 797 40 828 748 855", 
"6 3 952 194 7 253 257 1 85 56", "887 986 702 936 8 8 9 7 6 91", "10 99 2 877 393 9 586 3 896 3", "59 70 383 336 355 912 4 65 430 6", "220 245 766 10 62 176 6 96 59 4"}; 
vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 12, 26, 33, 27, 46, 12, 32, 26, 32, 43, 45, 70, 28, 25, 18, 35, 31, 22, 27, 36, 26, -1, -1, 39, 31, 33, 13, 22, 17, 24, 32, 24, 30, 31, -1, 8 }; 
vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, costs(Arg0, Arg1)); }
    void test_case_4() { 
string Arr0[] = {"8-18 4-11 15-5 7-12 11-8 0-15 15-2 3-11 4-18 2-3",
 "16-2 18-3 15-18 11-19 18-2 18-7 19-17 3-15 12-19",
 "2-17 0-12 1-2 14-12 6-2 4-2 11-5 4-11 11-6 17-16",
 "0-18 13-18 16-0 3-7 14-12 3-1 19-18 3-19 10-3 8-15",
 "18-19 3-16 13-6 0-19 12-14 5-17 1-12 7-13 9-14 1-2",
 "14-5 17-9 2-10 16-13 11-15 10-17 14-10 0-14 2-13",
 "4-5 0-17 6-9 17-7 12-6 5-6 6-18 10-18 0-2 13-0 8-4",
 "3-12 4-11 10-17 13-12 3-0 3-7 13-0 9-15 10-9 0-10" }; 
 vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
string Arr1[] = {"592 219 88 529 324 86 503 610",
 "2 94 8 600 34 95 6 494",
 "638 301 10 246 290 97 85 74",
 "118 8 939 393 450 79 317 99",
 "99 806 698 740 2 26 525 818",
 "95 9 615 972 23 23 5 666",
 "6 448 440 710 83 4 419 496",
 "4 47 182 4 185 70 718 770",
 "3 321 6 855 968 65 10 6",
 "173 224 300 3 79 2 707 49",
 "21 10 7 10 4 9 5 8",
 "6 600 4 724 7 1 960 247",
 "83 16 901 50 437 780 658 2",
 "763 923 125 576 45 423 3 1",
 "7 324 391 898 8 59 281 973",
 "9 44 49 364 78 744 43 5",
 "10 62 75 418 216 90 32 919",
 "764 534 778 605 80 647 821 74",
 "65 449 102 867 421 94 6 7",
 "67 155 362 789 189 316 107 595" }
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
int Arr2[] = { 170,  160,  155,  173,  145,  150,  158,  168,  153,  145,  162,  88,  162,  86,  163,  159,  153,  150,  104 }; 
vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, costs(Arg0, Arg1)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        IslandFerries ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
