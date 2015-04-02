#!/usr/bin/env python
import sys
from getExpression import getExpression, getExpressionBonus

def main():
	try:
		if len(sys.argv) != 2:
			print "usage: python computorv1.py EXPRESSION"
			exit(0)
		e = getExpressionBonus(sys.argv[1])
		#e = getExpression(sys.argv[1])
		print "Reduced form: " + str(e)
		print "Polynomial degree: " + str(e.getHighestDegree())
		e.solve()
	except Exception:
		print "error: Expression has syntax error or incompatible operation."

if __name__ == "__main__":
	main()