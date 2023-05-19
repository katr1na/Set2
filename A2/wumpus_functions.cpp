/* CSCI 200: Assignment 2: A2 - Watch the Wumpus
 *
 * Author: Katrina Ngo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *
 * A game of Watch the Wumpus where the Hero has to hunt the Wumpus in a series
 * of moves while the Wumpus has to avoid the Hero.
 * Reads a game file and outputs a game log file.
 */

#include <fstream>
#include <iostream>
#include <string>
using namespace std;
#include "wumpus_functions.h"

string enter_wumpus_file() {
    string input;
    cout << "Enter wumpus file to read from: "; 
    cin >> input;
    return input;
}

string enter_game_log_file() {
    string input;
    cout << "Enter game log file to write to: ";
    cin >> input;
    return input; 
}

bool open_files(ifstream& input, ofstream& output, std::string inputFile, std::string outputFile) {
    input.open(inputFile);
    output.open(outputFile);
    if (input.fail() || output.fail()) {
        return false;
    } else {
        return true;
    }
}

void read_world_header(ifstream& input, int& caveWidth, int& caveHeight) {
    int value;
    input >> value;
    caveWidth = value;
    input >> value;
    caveHeight = value;
}

bool read_object_header(ifstream& input, int& xWump, int& yWump, int& xHero, 
                        int& yHero, int& xPit, int& yPit) {
    char c;
    for (int i = 0; i < 3; i++) {
        input >> c;
        if (c == 'W') {
            input >> xWump >> yWump;
        } else if (c == 'H') {
            input >> xHero >> yHero;
        } else if (c == 'P') {
            input >> xPit >> yPit;
        } else {
            return false;
        }
    }
    return true;
}

void read_number_moves(ifstream& input, int& numMoves) {
    input >> numMoves;
}

bool choose_player() {
    string player;
    cout << "Who do you wish to play as?" << endl << "        " << "H - Hero" << endl << "        " << "W - Wumpus" << endl << "Character: ";
    cin >> player;
    while (player != "H" && player != "W" && player != "h" && player != "w") {
        cout << "Invalid choice, please select again." << endl << "Character: ";
        cin >> player;
    }
    if (player == "H" || player == "h") {
        return true;
    } else {
        return false;
    }
}

void play_game(ifstream& input, ofstream& output, const int caveWidth, const int caveHeight, const int numMoves, 
                int& xWump, int& yWump, int& xHero, int& yHero, int& xPit, int& yPit, const bool isHero) {
    bool endOfGame = false;
    for (int i = 0; i < numMoves; i++) {
        char player, dir;
        input >> player >> dir;
        bool isOutsideCave = false;
        string outsideCaveDir;
        if (dir == 'N') {
            if (player == 'W' && ((yWump + 1) <= caveHeight)) {
                yWump++;
            } else if (player == 'H' && ((yHero + 1) <= caveHeight)){
                yHero++;
            } else {
                isOutsideCave = true;
                outsideCaveDir = "North";
            }
        } else if (dir == 'S') {
            if (player == 'W' && ((yWump - 1) >= 1)) {
                yWump--;
            } else if (player == 'H' && ((yHero - 1) >= 1)){
                yHero--;
            } else {
                isOutsideCave = true;
                outsideCaveDir = "South";
            }
        } else if (dir == 'E') {
            if (player == 'W' && ((xWump + 1) <= caveWidth)) {
                xWump++;
            } else if (player == 'H' && ((xHero + 1) <= caveWidth)){
                xHero++;
            } else {
                isOutsideCave = true;
                outsideCaveDir = "East";
            }
        } else if (dir == 'W') {
            if (player == 'W' && ((xWump - 1) >= 1)) {
                xWump--;
            } else if (player == 'H' && ((xHero - 1) >= 1)){
                xHero--;
            } else {
                isOutsideCave = true;
                outsideCaveDir = "West";
            }
        }
        
        bool wumpusFellInPit = false;
        bool heroFellInPit = false; 
        bool wumpusIsKilled = false;
        if (xWump == xPit && yWump == yPit) {
            wumpusFellInPit = true;
        } else if (xHero == xPit && yHero == yPit) {
            heroFellInPit = true;
        } else if (xWump == xHero && yWump == yHero) {
            wumpusIsKilled = true;
        }

        if (isHero) {
            if (wumpusFellInPit) {
                output << "The Wumpus is at (" << xWump << ", " << yWump << ")." << endl;
                output << "The Wumpus has fallen in the pit.  You win!" << endl;
                endOfGame = true;
                break;
            } else if (heroFellInPit) {
                output << "You are at (" << xHero << ", " << yHero << ")." << endl;
                output << "You have fallen in the pit.  You lose." << endl;
                endOfGame = true;
                break;
            }
            if (wumpusIsKilled) {
                output << "The Wumpus is at (" << xWump << ", " << yWump << ")." << endl;
                output << "You have killed the Wumpus.  You win!" << endl;
                endOfGame = true;
                break;
            }
            if (player == 'H') {
                if (isOutsideCave) {
                    output << "You cannot move " << outsideCaveDir << "." << endl;
                }
                output << "You are at (" << xHero << ", " << yHero << ")." << endl;
            } else {
                if (isOutsideCave) {
                    output << "The Wumpus cannot move " << outsideCaveDir << "." << endl;
                }
                output << "The Wumpus is at (" << xWump << ", " << yWump << ")." << endl;
            }
        } else {
            if (wumpusFellInPit) {
                output << "You are at (" << xWump << ", " << yWump << ")." << endl;
                output << "You have fallen in the pit.  You lose." << endl;
                endOfGame = true;
                break;
            } else if (heroFellInPit) {
                output << "The Hero is at (" << xHero << ", " << yHero << ")." << endl;
                output << "The Hero has fallen in the pit.  You win!" << endl;
                endOfGame = true;
                break;
            }
            if (wumpusIsKilled) {
                output << "You are at (" << xWump << ", " << yWump << ")." << endl;
                output << "You have been killed by the Hero.  You lose." << endl;
                endOfGame = true;
                break;
            }
            if (player == 'W') {
                if (isOutsideCave) {
                    output << "You cannot move " << outsideCaveDir << "." << endl;
                }
                output << "You are at (" << xWump << ", " << yWump << ")." << endl;
            } else {
                if (isOutsideCave) {
                    output << "The Hero cannot move " << outsideCaveDir << "." << endl;
                }
                output << "The Hero is at (" << xHero << ", " << yHero << ")." << endl;
            }
        }
    }
    if (!endOfGame) {
        if (isHero) {
            output << "The Wumpus has evaded you.  You lose." << endl;
        } else {
            output << "You have evaded the Hero.  You win!" << endl;
        }
    }
    input.close();
    output.close();
}