#include "color_conversion.h"
#include <cmath>
#include <iostream>
using namespace std;

void rgb_to_hsv(int red, int green, int blue, double& hue, double& sat, double& value) {
    const double PI = 3.1415926535;
    double min;
    double max;
    if (red > green && green >= blue) {
        max = red;
        min = blue;
    } else if (green > red && red >= blue) {
        max = green;
        min = blue;
    } else if (green > blue && blue >= red) {
        max = green;
        min = red;
    } else if (blue > green && green >= red) {
        max = blue;
        min = red;
    } else if (blue > red && red >= green) {
        max = blue;
        min = green;
    } else if (red > blue & blue >= green) {
        max = red;
        min = green;
    } else {
        min = red;
        max = red;
    }

    value = max / 255.0;
    if (max > 0) {
        sat = 1 - (min/max);
    } else {
        sat = 0;
    }
    if ((green == 0 && blue == 0) || (red == green && green == blue)) {
        hue = 0;
    } else if (green >= blue) {
        hue = acos((red-(0.5*green)-(0.5*blue))/(sqrt((red*red)+(green*green)+(blue*blue)-(red*green)-(red*blue)-(green*blue))));
        hue = hue*180/PI;
    } else {
        hue = 360 - (acos((red-(0.5*green)-(0.5*blue))/(sqrt((red*red)+(green*green)+(blue*blue)-(red*green)-(red*blue)-(green*blue))))*(180/PI));
    }

}

void hsv_to_rgb(double hue, double sat, double value, int& red, int& green, int& blue) {
    double max = 255 * value;
    double min = max*(1-sat);
    double z = abs((max - min)*(1-abs(remainder(hue/60, 2) - 1)));

    if (hue >= 0 && hue < 60) {
        red = max;
        green = z + min;
        blue = min;
    } else if (hue >= 60 && hue < 120) {
        red = z + min;
        green = max;
        blue = min;
    } else if (hue >= 120 && hue < 180) {
        red = min;
        green = max;
        blue = z + min;
    } else if (hue >= 180 && hue < 240) {
        red = min;
        green = z + min;
        blue = max;
    } else if (hue >= 240 && hue < 300) {
        red = z + min;
        green = min;
        blue = max;
    } else if (hue >= 300 && hue < 360) {
        red = max;
        green = min;
        blue = z + min;
    }

}