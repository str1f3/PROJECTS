import random

minWhiteNumber = 1
maxWhiteNumber = 69
minRedNumber = 1
maxRedNumber = 26

whiteBall1 = random.randint(minWhiteNumber, maxWhiteNumber)
whiteBall2 = random.randint(minWhiteNumber, maxWhiteNumber)
whiteBall3 = random.randint(minWhiteNumber, maxWhiteNumber)
whiteBall4 = random.randint(minWhiteNumber, maxWhiteNumber)
whiteBall5 = random.randint(minWhiteNumber, maxWhiteNumber)


redBall = random.randint(minRedNumber, maxRedNumber)

print("WhiteBall #1 = " + str(whiteBall1))
print("WhiteBall #2 = " + str(whiteBall2))
print("WhiteBall #3 = " + str(whiteBall3))
print("WhiteBall #4 = " + str(whiteBall4))
print("WhiteBall #5 = " + str(whiteBall5))
print("PowerBall = " + str(redBall))
