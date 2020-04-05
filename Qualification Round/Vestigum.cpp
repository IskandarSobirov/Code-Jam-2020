#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long ull;
#define timesaver  ios_base::sync_with_stdio(false); cin.tie(0)
#define min(a,b) a < b ? a:b;
#define max(a,b) a > b ? a:b;
const int mod = (int)1e9 + 7; 

ll arr[100][100];

//Calculates trace value
int trace(int n)
{
  int sum = 0;
  int i = 0, j = 0;

  //goes through matrix dioganal
  //from upper left to lower right
  while(i < n && j < n)
  {
      sum+=arr[i][j];
      i++,j++;
  }

  return sum;
}

int row = 0, col = 0;

void solve(int n)
{
 bool flag = false;

    //check each row of matrix if it has duplicates values
    for(int i = 0; i < n; i++)
    {
      set<int>st;
      flag = false;
      for(int j = 0; j < n; j++)
      {
          if(st.find(arr[i][j]) != st.end())
           {
             flag = true;
             break;
           }

          else st.insert(arr[i][j]); 
      }
        if(flag) row++;
    }

//check each col of matrix if it has duplicates values
  for(int i = 0; i < n; i++)
    {
      set<int>stcol;
      flag = false;
      for(int j = 0; j < n; j++)
      {
          if(stcol.find(arr[j][i]) != stcol.end())
           {
             flag = true;
             break;
           }

          else stcol.insert(arr[j][i]); 
      }
        if(flag) col++;
    }
}

int main()
{
    timesaver; 

    ll cases,n;

    cin >> cases;

   for(int cas = 1; cas <= cases; cas++)
   {
      cin >> n;

      
      for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
          cin >> arr[i][j];

      int trac = trace(n);
      solve(n);

      cout <<"Case #" <<cas<<": "<< trac <<" "<< row <<" "<<col <<endl;
     
     //reset them after each test case
      row = 0, col = 0;
        
   }

    return 0;
}
