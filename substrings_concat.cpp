#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    
    void buildHashmap(map<string,int> & freq,const vector<string> & words)
    {
        // Build the hash table
        for(string word:words)
        {
            if(freq.find(word)!=freq.end())
                freq[word]+=1;
            else
                freq[word]=1;
        }
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int> result;
        
        if(words.size()==0 || s.empty())
            return result;
        
        int word_len = words[0].size(), total_words = words.size();
        int counter = total_words;
        int str_len = s.size();
        
        map<string,int> freq;
        
        buildHashmap(freq,words);
        
        // Start traversing the string
        int start = 0, end = word_len;
        int index=start;
        
        while(end<str_len)
        {
            if((counter)==total_words)
                index = start;

            cout<<"start:"<<start<<" end:"<<end<<endl;
            string sub_str = s.substr(start,end-start);
            cout<<"substring:"<<sub_str<<endl;
            
            // current word found in the given words
            if(freq.find(sub_str)!=freq.end() && freq[sub_str]>0)
            {
                cout<<"a given word"<<endl;
                freq[sub_str]--;
                counter--;
                
                // All words are seen
                if(counter==0)
                {
                    cout<<"Seen all words"<<endl;
                    // Add the index to result
                    result.push_back(index);
                    start++;
                    
                    counter = total_words;
                }
                else // Continue seeing next word
                {
                    start+= word_len;
                }

                end = start+word_len;
                continue;
            }
            else // Current word not a given word
            {
                cout<<"Not a given word"<<endl;
                start = index+1;
                end = start+word_len;
                counter = total_words;
                
                // Rebuild the hash map
                buildHashmap(freq,words);
            }
        }
        
        return result;
    }
};


int main()
{
    Solution sol;
    vector<string> words = {"foo","bar"};
    vector<int> result = sol.findSubstring("barfoothefoobarman",words);

    cout<<"Result"<<endl;
    for(int res:result)
    {
        cout<<res<<" ";
    }
    return 0;
}

// bar