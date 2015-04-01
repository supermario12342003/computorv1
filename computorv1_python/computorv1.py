#!/usr/bin/env python
import sys
import re
import pdb
term_pattern = "(\s*((\-|\+)?\s*([0-9]+|[0-9]+\.[0-9]))\s*\*\s*X\s*\^\s*([0-9]+)\s*)"
bonus_term_pattern = "(((\s*((\-|\+)?\s*([0-9]+|[0-9]+\.[0-9]))\s*\*)?\s*X\s*(\^\s*([0-9]+)\s*)?)|\s*([0-9]+|[0-9]+\.[0-9]))"
default_pattern = term_pattern + "+\=" + term_pattern + "+"
bonus_pattern = bonus_term_pattern + "+\=" + bonus_term_pattern + "+"

class Term:
	degree = 0
	multiplier = 1

	def __init__(self, multiplier, degree):
		self.multiplier = multiplier
		self.degree = degree
	
	def __str__(self):
		result = ""
		if self.multiplier < 0:
			result += "- " + str(-self.multiplier) + " * X ^ " + str(self.degree)
		else:
			result += "+ " + str(self.multiplier) + " * X ^ " + str(self.degree)
		return result

class Expression:
	terms = []
	highest = None

	def addTerm(self, multiplier, degree):
		multiplier = float(multiplier)
		degree = float(degree)
		if multiplier == 0:
			return
		degrees = [t.degree for t in self.terms]
		if degree in degrees:
			t = self.getTerm(degree)
			t.multiplier += multiplier
		else:
			term = Term(multiplier, degree)
			self.terms.append(term)

	def getTerm(self, degree):
		for t in self.terms:
			if t.degree == degree:
				return t
		return None

	def getTermMultiplier(self, degree):
		t = self.getTerm(degree)
		if t:
			return t.multiplier
		else:
			return 0

	def getHighestDegree(self):
		if self.highest != None:
			return self.highest
		else:
			self.highest = self.terms[0].degree
		for t in self.terms:
			if t.degree > self.highest:
				self.highest = t.degree
		return self.highest

	def solve(self):
		solutions = []
		if self.getHighestDegree() == 0:
			print "All the real number is a solution"
		elif self.getHighestDegree() == 1:
			self._solveDegree1()
		elif self.getHighestDegree() == 2:
			self._solveDegree2()
		else:
			print "The polynomial degree is stricly greater than 2, I can't solve."

	def _solveDegree1():
		b = self.getTermMultiplier(1)
		c = self.getTermMultiplier(0)
		print "The solution is:\n" + str(-c / b)

	def _solveDegree2(self):
		a = self.getTermMultiplier(2)
		b = self.getTermMultiplier(1)
		c = self.getTermMultiplier(0)
		discriminant = b * b - 4 * a * c
		if discriminant > 0:
			print "Discriminant is strictly positive, the two solutions are:"
			print str((-b + discriminant ** 0.5) / (2 * a))
			print str((-b - discriminant ** 0.5) / (2 * a))
		elif discriminant == 0:
			print "The solution is:\n" + str(-b / (2 * a))
		else:
			print "Discriminant is strictly negative, the two complex solutions are:"
			print str(-b / (2 * a)) + " - " + str(((-discriminant) ** 0.5) / (2 * a)) + "i"
			print str(-b / (2 * a)) + " + " + str(((-discriminant) ** 0.5) / (2 * a)) + "i"

	def __str__(self):
		result = ""
		self.terms = sorted(self.terms, key=lambda x:x.degree, reverse=True)
		for i, t in enumerate(self.terms):
			if result == "" and t.multiplier >= 0:
				result += str(t)[2:]
			else:
				result += str(t)
			result += " "
		result += "= 0"
		return result

def checkArgument():
	if len(sys.argv) != 2:
		print "usage: python computorv1.py EXPRESSION"
		exit(0)

def checkSyntax(exp):
	if not re.match(default_pattern, exp):
		print "error: Expression must be in \"n * X ^ p... = n * X ^ p ...\""
		exit(1)

def getExpression(exp):
	terms = re.findall(term_pattern, exp[:exp.index('=')])
	e = Expression()
	try:
		for t in terms:
			e.addTerm(t[1], t[4])
	except:
		print "error"
		exit(1)
	terms = re.findall(term_pattern, exp[exp.index('='):])
	for t in terms:
		e.addTerm(-float(t[1]), t[4])
	return e

def transform(exp):
	if not re.match(bonus_pattern, exp):
		print "not even bonus"
		exit(1)
	else:
		print "good"
		print re.findall("(\+?[^\+\-]+|\-?[^\+\-]+)+", exp[:exp.index('=')])
		exit(0)

def main():
	checkArgument()
	exp = transform(sys.argv[1])
	checkSyntax(exp)
	e = getExpression(sys.argv[1])
	print "Reduced form: " + str(e)
	print "Polynomial degree: " + str(e.getHighestDegree())
	e.solve()

if __name__ == "__main__":
	main()