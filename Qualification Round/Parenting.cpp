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
   timesaver;

    int cases, events = 0;
    cin >> cases;

    for(int test = 1; test <=cases ; test++)
    {
        cin >> events;

        // Pairs input start and end and then pairs with input number
        //it looks like pair((start,end)index)
        vector< pair< pair<int,int>, int > > input; 
        int start,end;
        for(int i = 0; i < events; i++)
        {
            cin >> start >> end;
           input.push_back(make_pair(make_pair(start,end),i));
        }

        // Uncomment if u want to see how input stored
        // for(auto it: input)
        //   cout << it.first.first <<" "<<it.first.second <<" "<< it.second << endl;
        
        sort(input.begin(),input.end());

        // Uncomment  below code if u want to see how input looks like after sorting
        // for(auto it: input)
        //   cout << it.first.first <<" "<<it.first.second <<" "<< it.second << endl;
        
        //Creates char array size events + 1, 
        //we need to add 1 to create extra 1 space for char '\0'
        //char arrays should end with '\0' to mark it is the end of array
        char result[events+1];
        // initialize variables with -1 
        //so when we compare first time they will be smaller
        int Jamie = -1;
        int Cameron = -1;
        
        bool impossible = false;

        for(int j = 0; j < events; j++)
        {   
            //if Cameron is free we assign to him 
            // ending time of the event
            // and place char C  at  events index 
            if(Cameron <= input[j].first.first)
            {
              Cameron = input[j].first.second;
              result[input[j].second] = 'C';
            }
            
             //if Jamie is free we assign to him 
            // ending time of the event
            // and place char J  at  events index in our res array
            else if(Jamie <= input[j].first.first)
            {
              Jamie = input[j].first.second;
              result[input[j].second] = 'J';
            }

            // In case both busy we mark the impossible flag true and break
            else 
            {
              impossible = true;
              break;
            }
        }

        // If impossible is true 
        if(impossible == true)
          cout << "Case #" << test<<": "<<"IMPOSSIBLE" << endl;
       
       //Else we append char '\0' at the end of our result array and print
        else {
          result[events]='\0';
          cout << "Case #" << test<<": "<< result << endl;
        }
    }


    return 0;
}