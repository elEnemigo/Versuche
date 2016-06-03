/**
 * @file main.cpp
 *
 * Provides functions for the game Reversi
 */

/**
* @mainpage Reversi
*
* Dokumentation des Spiels Reversi im Rahmen des Praktikums Informatik 1.
*
*/

/**Defines the type of a player */
#define HUMAN 1
#define COMPUTER 2

#include "test.h"
#include "config.h"
#include "Reversi_KI.h"
#include <iostream>
#include <stdlib.h>

/**
 * @brief Function providing first initialization of a new field
 *
 * This function fills an existing field with zeros and creates the starting pattern.
 *
 * @param field The field which will be initialized
 */
void initialize_field(int field[SIZE_Y][SIZE_X])
{
	for (int j = 0; j < SIZE_Y; j++)
		{
			for(int i = 0; i < SIZE_X; i++)
			{
				field[j][i] = 0;
			}
		}
		field[SIZE_Y / 2 - 1][SIZE_X / 2 - 1] = 1;
		field[SIZE_Y / 2][SIZE_X / 2 - 1] = 2;
		field[SIZE_Y / 2 - 1][SIZE_X / 2] = 2;
		field[SIZE_Y / 2][SIZE_X / 2] = 1;
}



/**
* @brief Prints the playing field to the console.
*
* This function gets the current playing field as parameter (two dimensional array)
* with entries of 0 (field is empty), 1 (field belongs to player 1), 2 (field belongs to player 2).
* <br>The function prints the playing field, grid included, to the console.
* Crosses symbolize player 1 while circles symbolize player 2.
*
*  @param field  The field which is going to be printed
*/
void show_field(const int field[SIZE_Y][SIZE_X])
{
	std::cout << "  ";

//Start at ASCII 65 = A
	for (int j = 65; j < 65 + SIZE_Y; j++)
		std::cout << ((char) j) << " " ;

	std::cout << std::endl;

	for (int j = 0; j < SIZE_Y; j++)
	{
		std::cout << j + 1;
		for (int i = 0; i < SIZE_X; i++)
		{
			switch (field[j][i])
			{
				case 0:
					std::cout << "  " ;
					break;
				case 1:
					std::cout << " X";
					break;
				case 2:
					std::cout << " O";
					break;
				default:
					std::cout << "Inconsistent data in field!" << std::endl;
					std::cout << "Aborting .... " << std::endl;
					exit(0);
					break;
			}
		};//for i
		std::cout << std::endl;
	}//for j
}

/**
* @brief Checks the playing field for a winner.
*
* This function gets the current playing field as parameter (two dimensional array)
* with entries of 0 (field is empty), 1 (field belongs to player 1), 2 (field belongs to player 2).
* <br>The function counts each player's pieces, compares them and outputs the winner
* which is the player with the most stones on the given field.
*
*  @param field  The field which is going to be checked for a winner
*  @return Returns the winning player. Values are 0, 1 or 2 for a tie, first player winning
*           and second player winning, respectively
*/
int winner(const int field[SIZE_Y][SIZE_X])
{
	int count_p1 = 0;
	int count_p2 = 0;

	for (int j = 0; j < SIZE_Y; j++)
	{
		for (int i = 0; i < SIZE_X; i++)
		{
			//loop through all fields + counting of X (1) and O (2)
			if (field[j][i] == HUMAN)
                count_p1++;
            else if (field[j][i] == COMPUTER)
                count_p2++;
		}
	}
	if (count_p1 == count_p2)
	{
		return 0;
	}
	if (count_p2 > count_p1)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

/**
* @brief Checks whether a turn is possible.
*
* This function gets the current playing field, the corresponding player and a position as parameter
* <br>The function checks whether the proposed turn in 'field' is valid by determining if the placed piece ('pos_x' and 'pos_y')
* would result in enemy pieces being trapped between the player's ('player') pieces.
*
*  @param field  The field which is going to be checked
*  @param player  Player for whom to validate the turn
*  @param pos_x  X-position of the piece that 'player' wants to place
*  @param pos_y  Y-position of the piece that 'player' wants to place
*  @return Returns true if turn is valid and false if it is not
*/
bool turn_valid(const int field[SIZE_Y][SIZE_X], const int player, const int pos_x, const int pos_y)
{
	// Process all possible directions
	int opponent = 3 - player; // the same as: if player = 1 -> opponent = 2 else
							   // if player = 2 -> opponent = 1

	if (field[pos_y][pos_x] != 0) //check if field is currently empty
	{
		return false;
	}

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			//check if you can find an opponents stone in a neighboring field
			//then check if in this direction all stones are opponent stones until
			//the line is terminated by one of your own stone
			//in that case return true otherwise not
                if (field[pos_y + j][pos_x + i] != opponent)
					continue;

				int temp_y = pos_y;
				int temp_x = pos_x;
				while ((temp_x += i) >= 0 && temp_x < SIZE_X && (temp_y += j) >= 0 && temp_y < SIZE_Y)
				{
					if (field[temp_y][temp_x] == player)
						return true;
                    else if (field[temp_y][temp_x] == 0)
						break;
				}
		}
	}
	return false;
}

/**
* @brief Executes the turn chosen by a player.
*
* This function gets the current playing field, the corresponding player and a position as parameters
* <br>The function first checks whether the given turn is valid and then converts each enemy piece trapped
* between the player's pieces to its own.
*
*  @param field  The field which is going to be altered
*  @param player  Player for whom to execute the turn
*  @param pos_x  X-position of the piece that 'player' wants to place
*  @param pos_y  Y-position of the piece that 'player' wants to place
*/
void execute_turn(int field[SIZE_Y][SIZE_X], const int player, const int pos_x, const int pos_y)
{
    int opponent = 3 - player;
	// very similar to function "turn_valid" - just take care that all opponent
	// stones are changed to yours
	if (turn_valid(field, player, pos_x, pos_y))
    {
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
			//check if you can find an opponents stone in a neighboring field
			//then check if in this direction all stones are opponent stones until
			//the line is terminated by one of your own stone
			//in that case return true otherwise not
                if (field[pos_y + j][pos_x + i] != opponent)
					continue;

				int temp_y = pos_y;
				int temp_x = pos_x;
				int enemyPieces = 0;
				while ((temp_x += i) >= 0 && temp_x < SIZE_X && (temp_y += j) >= 0 && temp_y < SIZE_Y)
				{
				    enemyPieces++;
					if (field[temp_y][temp_x] == player)
                    {
                        for (int k = 1; k <= enemyPieces; k++)
                            field[temp_y + j*(-1)*k][temp_x + i*(-1)*k] = player;
                    }
                    else if (field[temp_y][temp_x] == 0)
						break;
				}
            }
        }
    }
}

/**
* @brief Calculate the number of possible turns a player may perform.
*
* This function gets the current playing field and the corresponding player as parameters.
* <br>The function counts all possible turns the 'player' may perform.
*
*  @param field  The corresponding field
*  @param player  Player for whom to calculate
*/
int possible_turns(const int field[SIZE_Y][SIZE_X], const int player)
{
    int numTurns = 0;

    for (int j = 0; j < SIZE_Y; j++)
    {
        for (int i = 0; i < SIZE_X; i++)
        {
            if (turn_valid(field, player, i, j))
                numTurns++;
        }
    }

	return numTurns;
}

/**
* @brief Processing player's input and executing their turn.
*
* The function processes the input of a player, checks whether the turn is valid
* and executes that turn if it is.
*
*  @param  field  The field that is being played on
*  @param  player  The player for whom to process these inputs
*  @return Returns true if there still are possible turns left to do for 'player'. Otherwise false
*/
bool human_turn(int field[SIZE_Y][SIZE_X], const int player)
{
	if (possible_turns(field, player) == 0)
	{
		return false;
	}

	int px;
	int py;
	bool repeat=false;

	while (true)
	{
		std::string input;
		input.reserve(50);
		std::cout << std::endl << "Your move (e.g. A1): " ;
		input.erase(input.begin(), input.end());
		std::cin >> input;
		px = ((int) input.at(0) ) - 65;
		py = ((int) input.at(1) ) - 49;

		if (turn_valid(field, player, px, py))
		{
			//accept turn;
			break;
		}
		else
		{
			std::cout << std::endl << "Invalid input !" << std::endl;
		}
	}

	execute_turn(field, player, px, py);

	return true;
}

/**
* @brief Game processing function.
*
* The function is the one processing the entire game, initializing everything,
* determining whose turn it is and printing the winner.
*
*  @param player_typ  1D-array of the type of each player (1=Human, 2=CPU)
*/
void game(const int player_typ[2])
{

	int field[SIZE_Y][SIZE_X];

	//Create starting pattern
	initialize_field(field);

	int current_player = 1;

	while (possible_turns(field, current_player) != 0)
    {
        show_field(field);
        //let each player make its moves until no further moves are possible
        if (current_player == 1)
            std::cout << "Player 1, it's your turn (X)" << std::endl;
        else
            std::cout << "Player 2, it's your turn (O)" << std::endl;
        if (player_typ[current_player-1] == HUMAN)
            human_turn(field, current_player);
        else
            computer_turn(field, current_player);

        current_player = 3 - current_player;
    }

	switch (winner(field))
	{
    case 1:
        std::cout << "Player 1 Won!" << std::endl;
        break;
    case 2:
        std::cout << "Player 2 Won!" << std::endl;
        break;
    case 0:
        std::cout << "It is a Tie!" << std::endl;
        break;
	}
}

/**
* @brief Entry point to the executable.
*
* The function is the entry point to this executable and thus is the first function
* to be called when the program is run. It tests all functions and runs the game.
*
*  @return Always returns 0 (which tells the OS the program ran successfully)
*/
int main(void)
{
	if (TEST == 1)
	{
		bool result = run_full_test();
		if (result == true)
		{
			std::cout << "ALL TESTS PASSED!" << std::endl;
		}
		else
		{
			std::cout << "TEST FAILED!" << std::endl;
		}
	}

	//int field[SIZE_Y][SIZE_X];

	//initialize_field(field);

	//show_field(field);

	bool bCont = true;
	while (bCont)
    {
        char choice;
        int player_type[2]; //Contains information whether players are HUMAN(=1) or COPMUTER(=2)
        std::cout << "\nStarting game..." << std::endl;
        std::cout << "Is Player 1 a Human (H) or Computer (C)? ";
        std::cin >> choice;
        switch (std::toupper(choice))
        {
        case 'H':
            player_type[0] = 1;
            break;
        case 'C':
            player_type[0] = 2;
            break;
        default:
            std::cout << "Invalid input, choosing computer instead!" << std::endl;
            player_type[0] = 2;
            break;
        }
        std::cout << "Is Player 2 a Human (H) or Computer (C)? ";
        std::cin >> choice;
        switch (std::toupper(choice))
        {
        case (int)'H':
            player_type[1] = 1;
            break;
        case 'C':
            player_type[1] = 2;
            break;
        default:
            std::cout << "Invalid input, choosing computer instead!" << std::endl;
            player_type[1] = 2;
            break;
        }

        game(player_type);

        std::cout << "Do you want to play another session (Y/N)? ";
        std::cin >> choice;
        switch (std::toupper(choice))
        {
        case 'Y':
            continue;
            break;
        case 'N':
            bCont = false;
            break;
        default:
            std::cout << "Invalid input, quitting..!" << std::endl;
            bCont = false;
            break;
        }
    }

	return 0;
}
