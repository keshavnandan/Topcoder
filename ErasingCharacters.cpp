#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class ErasingCharacters
        {
        public:
        string simulate(string s)
            {
                int i = 0, n = s.size();
                while(i < n-1){
                    while(i < n-1 && s[i] != s[i+1]) i++;
                    if(i < n-1){
//                        cout<<i<<" "<<s[i]<<" "<<s[i+1]<<endl;
                        s = s.substr(0, i) + ( (i+2 < n) ? s.substr(i+2) : "" );
                        i = 0;
                    }
                    n = s.size();
                    if(n == 1)
                    break;
                }
                return s;
            }


        };
// Powered by CodeProcessor
