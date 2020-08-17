#include<iostream>
#include<vector>
using namespace std;
void mirrorReverse(vector<char>& s,int start, int n)
    {
        int i=start,end=n-1;

        while(i<end)
        {
            char temp = s[i];
            s[i]=s[end];
            
            s[end]=temp;
            i++;
            end--;
        }
    }
    
    void reverseWords(vector<char>& s) {
        
        int length = s.size();
        
        // Reverse the array
        mirrorReverse(s,0,length);

        int start=0,current=0;

        while(current<length)
        {
            if(s[current]==' ')
            {
                // Reverse the word
                
                mirrorReverse(s,start,current);
                start=current+1;
            }
            current++;
        }
        if(current==length)
            mirrorReverse(s,start,current);

    }


    int main()
    {
        vector<char> a = {'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};
        cout<<"Started";
        reverseWords(a);
        
        for(char c:a)
            cout<<c<<" ";

        return 0;
    }