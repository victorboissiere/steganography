#pragma once
#include "utils.hh"
#include <opencv2/opencv.hpp>


std::string int_to_binary(int x);
int binary_to_int(const std::string& binary);
void hide_text_in_image(Image& image, std::string text);
void change_pixel(unsigned char& pixel, bool pair);
std::string get_text_in_image(Image& image, unsigned text_size);
