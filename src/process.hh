#pragma once
#include "utils.hh"
#include <opencv2/opencv.hpp>

/**
** Convert an int into a binary string (ie "01100001")
*/
std::string int_to_binary(int x);

/**
** Convert a binary string (ie "0110001") into an int
*/
int binary_to_int(const std::string& binary);

/**
** Hide the given text into an image
*/
void hide_text_in_image(Image& image, std::string text);

/**
** Change the lowest bit of a r,g or b color channel based on parity
** If it is even, set the lowest bit color to 0, else to 1
*/
void change_pixel(unsigned char& c, bool even);

/**
** Get the text hidden in an image
*/
std::string get_text_in_image(Image& image, unsigned text_size);
