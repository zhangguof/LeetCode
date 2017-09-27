#-*- coding:utf-8 -*-
#681. Next Closest Time

# Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

# You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

# Example 1:

# Input: "19:34"
# Output: "19:39"
# Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.
# Example 2:

# Input: "23:59"
# Output: "22:22"
# Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.

class Solution(object):
	def nextClosestTime(self, time):
		"""
		:type time: str
		:rtype: str
		"""
		DAY_MINS = 24*60
		def cal_time(st):
			h = int(st[0]) * 10 + int(st[1])
			m = int(st[2])*10 + int(st[3])
			if h >= 24 or m >= 60:
				return -1
			mins = h*60 + m
			return mins

		def dis_time(now_time,next_time):
			if next_time<=now_time:
				return DAY_MINS - now_time + next_time
			return next_time - now_time

		base = [time[0],time[1],time[3],time[4]]
		now = cal_time(base)
		self.min_time = 9999999
		self.resutl = None
		re = []
		def get_list(L,idx):
			if idx == 4:
				#re.append(list(L))
				nt = cal_time(L)

				if nt>=0:
					dt = dis_time(now,nt)
					if dt < self.min_time:
						self.min_time = dt
						self.resutl = list(L)
						#print L,dt
						
				return
			for a in base:
				L[idx] = a
				get_list(L,idx+1)
		get_list([-1,-1,-1,-1],0)
		r = self.resutl
		return "%s%s:%s%s"%(r[0],r[1],r[2],r[3])
		# return "%s%s:%s%s".format(r)



if __name__ == "__main__":
	sol = Solution()
	print sol.nextClosestTime("23:59")
	print sol.nextClosestTime("19:34")
	print sol.nextClosestTime("00:00")