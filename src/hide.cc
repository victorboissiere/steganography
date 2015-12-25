#include <iostream>
#include <fstream>
#include "utils.hh"
#include "process.hh"

int main(int argc, char **argv)
{
  if (argc != 3)
  {
    std::cerr << "Usage : ./main image  file_of_text_to_hide\n";
    return 1;
  }
  //Load image
  auto image = Image(argv[1]);

  //load file content to hide
  std::ifstream file(argv[2]);
  if (!file.is_open())
  {
    std::cerr << "Cannot open file " << argv[2] << '\n';
    return 1;
  }
  std::string file_content((std::istreambuf_iterator<char>(file)),
                            std::istreambuf_iterator<char>());

  //hide text content
  hide_text_in_image(image, file_content);
  image.save("./output.png");

  std::cout << "Text hidden in ./.poutput.png.\n";

  return 0;
}
