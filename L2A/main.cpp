/* CSCI 200: Lab 2A: 2A - The Secret Moosage
 *
 * Author: Katrina Ngo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *
 * Reading a file with a ciphered message about the whereabouts of the cows
 * Deciphering the file by processing the input stream
 * Writing out the deciphered message in a new text file 
 */


#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream secretMessage("secretMessage.txt"); // declare ifstream object and open file
    ofstream decipheredMessage("decipheredMessage.txt"); // declare ofstream object and open file

    // check for error
    if (secretMessage.fail()) {
        cerr << "Error opening input file" << endl;
        return -1;
    }

    // read the file until the end of the secret message file
    char c;
    while (!secretMessage.eof()) {
    // decipher each character of the secret message file appropriately
    // and write it in the deciphered message file 
        secretMessage.get(c);
        if (c == '\n') {
            decipheredMessage << c;
        } else if (c == '~') {
            decipheredMessage << " ";
        } else {
            decipheredMessage << (char)(c + 1);
        }
    }

    // close both files
    secretMessage.close();
    decipheredMessage.close();
    return 0;
}