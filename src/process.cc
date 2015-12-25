#include "process.hh"

std::string int_to_binary(int x)
{
  auto binary = std::string("");
  int i = 0;
  while (i++ < 8)
  {
    binary += x % 2 + '0';
    x /= 2;
  }
  return binary;
}

int binary_to_int(const std::string& binary)
{
  int x = 0;
  for (unsigned i = 0; i < binary.size(); ++i)
  {
    if (binary[i] == '1')
      x += std::pow(2, i);
  }
  return x;
}

void change_pixel(unsigned char& a, bool pair)
{
  if (a == 255 && pair)
    a--;
  else if ((pair && a % 2 == 1) || (!pair && a % 2 == 0))
    a++;
}

void hide_text_in_image(Image& image, std::string text)
{
  int text_pos = -1;
  int text_size = text.size();
  std::string binary;
  auto binary_pos = 9;
  for (int x = 0; x < image.getWidth(); ++x)
  {
    for (int y = 0; y < image.getHeight(); ++y)
    {
      if (binary_pos == 9)
      {
        binary_pos = 0;
        binary = int_to_binary(int(text[++text_pos]));
      }
      if (text_pos >= text_size)
        return;

      //change pixel
      auto& pixel = image.getPixel(x, y);
      change_pixel(pixel[0], binary[binary_pos++] == '0');
      change_pixel(pixel[1], binary[binary_pos++] == '0');
      if (binary_pos <= 8)
        change_pixel(pixel[2], binary[binary_pos++] == '0');
    }
  }

  std::domain_error("Image not big enough to hide text");
}

std::string get_text_in_image(Image& image, unsigned text_size)
{
  std::string binary;
  std::string text;
  auto pixel_pos = 0;
  for (int x = 0; x < image.getWidth(); ++x)
  {
    for (int y = 0; y < image.getHeight(); ++y)
    {
      pixel_pos++;

      //get pixel letter
      auto& pixel = image.getPixel(x, y);
      binary += pixel[0] % 2 + '0';
      binary += pixel[1] % 2 + '0';
      if (pixel_pos != 3)
        binary += pixel[2] % 2 + '0';
      else
      {
        pixel_pos = 0;
        text += char(binary_to_int(binary));
        binary.clear();
        if (text.size() == text_size + 1)
          return text;
      }
    }
  }
  return text;
}
