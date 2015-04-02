import re
from expression import Expression
import pdb

term_number = "(\s*(\-|\+)?\s*([0-9]+\.[0-9]+|[0-9]+)\s*)"
term_x = "(" + term_number + "\*\s*X\s*)"
term_power = "(" + term_x + "\^\s*([0-9]+)\s*)"
term_bonus = "(" + term_power + "|" + term_x + "|" + term_number + ")"
bonus_pattern = term_bonus + "+\=" + term_bonus + "+$"
default_pattern = term_power + "+\=" + term_power + "+$"
invalid_float = "[0-9]+\.[0-9]+\.[0-9]+"

def getExpression(exp):
	if not re.match(default_pattern, exp):
		print "error: Expression must be in \"n * X ^ p... = n * X ^ p ...\""
		exit(0)
	terms = re.findall(term_power, exp[:exp.index('=')])
	e = Expression()
	for t in terms:
		e.addTerm("".join(t[2].split()), "".join(t[5].split()))
	terms = re.findall(term_power, exp[exp.index('='):])
	for t in terms:
		e.addTerm(-float("".join(t[2].split())), "".join(t[5].split()))
	return e

def getExpressionBonus(exp):
	if not re.match(bonus_pattern, exp):
		print "error: Expression must be in \"n * X ^ p... = n * X ^ p ...\", p must be integer only"
		exit(0)
	else:
		if re.search(invalid_float, exp):
			print "error: Expression must be in \"n * X ^ p... = n * X ^ p ...\", n must be integer or valid float"
			exit(0)
		e = Expression()
		terms = re.findall(term_bonus, exp[:exp.index('=')])
		for t in terms:
			if (re.match(term_power, t[0])):
				e.addTerm("".join(t[3].split()), "".join(t[6].split()))
			elif (re.match(term_x, t[0])):
				e.addTerm("".join(t[8].split()), 1)
			elif re.match(term_number, t[0]):
				e.addTerm("".join(t[0].split()), 0)
				terms = re.findall(term_bonus, exp[:exp.index('=')])
		terms = re.findall(term_bonus, exp[exp.index('='):])
		for t in terms:
			if (re.match(term_power, t[0])):
				e.addTerm(-float("".join(t[3].split())), "".join(t[6].split()))
			elif (re.match(term_x, t[0])):
				e.addTerm(-float("".join(t[8].split())), 1)
			else:
				e.addTerm(-float("".join(t[0].split())), 0)
		return e