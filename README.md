# Snakes and Ladders

### Overview
Simplified version of the game, consisting in a 30 square board, a dice and two players. The players will take turns to roll the dice and move across the board, taking account of the snakes (go back) and ladders (advance forward). 

### Compile Instructions
To compile the program, navigate to the src directory and run snakes.cpp, make sure all the files are in the same directory. 

### OOP Concepts Used

Encapsulation: 
- Dice: Encapsulates the logic for rolling a die
- Board: Including the initialization of squares and the type of square
- Player: Track of the player's position. 
- MyGame: Manages logic like player turns, game state, and interactions. 

Composition: 
- MyGame: Composed of Dice, Board, and Player objects. MyGame class relies
on these objects to function.

### Design Decisions
The code was divided in the classes previously mentioned for the organization of it. The snakes and ladders are places randomly every start of the game, so each game is unique. The program uses input and output for interaction. 

