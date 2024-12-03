#include <utility>
#include <random>
#include <set>
#include "grid.h"
#include "maze.h"
using namespace std;

/* Change constant kYourNetID to store your netID 
 *    - your submission will be manually inspected to ensure
 *      you have used the exact string that is your netID
 *    - thus, it is vital you understand what your netID is
 *    - ex: Professor Reckinger's email is scotreck@uic.edu, so
 *          Professor Reckinger's netID is scotreck     
 *    - ex: Professor Kidane's email is ekidan2@uic.edu, so
 *          Professor Kidane's netID is ekidan2     
 *    - ex: Student Sparky's email is sspark211@uic.edu, so
 *          Student Sparky's netID is sspark211 
 * WARNING: Once you've set set this constant and started 
 * exploring your maze, do NOT edit the value of kYourNetID. 
 * Changing kYourNetID will change which maze you get back, 
 * which might invalidate all your hard work!
 */
const string kYourNetID = "jbatr3";

/* Change these constants to contain the paths out of your mazes. */
const string kPathOutOfRegularMaze = "EEESSNNWSWSWNSSEE";
const string kPathOutOfTwistyMaze = "EENWEEWWWSEEENSNWNESNW";

bool isPathToFreedom(MazeCell *start, const string& moves) {
    if(start == NULL){
        return false; //Assume the start is not NULL
    } 
    //Tracks that we pick up all of these items to ensure a valid maze
    bool hasPotion = false;
    bool hasWand = false;
    bool hasSpellbook = false;
    
    MazeCell* current = start; //Starts at a given cell

    for(size_t i = 0; i < moves.size(); i++){ //Loops through the index
        char move = moves[i]; //Access the character at index i

        if(current->whatsHere == "Potion") hasPotion = true; //Picks up potion in the current
        if(current->whatsHere == "Wand") hasWand = true; //Picks up wand in the current
        if(current->whatsHere == "Spellbook") hasSpellbook = true; //Picks up spellbook in the current

        //Make sure the move is valid so NSEW
        if(move == 'N'){
            current = current->north;
        } else if (move == 'S') {
            current = current->south;
        } else if (move == 'E'){
            current = current->east;
        } else if(move == 'W'){
            current = current->west;
        } else {
            return false; //If the string contains anything other than NSEW, then false move
        }
        if(current == NULL){ //If the next move is invalid, then returns false. 
            return false;
        }
    }
    
    if(current->whatsHere == "Potion") hasPotion = true; //Picks up potion in the final cell
    if(current->whatsHere == "Wand") hasWand = true; //Picks up wand in the final cell
    if(current->whatsHere == "Spellbook") hasSpellbook = true; //Picks up spellbook in the final cell

    return hasPotion && hasWand && hasSpellbook; //Returns true for if all the items were collected.
}
