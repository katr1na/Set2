#ifndef COLOR_CONVERSION_H
#define COLOR_CONVERSION_H

/**
 * @brief converts RGB values to HSV values
 * 
 * @param red 
 * @param green 
 * @param blue 
 * @param hue 
 * @param sat 
 * @param value 
 */
void rgb_to_hsv(int red, int green, int blue, double& hue, double& sat, double& value);

/**
 * @brief converts HSV values to RGB values
 * 
 * @param hue 
 * @param sat 
 * @param value 
 * @param red 
 * @param green 
 * @param blue 
 */
void hsv_to_rgb(double hue, double sat, double value, int& red, int& green, int& blue);

#endif 