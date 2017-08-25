#-*- coding:utf-8 -*-

# 200. Number of Islands   QuestionEditorial Solution  My Submissions
# Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

# Example 1:

# 11110
# 11010
# 11000
# 00000
# Answer: 1

# Example 2:

# 11000
# 11000
# 00100
# 00011
# Answer: 3

def print_grid(grid):
	for r in grid:
		print "".join(r)

class Solution(object):
	def numIslands(self, grid):
		"""
		:type grid: List[List[str]]
		:rtype: int
		"""
		cnt = 0
		grid = [list(s) for s in grid]
		xsize = len(grid)
		if xsize == 0:
			return 0
		ysize = len(grid[0])


		
		while 1:
			find = False
			for i in xrange(0,xsize):
				for j in xrange(0,ysize):
					if grid[i][j] == "1":
						#self.depth_vistor(grid,i,j)
						self.Breadth_vistor(grid,i,j)
						#print "after 1"
						#print_grid(grid)
						#return
						
						cnt += 1
						find = True

			if not find:
				break
		return cnt

	def depth_vistor(self,grid,sx,sy):
		xsize = len(grid)
		ysize = len(grid[0])
		if sx >= xsize or sy >= ysize or sx<0 or sy <0:
			return
		grid[sx][sy] = "0"

		dir = [(0,1),(1,0),(0,-1),(-1,0)]
		for dx,dy in dir:
			x, y = sx+dx, sy+dy
			if x >= xsize or y >= ysize or x < 0 or y < 0 or grid[x][y]=="0":
				continue
			
			self.depth_vistor(grid,x,y)

	def Breadth_vistor(self,grid,sx,sy):
		from collections import deque
		xsize = len(grid)
		ysize = len(grid[0])
		

		que = deque(maxlen=xsize*ysize)
		dir = [(0,1),(1,0),(0,-1),(-1,0)]

		que.append((sx,sy))
		while len(que)!= 0:
			sx, sy = que.popleft()
			grid[sx][sy] = "0"
			# if sx==2 and sy==16:
			# 	print "in test"
			# 	print_grid(grid)
			# if sx==2 and sy==12:
			# 	print "in test2:",sx,sy
			# 	print_grid(grid)

			for dx, dy in dir:
				x,y = sx + dx, sy + dy
				if x >= xsize or y >= ysize or x < 0 or y < 0 or grid[x][y] != "1":
					continue
				que.append((x,y))
				grid[x][y] = "2"
			# if sx==2 and sy==12:
			# 	print "in test3:",sx,sy
			# 	print_grid(grid)




if __name__ == "__main__":
	sol = Solution()
	grid = ["11110","11010","11000","00000"]
	print sol.numIslands(grid)
	#print sol.numIslands(["11000","11000","00100","00011"])
	#print sol.numIslands([])