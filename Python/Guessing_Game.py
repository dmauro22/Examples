# Python 3.5 
#
# Guessing game  
#
# This program uses a random number generator and gives 
# hints when the player is close.  The range is 1 to 1000, 
# and the clue is given when the player is within 10 points 
# of the chosen number.
#
#
#


import random

# Function with hint calculator, displays when the guess is within 10 of the target number

def hint(target_number, target_guess):
	if target_number - target_guess > 10:
		print('low')
	elif target_number - target_guess <= 10 and target_number - target_guess > 0:
		print('warm, but a bit too low')
	elif target_guess - target_number <= 10 and target_guess - target_number > 0:
		print('warm, but a bit too high')
	elif target_guess - target_number > 10:
		print('high')

# Loop control

again = 'y'

guess_count = 1

# Define the game

while again == 'y' or again == 'Y':

	target_number = random.randint(1, 1000)
	target_guess = int(input('Guess any number from 1 to 1000: '))

	while target_guess != target_number:
		guess_count += 1
		hint(target_number, target_guess)
		target_guess = int(input('Guess again: '))


	print('We have a winner!!!')
	print('It took you ', guess_count,  ' tries')
	print('Would you like to play again? ')
	again = input('Y for yes: ')
	guess_count = 1
	target_guess = 0

