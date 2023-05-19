/* CSCI 200: Lab 2B: 2B - Color Space Converter
 *
 * Author: Katrina Ngo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *
 * Converts an RGB value to an HSV value or vice versa
 * User is prompted their choice of conversion and the appropriate values in order to convert
 */

#include <iostream>
#include <cmath>
#include "color_conversion.h"
using namespace std;

int main() {
    int red = 0;
    int green = 0;
    int blue = 0;
    double hue = 0;
    double sat = 0;
    double value = 0;
    int conversionDir = 0;

// prompts user for input on conversion direction and will only take in 1 or 2
    do {
        cout << "Please pick which conversion you'd like to do:" << endl << "(1) RGB --> HSV" << endl << "(2) HSV --> RGB" << endl << "Type in 1 or 2: ";
        cin >> conversionDir;
    } while (!(conversionDir == 1 || conversionDir == 2));

// prompts user for RGB values to convert to HSV
    if (conversionDir == 1) {
        do {
            cout << "Red Value: ";
            cin >> red;
            if (red < 0 || red > 255) {
                cerr << "Please enter a value between 0 and 255" << endl;
            } else {
                break;
            }
        } while (true);
        do {
            cout << "Green Value: ";
            cin >> green;
            if (green < 0 || green > 255) {
                cerr << "Please enter a value between 0 and 255" << endl;
            } else {
                break;
            }
        } while (true);
        do {
            cout << "Blue Value: ";
            cin >> blue;
            if (blue < 0 || blue > 255) {
                cerr << "Please enter a value between 0 and 255" << endl;
            } else {
                break;
            }
        } while (true);
        rgb_to_hsv(red, green, blue, hue, sat, value);
        cout << "HSV value: (" << hue << ", " << sat << ", " << value << ")" << endl;
        
// prompts user for HSV values to convert to RGB
    } else if (conversionDir == 2) {
        cout << "Please type in the HSV values you'd like to convert:" << endl;
        do {
            cout << "Hue: ";
            cin >> hue;
            if (green < 0 || green >= 360) {
                cerr << "Please enter a hue value between 0 and 360: ";
            } else {
                break;
            }
        } while(true);
        do {
            cout << "Saturation: ";
            cin >> sat;
            if (sat < 0 || sat > 1) {
                cerr << "Please enter a saturation value between 0 and 1: ";
            } else {
                break;
            }
        } while(true);
        do {
            cout << "Value: ";
            cin >> value;
            if (value < 0 || value > 1) {
                cerr << "Please enter a value between 0 and 1: ";
            } else {
                break;
            }
        } while(true);
        hsv_to_rgb(hue, sat, value, red, green, blue);
        cout << "RGB value: (" << red << ", " << green << ", " << blue << ")" << endl;
    }
}