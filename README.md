# Math-Game
Math Game With C++ 
# **Functions In The Game**
# 1 
Choosing Levels with validating the user input 
# 2 
answering question validation anything not a digit you enter will be ignored and if your answer is correct the text will be in green and if it's false the text will be in red **your answer can contain only dot (2.5)**
# 3
Play Again question validation if you enter anything not 1 or 2 will not accepted but if it's too long it will crash, yes repeat the whole cycle except for the welcoming text as it appears only one time when you open the game, and if no record screen will appear and exits
# 4 
Record Screen shows you the number of questions that were answered correctly and the number of questions that were answered incorrectly. It also shows the number of the whole questions.
with a green screen if you won and red screen if you lose and yellow screen if it's draw
# SOME PROBLEMS THAT I WASN'T ABLE TO SOLVE
# 1
In choosing the levels, entering a very large number causes a problem because when converting text to a number **stoi()**, the variable cannot contain this big number and causes a problem in the program
# 2
In asking to play again, entering a very large number causes a problem because when converting text to a number **stoi()**, the variable cannot contain this big number and causes a problem in the program
# 3
The First number is usually larger than the Second number as we don't need negative number because **cin.ignore()** consider negative sign (-) as not an integer 
# 4 
The Second number is usually not equal to zero in order to avoid the division by zero as my code makes the choosing of the operation randomly and I make a function that calculates the result and a function that gives numbers on easy, medium, hard, or insane choice so if I want to make it when it's division the levels will be implemented again in a special way so for now the **second number != 0**
