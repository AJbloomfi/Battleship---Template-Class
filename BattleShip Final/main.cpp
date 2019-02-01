//
//  main.cpp
//  Battleship Project
//
//  Created by Aaron Bloomfield on 10/10/18.
//  CPSC 340 Section 1
//
// This code is creation of BattleShip into code. The game will ask you if you would like to cheat
// then display the rules of the game, ask how many ships you would liek to face against, and then
// askf or coordinates on where to drop bombs. From there, you will either win by hitting all of the 
// ships or lose by running out of bombs.

#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <list>

#include "list.h"
#include "gameClass.h"

using namespace std;

int main(){
    int placeShip; //Creates a variable for how many ships the user would like to play with
    string answer; //Creates a variable to be inputted for if the player wants to cheat or not
    srand(10); //Generates a psuedo-random number
    int num;
    
    cout << "Do you want to cheat? (Y/N)" << endl;
    cin >> answer; //input for if the player wants to cheat
    
    gameClass game; //Creates a game and fills the boards
    game.rules(); //Displays the rules of the game
    
    cout << "How many ships would you like to play with? ";
    cin >> num; //input for how many ships the player wants
    
    int targetsOpen = (SIZE*2 + (num * 4)); //Determines how many bombs the player should have based off of 
                                                  //the ampunt of ships
     
    if(answer == "Y" || answer == "y"){
        for(int i=0; i<num; i++){
            game.placeShip(placeShip);   //Calls the place ship function and places the amount of ships the user requests
        }
        
        game.dispBoardCheat(); //Displays the contents of the Cheat Board
        game.dispBoard(); // Displays the contents of the user board
        
        game.dropBombCheat(targetsOpen); //Provides the user with the amount of bombs and Asks the user the locations of where they would like to drop the bombs and shows both the user board and cheat board
        
        
    }
    else{
        for(int i=0; i<num; i++){
            game.placeShip(placeShip); //Calls the place ship function and places the amount of ships the user requests
        }
        
        game.dispBoard(); //Displays the users board
        
        game.dropBomb(targetsOpen); //Provides the user with the amount of bombs and Asks the user the locations of where they would like to drop the bombs, only showing the user board
    }
    

    
    
}