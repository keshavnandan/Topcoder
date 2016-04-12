#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <cctype>
#include <map>
using namespace std;

class Poetry {
public:
	string rhymeScheme(vector <string>);
    string pattern(string s);
    bool isvowel(char x, int p, int n) {
        if(p == 0 || p == n-1)
        return    (x) == 'a' || (x) == 'e' || (x) == 'i' || (x) == 'o' || (x) == 'u';
        return    (x) == 'a' || (x) == 'e' || (x) == 'i' || (x) == 'o' || (x) == 'u' || (x) == 'y';
    }
};


string Poetry::pattern(string s){
    stringstream ss(s);
    string t = "", temp = "";
    while(ss>>temp) {
//        cout<<temp<<endl;
        t = temp;
    }
    for(int i = 0; i < t.size(); i++)
        if(isupper(t[i])) t[i] = t[i]-'A' + 'a';

    int n = t.size(); n--;
    while(n >= 0 &&!isvowel(t[n], n, t.size())) n--;
    while(n >= 0 && isvowel(t[n], n, t.size())) n--;
    return t.substr(n+1, t.size()-n-1);

}

string Poetry::rhymeScheme(vector <string> poem) {
    vector<char> ls(poem.size());
    map<string, char> ms;

    int c = 'a';
    for(int i = 0; i < poem.size(); i++){
        ls[i] = ' ';
        string s = pattern(poem[i]);
//        cout<<s;
        if(s.empty()) ls[i] = ' ';
        else{
            if(ms.count(s) == 0) ms[s] = char(c++);
            ls[i] = ms[s];
            }
        if(c == 'z' + 1) c = 'A';
    }

    string s = "";
    for(int i  = 0; i < ls.size(); i++){
         s.push_back(ls[i]);
     }
    return s;
}

int main(){
    string  sl[] =
{"     ",
 "Measure your height",
 "AND WEIGHT      ",
 "said the doctor",
 "",
 "And make sure to take your pills",
 "   to   cure   your    ills",
 "Every",
 "DAY"}
//{" aioimoxabufo   ", "  diilbblmrsfeeucqwikiiazhxeorpxgsewwheuuanrsgityy", "   azaiiaerefevpijiznha", "  hwxrtbueauakegbetuejsuaueeukv ", "eafearpeaieoudaaojaeeloukoonitwweadviyiucjvivyidvn", "", " ueoophcmiuwqfuuoaptueejrcigpahujoaadoeflhudzjaom", "", "", "", "  ", "luiaomzeatmadikduabaeeaehunxgiuoaaes", "", " ", "   amdboihaelhaeiuikejfeoauboosemooy     yuhwiah", "", "  auainpwemijcv", "uaioiufretouqghlactlpssqbeakb        ", "ttxukafxuuraquzarlubkkdonvioxeesaguhxmmumaeaeizaia", "avoeuogbqogciklhaavrcngstuielidelacwue ", "  yeelouhbxowtaoeahsjrihxftfttkvcrxurojacrurouryyp", "    ", "   ", "", " ", "  ", "       vuuvmosxiya", " ", "oiiczezkerkeneeiiefoooxxxtljidluqpilaohhabenay ", "", ""}
 ;
    vector<string> vs(sl, sl + sizeof(sl)/sizeof(sl[0]));
    cout<<"ans = \n"<<Poetry().rhymeScheme(vs);
//    cout<<Poetry().pattern("is a whole better than this");
}
