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
			for t in self.terms:
				if t.multiplier == 0:
					self.terms.remove(t)
			if not self.terms:
				print "Infinite solution is possible."
				exit(0)
			self.highest = self.terms[0].degree
		for t in self.terms:
			if t.degree > self.highest and t.multiplier != 0:
				self.highest = t.degree
		return self.highest

	def solve(self):
		solutions = []
		if self.getHighestDegree() == 0:
			print "There is no solution"
		elif self.getHighestDegree() == 1:
			self._solveDegree1()
		elif self.getHighestDegree() == 2:
			self._solveDegree2()
		else:
			print "The polynomial degree is stricly greater than 2, I can't solve."

	def _solveDegree1(self):
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
		self.getHighestDegree()
		self.terms = sorted(self.terms, key=lambda x:x.degree, reverse=True)
		for i, t in enumerate(self.terms):
			if result == "" and t.multiplier >= 0:
				result += str(t)[2:]
			else:
				result += str(t)
			result += " "
		result += "= 0"
		return result