#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int steps = 0;
        
        if(grid.size()==0 || grid[0].size()==0)
        {
            return -1;
        }
        
        vector<tuple<int,int,int>> queue;
        
        for(int i=0;i<grid.size();i++)
        {
            for (int j = 0;j<grid[i].size();j++)
            {
                if(grid[i][j]==2)
                {
                    tuple<int,int,int> next_node = make_tuple(i,j,0);
                    queue.push_back(next_node);
                }
            }
        }
        
        int max_days =0;
        while(!queue.empty())
        {
            tuple<int,int,int> next_node = queue[0];
            queue.erase(queue.begin());
            int i = get<0>(next_node), j= get<1>(next_node);
            steps =  get<2>(next_node);
           
            // Rot the oranges
            int directions[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};

            for(int* dir: directions)
            {
                int new_i = i+dir[0], new_j = j+dir[1];
                if(new_i>=0 && new_i<grid.size() && new_j>=0 && new_j<grid[0].size())
                {

                    // If the node is not visited yet
                    if(grid[new_i][new_j]==1)
                    {
                        // Set the node to visited
                        grid[new_i][new_j]=2;
                        tuple<int,int,int> next_node = make_tuple(new_i,new_j,steps+1);
                        queue.push_back(next_node);
                    }
                }
            }
            if(steps> max_days)
            max_days = steps;
        }
        
        return max_days;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout<<"Final Solution:"<<sol.orangesRotting(grid);
    cout<<"End"<<endl;
    return 0;
}