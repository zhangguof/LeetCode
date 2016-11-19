#-*- coding:utf-8 -*-

# 190. Reverse Bits   QuestionEditorial Solution  My Submissions

# Reverse bits of a given 32 bits unsigned integer.

# For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), 
#return 964176192 (represented in binary as 00111001011110000010100101000000).

# Follow up:
# If this function is called many times, how would you optimize it?



class Solution:
	# @param n, an integer
	# @return an integer
	def reverseBits1(self, n):
		bit_n = 0
		r = 0
		while n:
			bit_n += 1
			r = (r<<1) + (n&1)
			n = n>>1
		r = r<<(32-bit_n)
		return r
	def reverseBits(self,n):
		# unsigned int v; // 32-bit word to reverse bit order

		# // swap odd and even bits
		# v = ((v >> 1) & 0x55555555) | ((v & 0x55555555) << 1);
		# // swap consecutive pairs
		# v = ((v >> 2) & 0x33333333) | ((v & 0x33333333) << 2);
		# // swap nibbles ... 
		# v = ((v >> 4) & 0x0F0F0F0F) | ((v & 0x0F0F0F0F) << 4);
		# // swap bytes
		# v = ((v >> 8) & 0x00FF00FF) | ((v & 0x00FF00FF) << 8);
		# // swap 2-byte long pairs
		# v = ( v >> 16             ) | ( v               << 16);

		# swap odd and even bits
		v = n
		v = ((v >> 1) & 0x55555555) | ((v & 0x55555555) << 1) 
		# swap consecutive pairs
		v = ((v >> 2) & 0x33333333) | ((v & 0x33333333) << 2) 
		# swap nibbles ... 
		v = ((v >> 4) & 0x0F0F0F0F) | ((v & 0x0F0F0F0F) << 4) 
		# swap bytes
		v = ((v >> 8) & 0x00FF00FF) | ((v & 0x00FF00FF) << 8) 
		# swap 2-byte long pairs
		v = (( v >> 16) & 0x0000FFFF) | (( v & 0x0000FFFF) << 16)
		#print bin(v),len(bin(v)),bin(n)
		return v



if __name__ == "__main__":
	sol = Solution()
	print sol.reverseBits(1)
	print sol.reverseBits(0)
	print sol.reverseBits(43261596)
	print sol.reverseBits(964176192)
            
