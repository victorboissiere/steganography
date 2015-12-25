#include <iostream>
#include <opencv2/opencv.hpp>
#include "utils.hh"
#include "process.hh"
#include <string.h>

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cerr << "Usage : ./find image\n";
    return 1;
  }
  //Load image
  auto image = Image(argv[1]);
  
  auto nb_pixels = image.getWidth() * image.getHeight();
  auto hidden_text = get_text_in_image(image, nb_pixels);
  std::cout << hidden_text << '\n';
  return 0;
}
