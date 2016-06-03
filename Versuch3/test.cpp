/**
 * @file test.cpp
 *
 * Provides a function for testing the program and some other functions in order to provide this.
 */

#include "test.h"
#include "config.h"

#include <iostream>


extern void show_field(const int field[SIZE_Y][SIZE_X]);
extern int winner(const int field[SIZE_Y][SIZE_X]);
extern bool turn_valid(const int field[SIZE_Y][SIZE_X],  const int player, const int pos_x, const int pos_y);
extern void execute_turn(int field[SIZE_Y][SIZE_X], const int player, const int pos_x, const int pos_y);
extern int possible_turns(const int field[SIZE_Y][SIZE_X], const int player);

/**
* @brief Tests the 'winner' function.
*
* This function gets the current playing field as parameter (two dimensional array)
* with entries of 0 (field is empty), 1 (field belongs to player 1), 2 (field belongs to player 2).
* <br>The function tests the 'winner' function by passing it a pre-created field and
* comparing its result with the pre-computed (correct) result given by the 'winner_code' parameter.
*
*  @param field  The field on which 'winner' is going to be called
*  @param winner_code  The correct winner
*  @return Returns true if 'winner' delivered expected result. Otherwise false
*/
bool test_winner(const int field[SIZE_Y][SIZE_X], const int winner_code)
{
	std::cout << "Running test for 'winner'..." << std::endl;
	std::cout << "----------------------------" << std::endl;
	show_field(field);
	std::cout << "Checking who wins" << std::endl;

	//Call winner-function
    int ret = winner(field);

	/* Check if result of winner function is correct and what you expected
	 *
	 * Return true for correct and false for wrong
	 *
	 * also print to the console if test was passed or not
	 */
	 if (ret == winner_code)
     {
         std::cout << "Test passed!" << std::endl;
         return true;
     }
     else
     {
         std::cout << "Test failed!" << std::endl;
         return true;
     }
}

/**
* @brief Tests the 'turn_valid' function.
*
* This function gets the current playing field, the corresponding player, a position and the correct result as parameters
* <br>The function tests the 'turn_valid' function by passing it the required parameters and
* comparing its result with the pre-computed (correct) result given by the 'valid' parameter.
*
*  @param field  The field on which 'turn_valid' is going to be called
*  @param player  Player for whom to validate the turn
*  @param pos_x  X-position of the piece that 'player' wants to place
*  @param pos_y  Y-position of the piece that 'player' wants to place
*  @param valid  The correct result
*  @return Returns true if function delivered expected result. Otherwise false
*/
bool test_turn_valid(const int field[SIZE_Y][SIZE_X], const int player, const int pos_x,
					 const int pos_y, const bool valid)
{
	// check for a given field whether a turn is valid
	std::cout << "Running test for 'turn_valid'..." << std::endl;
	std::cout << "----------------------------" << std::endl;
    show_field(field);

	bool result = turn_valid(field, player, pos_x, pos_y);
	if (result == valid)
	{
		std::cout << "Test passed!" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Test failed!" << std::endl;
		return false;
	}

	return 0;
}

/**
* @brief Tests the 'execute_turn' function.
*
* This function gets the current playing field, a reference field, the corresponding player, a position and the correct result as parameters
* <br>The function tests the 'execute_turn' function by passing it the required parameters and
* comparing its result with the pre-computed (correct) result given by the 'output' parameter.
*
*  @param input  The field on which 'execute_turn' is going to be called
*  @param output  The reference field to compare our results with
*  @param player  Player for whom to validate the turn
*  @param pos_x  X-position of the piece that 'player' wants to place
*  @param pos_y  Y-position of the piece that 'player' wants to place
*  @return Returns true if function delivered expected result. Otherwise false
*/
bool test_execute_turn(int input[SIZE_Y][SIZE_X], const int output[SIZE_Y][SIZE_X],
					   const int player, const int pos_x, const int pos_y)
{
	// check for a given field whether the execution of a turn is valid
    std::cout << "Running test for 'execute_turn'..." << std::endl;
	std::cout << "----------------------------" << std::endl;

	std::cout << "Before:" << std::endl;
    show_field(input);

	execute_turn(input, player, pos_x, pos_y);

    std::cout << "After:" << std::endl;
    show_field(input);

    std::cout << "Expected:" << std::endl;
    show_field(output);

    bool result = true;
	for (int j = 0; j < SIZE_Y; j++)
    {
        for (int i = 0; i < SIZE_X; i++)
        {
            if (input[j][i] != output[j][i])
            {
                result = false;
                break;
            }
        }
    }

	if (result == true)
	{
		std::cout << "Test passed!" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Test failed!" << std::endl;
		return false;
	}
}

/**
* @brief Tests the 'possible_turns' function.
*
* This function gets the current playing field, the corresponding player and the correct result as parameters.
* <br>The function tests the 'possible_turns' function by passing it the required parameters and
* comparing its result with the pre-computed (correct) result given by the 'count_possible_turns' parameter.
*
*  @param field  The field on which 'possible_turns' is going to be called
*  @param player  Player for whom to calculate possible turns
*  @param count_possible_turns  The correct result
*  @return Returns true if function delivered expected result. Otherwise false
*/
bool test_possible_turns(const int field[SIZE_Y][SIZE_X], const int player,
						 const int count_possible_turns)
{
	// very if your function finds all possible turns
    std::cout << "Running test for 'possible_turns'..." << std::endl;
	std::cout << "----------------------------" << std::endl;

    show_field(field);

	int result = possible_turns(field, player);
	std::cout << "Result: " << result << "  |  Expected: " << count_possible_turns << std::endl;

	if (result == count_possible_turns)
	{
		std::cout << "Test passed!" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Test failed!" << std::endl;
		return false;
	}
}

/**
* @brief Tests all the above functions.
*
* The function tests each of the above functions individually by providing them with
* pre-computed values and checking their return values.
*
*  @return Returns true if each tested function passed. Otherwise false
*/
bool run_full_test(void)
{
	bool result = true;


// ---------- CHECK WINNER ---------- //

	int winner_matrix[5][8][8]= {
			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 1, 0, 1, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},
			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 2, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 2, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 2, 0, 0, 0, 2, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
				},
				{   {0, 0, 0, 0, 0, 0, 0, 0},
 {0, 0, 1, 0, 2, 0, 0, 0},
 {0, 0, 0, 0, 0, 0, 2, 0},
 {0, 0, 0, 0, 0, 0, 0, 0},
 {0, 0, 0, 0, 0, 2, 0, 0},
 {0, 0, 2, 0, 0, 0, 0, 0},
 {0, 2, 0, 2, 0, 2, 0, 0},
 {0, 0, 0, 0, 0, 0, 0, 0}
},
{   {1, 1, 0, 0, 0, 0, 1, 0},
 {0, 0, 0, 0, 1, 0, 1, 0},
 {0, 0, 1, 0, 0, 0, 2, 0},
 {1, 0, 0, 0, 0, 1, 0, 0},
 {1, 0, 0, 1, 0, 0, 0, 0},
 {1, 2, 0, 0, 1, 2, 0, 0},
 {1, 0, 0, 0, 0, 1, 0, 0},
 {1, 0, 0, 0, 0, 0, 0, 0}
},
{   {0, 1, 0, 0, 0, 0, 1, 0},
 {0, 0, 2, 0, 0, 0, 0, 0},
 {0, 0, 2, 2, 0, 0, 0, 0},
 {0, 0, 2, 1, 0, 0, 0, 0},
 {0, 0, 2, 2, 0, 2, 0, 0},
 {0, 1, 0, 2, 0, 0, 0, 0},
 {0, 0, 0, 2, 0, 0, 0, 0},
 {0, 0, 0, 2, 0, 0, 0, 0}
}};

	int winner_code[5] = {1,2,2,1,2};

	for (int i = 0; i < 5; i++)
	{
		// TODO: Call the check function
        if(!test_winner(winner_matrix[i], winner_code[i]))
			result = false;
	}


// ---------- CHECK TURN VALID ---------- //

	int turnvalid_matrix[6][8][8] = {
			{   {1, 0, 2, 0, 0, 1, 1, 1},
				{0, 0, 2, 0, 0, 0, 0, 1},
				{0, 0, 0, 0, 0, 1, 2, 2},
				{2, 2, 0, 2, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 2, 0},
				{0, 0, 0, 2, 1, 1, 0, 2},
				{1, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 0, 1}
			},

			{   {1, 0, 2, 0, 0, 1, 1, 1},
				{0, 0, 2, 0, 0, 1, 0, 0},
				{0, 0, 2, 0, 0, 2, 1, 1},
				{0, 0, 0, 2, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 2, 0},
				{0, 0, 0, 2, 1, 1, 0, 2},
				{1, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 0, 1}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 2, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 1, 0, 0, 2, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 1, 0},
				{2, 0, 1, 2, 0, 2, 0, 0},
				{0, 2, 0, 2, 2, 2, 2, 2},
				{0, 0, 0, 0, 0, 0, 0, 1},
				{1, 0, 0, 0, 0, 2, 2, 2},
				{0, 2, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 1, 1, 1, 0, 0}
			},

			{   {2, 1, 0, 0, 2, 1, 1, 1},
				{0, 2, 0, 0, 0, 0, 0, 0},
				{1, 0, 0, 2, 0, 0, 0, 1},
				{0, 1, 1, 1, 0, 1, 0, 0},
				{1, 0, 0, 1, 1, 0, 0, 2},
				{0, 0, 0, 0, 0, 0, 0, 1},
				{1, 1, 0, 0, 0, 0, 2, 0},
				{1, 1, 2, 0, 0, 2, 2, 1}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			}
		};

	int turnvalid_player[6] = {1, 2, 2, 1, 2, 1};
	int turnvalid_pos[6][2] = { {2, 3}, {0, 3}, {4, 3}, {3, 4}, {3, 5}, {3, 4} };
	bool turnvalid_valid[6] = {0, 0, 0, 1, 1, 0};

	for (int i = 0; i < 6; i++)
	{
		// TODO: Call the check function
		if(!test_turn_valid(turnvalid_matrix[i], turnvalid_player[i], turnvalid_pos[i][0], turnvalid_pos[i][1], turnvalid_valid[i]))
			result = false;
	}


// ---------- CHECK EXECUTE TURN ---------- //

	int executeturn_matrix_in[9][8][8] = {
			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 2, 2},
				{2, 2, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 1, 1},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 2, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 1, 0},
				{0, 0, 0, 2, 0, 2, 0, 0},
				{0, 0, 0, 2, 2, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 2, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 1, 0, 0},
				{0, 0, 0, 1, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 1, 0},
				{0, 0, 0, 2, 0, 2, 0, 0},
				{0, 0, 0, 2, 2, 0, 0, 0},
				{0, 1, 2, 0, 2, 2, 1, 0},
				{0, 0, 0, 2, 2, 0, 0, 0},
				{0, 0, 0, 1, 0, 1, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 1, 1, 1, 1, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 2, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 0, 2, 1},
				{1, 0, 1, 1, 2, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			}
		};

	int executeturn_matrix_out[9][8][8] {
			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 2, 2},
				{2, 2, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 1, 1},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 2, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 1, 0},
				{0, 0, 0, 2, 0, 1, 0, 0},
				{0, 0, 0, 2, 1, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 2, 0, 0, 0, 0},
				{0, 0, 0, 2, 0, 1, 0, 0},
				{0, 0, 0, 2, 1, 0, 0, 0},
				{0, 0, 0, 2, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 1, 0},
				{0, 0, 0, 1, 0, 1, 0, 0},
				{0, 0, 0, 1, 1, 0, 0, 0},
				{0, 1, 1, 1, 1, 1, 1, 0},
				{0, 0, 0, 1, 1, 0, 0, 0},
				{0, 0, 0, 1, 0, 1, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 0, 0},
				{0, 0, 0, 0, 2, 0, 0, 0},
				{0, 0, 0, 2, 0, 0, 0, 0},
				{0, 0, 2, 1, 1, 1, 1, 0},
				{0, 0, 2, 0, 0, 0, 0, 0},
				{0, 0, 2, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 0, 2, 1},
				{1, 2, 2, 2, 2, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			}
		};

	int executeturn_player[9]={0,0,0,1,2,0,1,2,2};
	int executeturn_pos[9][2]={	{0,0},
					{0,0},
					{0,0},
					{3,4},
					{3,5},
					{0,0},
					{3,4},
					{2,4},
					{1,4}};

	for (int i = 0; i < 9; i++)
	{
		// TODO: Call the check function
		if(!test_execute_turn(executeturn_matrix_in[i], executeturn_matrix_out[i], executeturn_player[i], executeturn_pos[i][0], executeturn_pos[i][1]))
			result = false;
	}


// ---------- CHECK POSSIBLE TURNS ---------- //

	int possibleturns_matrix[2][8][8] {
			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 2, 0, 0, 0},
				{0, 0, 0, 2, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 2, 1, 0, 0, 0},
				{0, 0, 0, 2, 1, 1, 0, 0},
				{0, 0, 0, 2, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			}
		};

	int possibleturns_player[2] = {1, 1};
	int possibleturns_count[2] = {4, 5};

	for (int i = 0; i < 2; i++)
	{
		// TODO: Call the check function
		if(!test_possible_turns(possibleturns_matrix[i], possibleturns_player[i], possibleturns_count[i]))
            result = false;
	}

	return result;
}
