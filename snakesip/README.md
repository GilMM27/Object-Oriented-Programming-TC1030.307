# Snakes and Ladders

### Overview
Simplified version of the game, consisting a square board, a dice and a number of players. The players will take turns to roll the dice and move across the board, taking account of the snakes (go back) and ladders (advance forward).

### Compile Instructions
To compile the program, navigate to the src directory and compile the files, make sure all the files are in the same directory.

Compile:
g++ main.cpp gameType.cpp dice.cpp mygame.cpp player.cpp -o executable

To run the executable:
./executable (8 parameters)

Should look something like this:
./executable 30 3 3 3 3 2 10 M

Parameters: 
Number of tiles, number of snake tiles, number of ladder tiles, penalty for landing in a snake tile, reward for landing in a ladder tile, number of players, maximum number of turns, game type (A for automatic and M for manual).

### OOP Concepts Used
Encapsulation: 
- Dice: Encapsulates the logic for rolling a die
- Player: Track of the player's position. 
- MyGame: Manages logic like player turns, game state, and interactions.
- gameType: Has the different implementations of myGame for manual and automatic modes.

Composition: 
- MyGame: Composed of Dice, Board, and Player objects. MyGame class relies
on these objects to function.

Inheritence:
- gameType: This is a file with two classes which both inherits from the base class MyGame and its main porpuse is to differienciate between the manual and automatic modes for the game.

Polymorphism
- gameType: The function play from MyGame is overrided in order to change its implementation for the manual and automatic modes.

### Design Decisions
The code was divided in the classes previously mentioned for the organization of it. The snakes and ladders are places randomly every start of the game, so each game is unique. The program uses standard input and output for interaction. 