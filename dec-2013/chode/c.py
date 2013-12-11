import sys

def generateAlphabet(text):
	dict = {}
	letters = ""	

	for c in text:
		c = c.lower()
		if str(c).isalpha():
			if c in dict:
				dict[c] = dict[c] + 1
			else:
				dict[c] = 1

	for letter in sorted(dict.items(), key=lambda x: (x[1], x[0])):
		letters = letters + letter[0]

	return letters.lower()

def appendMissingAlphabet(letters):
	alpha = set(['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'])
	missingLetters = alpha - set(letters)

	l = list(missingLetters)
	l.sort()

	return ''.join(l)


def main():
	tests = int(raw_input())

	for i in xrange(tests):
		el = list(raw_input())
		et = list(raw_input())

		ea = generateAlphabet(et)
		ea = appendMissingAlphabet(ea) + ea

		answer = ""

		for letter in et:
			originalLetter = letter
			letter = letter.lower()

			if letter in ea:
				islower = True

				if ord(originalLetter) >= 65 and ord(originalLetter) <= 90:
					islower = False

				if islower == True:
					answer = answer + el[ea.index(letter)]
				elif islower == False:
					answer = answer + el[ea.index(letter)].upper()
			else:
				answer = answer + letter	

		print answer

main()
