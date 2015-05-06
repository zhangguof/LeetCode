#-*- coding:utf-8 -*-

#problem
# Given a string containing only digits, restore it by returning all possible valid IP address combinations.

# For example:
# Given "25525511135",

# return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)


class Solution:
    # @param {string} s
    # @return {string[]}
    def restoreIpAddresses(self, s):
        n = len(s)
        if n > 12:
        	return []
        if n == 4:
        	return [".".join(list(s))]
        ret = []
        #print n

        for i in xrange(1,n-2):
        	a = s[:i]
        	if a[0] == "0" and len(a) > 1:
        		continue

        	a = int(a)
        	#print a
        	if a >= 0 and a<=255:
        		pass
        	else:
        		continue
        	for j in xrange(i+1, n-1):
        		#print "i:%s,j:%s"%(i,j)
        		b = s[i:j]
        		if b[0] == "0" and len(b)> 1:
        			continue
        		b = int(b)
        		if b >= 0 and b<=255:
        			#print "j:%s"%j,a
        			#print a,b
        			pass
        		else:
        			continue

        		for k in xrange(j+1,n):
        			c = s[j:k]
        			d = s[k:]
        			if (c[0] == "0" and len(c) > 1) or (d[0]=="0" and len(d)>1):
        				continue
        			c, d = int(c), int(d)
        			#print a,b,c,d
        			if c >= 0 and c<=255 and d>=0 and d<=255:
        				#print a,b,c,d
        				#ret.append(".".join([str(a),str(b),str(c),str(d)]))
        				ret.append(".".join([s[:i],s[i:j],s[j:k],s[k:]]))
        			else:
        				continue
        return ret

if __name__ == "__main__":
	sol = Solution()
	print sol.restoreIpAddresses("010010")