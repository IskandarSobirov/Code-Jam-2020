#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long ull;
#define timesaver  ios_base::sync_with_stdio(false); cin.tie(0)
#define min(a,b) a < b ? a:b;
#define max(a,b) a > b ? a:b;
const int mod = (int)1e9 + 7; 


int main()
{
    int n;
    cin >> n;
    for(int  i = 1; i <= n; i++)
    {
     
      int digit = 0;
      int depth = 0;
      string res;
      string s;

        cin >> s;
        
        for(char i: s)
        {
            digit = i-'0';
            while(depth > digit)
            {
                res.push_back(')');
                depth--;
            }
            while(depth < digit)
            {
                res.push_back('(');
                depth++;
            }

            res.push_back(i);
        }
    //if  depth greater than 0 we need closing parentheses
    while(depth--)
        res.push_back(')');

      cout << "Case #" << i  << ": " << res << endl;
   }
  
    return 0;
}