#ifndef WUMPUS_FUNCTIONS_H
#define WUMPUS_FUNCTIONS_H
#include <string>

/**
 * @brief prompts user for .wgh file to open
 * 
 * @return string 
 */
std::string enter_wumpus_file();

/**
 * @brief prompts user for .log file to open
 * 
 * @return string 
 */
std::string enter_game_log_file();

/**
 * @brief Opens the corresponding files for reading and writing based on the file names provided. 
 * Verifies that both files successfully opened, returning true if so. 
 * Otherwise, if either file failed to open, returns false.
 * 
 * @param input 
 * @param output 
 * @param inputFile 
 * @param outputFile 
 * @return true 
 * @return false 
 */
bool open_files(std::ifstream& input, std::ofstream& output, std::string inputFile, std::string outputFile);

/**
 * @brief Reads the cave size information of the file (the first two values). 
 * Upon completion, the parameters corresponding to the width & height 
 * will match the values read from the file.
 * 
 * @param input 
 * @param caveWidth 
 * @param caveHeight 
 */
void read_world_header(std::ifstream& input, int& caveWidth, int& caveHeight);

/**
 * @brief Reads the object header information of the file (the next six values). 
 * Upon completion, the parameters corresponding to the (X, Y) location of each object 
 * will correspond to the values read from the file.
 * 
 * @param input 
 * @param xWump 
 * @param yWump 
 * @param xHero 
 * @param yHero 
 * @param xPit 
 * @param yPit 
 * @return true 
 * @return false 
 */
bool read_object_header(std::ifstream& input, int& xWump, int& yWump, int& xHero, 
                        int& yHero, int& xPit, int& yPit);

/**
 * @brief Reads the number of moves information of the file (the next values). 
 * Upon completion, the parameter corresponding to the number of moves 
 * will match the value read from the file.
 * 
 * @param input 
 * @param numMoves 
 */
void read_number_moves(std::ifstream& input, int& numMoves);

/**
 * @brief Prompts the user until they enter H to be the Hero or W to be the Wumpus.
 * 
 * @return true 
 * @return false 
 */
bool choose_player();

/**
 * @brief Simulates the game play as laid out in the input file and 
 * writes the game log to the output file.
 * 
 * @param input 
 * @param output 
 * @param caveWidth 
 * @param caveHeight 
 * @param numMoves 
 * @param xWump 
 * @param yWump 
 * @param xHero 
 * @param yHero 
 * @param xPit 
 * @param yPit 
 * @param isHero 
 */
void play_game(std::ifstream& input, std::ofstream& output, const int caveWidth, const int caveHeight, const int numMoves, 
                int& xWump, int& yWump, int& xHero, int& yHero, int& xPit, int& yPit, const bool isHero);

#endif