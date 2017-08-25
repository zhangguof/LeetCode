#-*- coding:utf-8 -*-
# 54. Spiral Matrix
# Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

# For example,
# Given the following matrix:

# [
#  [ 1, 2, 3 ],
#  [ 4, 5, 6 ],
#  [ 7, 8, 9 ]
# ]
# You should return [1,2,3,6,9,8,7,4,5].

class Solution(object):
	def spiralOrder(self, matrix):
		"""
		:type matrix: List[List[int]]
		:rtype: List[int]
		"""
		if len(matrix)==0:
			return []
		direct = [(1,0),(0,1),(-1,0),(0,-1)]
		row_n, col_n = len(matrix),len(matrix[0])
		n = row_n * col_n
		R = []
		def vised(r,d_idx,x,y):
			d = direct[d_idx]
			if x < 0 or x>col_n or y<0 or y>row_n or len(r)==n:
				return
			
			r.append(matrix[y][x])
			matrix[y][x] = None
			
			while 1:
				nx, ny = x + d[0], y+d[1]
				if not (nx >= 0 and nx < col_n and ny>=0 and ny<row_n):
					break
				a = matrix[ny][nx]
				if a==None:
					break
				x,y = nx,ny
				r.append(a)
				matrix[y][x] = None

			d = direct[(d_idx+1)%4]
			x,y = x+d[0], y+d[1]
			vised(r,(d_idx+1)%4,x,y)
		vised(R,0,0,0)
		return R






	def spiralOrder1(self, matrix):
		"""
		:type matrix: List[List[int]]
		:rtype: List[int]
		"""
		R = []
		if len(matrix) == 0:
			return R
		row_n, col_n = len(matrix), len(matrix[0])
		direct = [(1,0),(0,1),(-1,0),(0,-1)]

		def vised(r,c,r0,r1,c0,c1,R,d_idx):
			d = direct[d_idx]
			if (d[1]!=0 and (r<r0 or r>r1)) or (d[0]!=0 and (c<c0 or c>c1)):
			#	print "oooooo:",r,c,r0,r1,c0,c1
				return

			R.append(matrix[r][c])
			nr,nc = r+d[1],c+d[0]
			#print r,c,matrix[r][c],nr,nc,(d[0],d[1])
			while (d[1] and nr<=r1 and nr>=r0) or (d[0] and nc <= c1 and nc >= c0):
				#print nr,nc,matrix[nr][nc]
				R.append(matrix[nr][nc])
				r,c = nr,nc
				nr,nc = r+d[1],c+d[0]
				
			if d[0] == 1:
				r0 = r0 +1
			elif d[0] == -1:
				r1 = r1 - 1

			if d[1] == 1:
				c1 = c1 - 1
			elif d[1] == -1:
				c0 = c0 + 1
				
			d = direct[(d_idx+1)%4]
			r,c = r+d[1],c+d[0]
			#print "aaaaa:",r,c,r0,r1,c0,c1

			vised(r,c,r0,r1,c0,c1,R,(d_idx+1)%4)
		vised(0,0,0,row_n-1,0,col_n-1,R,0)
		return R

		
if __name__ == "__main__":
	sol = Solution()
	m = [
		[ 1, 2, 3 ],
		[ 4, 5, 6 ],
		[ 7, 8, 9 ],
		]
	print sol.spiralOrder(m)
	m = [
		[1,2,3,4,5],
		[6,7,8,9,10],
	]
	#print sol.spiralOrder(m)
