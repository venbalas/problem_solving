class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)

        print(matrix)

        # Transpose the matrix
        for i in range(n):
            for j in range(n):
                if i==j:
                    continue
                temp = matrix[i][j]
                matrix[i][j] = matrix[j][i]
                matrix[j][i] = temp
                # matrix[i][j], matrix[j][i]= matrix[j][i],matrix[i][j]
        
        # Invert the rows
        for i in range(n):
            for j in range(n):
                temp = matrix[i][j]
                matrix[i][j] = matrix[i][n-1-j]
                matrix[i][n-1-j] = temp
                # matrix[i][j],matrix[i][n-1-j]=matrix[i][n-1-j],matrix[i][j]

sol = Solution()
matrix = [[1,2,3],[4,5,6],[7,8,9]]
sol.rotate(matrix)
