#include <iostream>
#include <opencv2/opencv.hpp>
#include "utils.hh"
#include "process.hh"
#include <string.h>

int main(int argc, char **argv)
{
  if (argc != 3)
  {
    std::cerr << "Usage : ./main image  file_of_text_to_hide\n";
    return 1;
  }
  auto image = Image(argv[1]);

  hide_text_in_image(image, argv[2]);
  image.save("./output.png");
  image = Image("./output.png");

  std::cout << "Text hidden in ./.poutput.png.\n";

  return 0;
}
