class Solution:
    def numIslands(self, grid) -> int:

        counter = 1

        for i in range(len(grid)):

            for j in range(len(grid[i])):

                if int(grid[i][j])==1:

                    counter+=1
                    grid[i][j] = str(counter)

                if int(grid[i][j])>0:

                    # set the neighbours
                    if i>0 and grid[i-1][j]=='1':
                        grid[i-1][j]=str(counter)
                    if j>0 and grid[i][j-1]=='1':
                        grid[i][j-1]=str(counter)
                    if i<len(grid)-1 and grid[i+1][j]=='1':
                        grid[i+1][j]=str(counter)
                    if j<len(grid)-1 and grid[i][j+1]=='1':
                        grid[i][j-1]=str(counter)
                    if i>0 and j>0 and grid[i-1][j-1]=='1':
                        grid[i-1][j-1]=str(counter)
                    if i<len(grid)-1 and j<len(grid[i])-1 and grid[i+1][j+1]=='1':
                        grid[i+1][j+1]=str(counter)

        print(grid)
        return counter-1

input = [["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]
sol = Solution()
sol.numIslands(input)
