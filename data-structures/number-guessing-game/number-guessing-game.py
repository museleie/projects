
#import packages needed
import numpy as np
import random as rand

#create a function to display the title information
def display_title():
  #display requirements
  print("This is the Guess the Number Game")
  print("This program will:")
  print("1. Display the title and program specifications")
  print("2. Next is it will play the game")
  print("3. The last part will be to use the main function to play the game\n\n")
  print("Do you want to play? Type in 'yes'\n\n")


#this function will play the game
def play_game():
  #print out details about starting the game
  print("Now let the game begin.\n\n")

  #begin creating the random number
  random_number = rand.randint(1, 100)
  print("I have a number between 1 and 100, what do you think it is?")

  #ask user for their guess of the random number
  guess = int(input("Enter your guess: "))

  #create a bool as False to enter the while loop
  solved = False

  #set counter to tally attempts
  counter = 1

  #as long as the puzzle is not solved, it will not exit the loop
  while ((solved is False) ):
    print(counter)
    #increment the counter
    counter += 1

    #if the guess is too high, print that out
    if guess > random_number:
      print("Too high")
      #have user continue their guessing
      guess = int(input("Enter your guess: "))
    #if the guess is too low, print that out
    elif guess < random_number:
      print("Too low")
      #have user continue their guessing
      guess = int(input("Enter your guess: "))
    else:
      #print out that the puzzle is solved
      print("You guessed it with " + str(counter) + " attemps!")
      #set bool as True, this will exit the while loop
      solved = True

  #this will exit the function
  return

#finding the number, use binary search to guarantee it taking 7 or less attempts. 
#Big O notation has it as: log(n) --> log base 2 of 100 ~ 6.69, so it should be found in 7 or less attempts
def reverse_game():
  #create an array to traverse all values frm 1 to 100
  arr = np.arange(1, 101)
  #low end of array
  low = 0
  #high end of array
  high = len(arr) - 1
  #middle value
  mid = 0
  #set bool to false, so it will be a fake infinite loop and exit when the condition is met
  solved=False
  #set a counter to start counting the tries
  counter=0
  while (solved is False):
    #increment the counter
    counter+=1
    #find the middle index
    mid = (high + low) // 2
    #ask if the middle index (with current set high and low endpoints) is the value
    guess=input("Is your value " +str(arr[mid])+"? Type 'yes' or 'no'")
    print("\n")
    if guess =='yes':
      print("\n")
      #print solved, the current index is the value
      print("Solved! Your number was "+str(arr[mid])+"! I solved it in " +str(counter)+" tries, good for me!")
      solved=True
    elif guess =='no':
      #determine to target the higher or lower arrays
      estimate=input("Was your value higher or lower than " +str(arr[mid])+"? Type 'h' or 'l'")
      
      if estimate =='h':
        #look at the right side of the array for the next values
        #set the new minimum above the previous middle index
        low = mid + 1
        print(str(low)+"\n")
      elif estimate =='l':
        #look at the left side of the array for the next values
        #set the new maximum below the previous middle index
        high = mid - 1
        print(str(high)+"\n")
      else:
        #validate correct input
        print("What is going on here... add a valid input. ")
        print("\n")
    else:
      #validate correct input
      print("Enter a valid input :) ")
      print("\n")
  return


#define the main
def main():
  #use the display_title function to display the information
  display_title()
  #ask the user for their yes input
  response = input()
  while(response =='yes'):
    game_type =input("To guess the computer's number, type 'user'. \n\n To have the computer guess your number, type 'computer' \n\n")
    if game_type =='user':
      play_game()
    else:
      reverse_game()
    #once the game is done, ask if user wants to play again
    response = input("Do you want to play again? Anything besides 'yes' will exit: ")
  #if the response is not yes, the while loop will exit
  print("You have exited. Goodbye!")



#execute the main function
if __name__ == "__main__":
  main()

