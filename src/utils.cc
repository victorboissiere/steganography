#include "utils.hh"


Color::Color(int r, int g, int b)
{
  this->r = r;
  this->g = g;
  this->b = b;
}

Image::Image(const std::string& path)
{
  image_ = cv::imread(path);

  if (!image_.data)
  {
    throw std::invalid_argument("Could not read data image.");
  }
}

void Image::show(const std::string& window_name) const
{
  cv::namedWindow(name, cv::WINDOW_AUTOSIZE);
  cv::imshow(name, image_);
}

void Image::waitKey() const
{
  cv::waitKey(0);
}

cv::Vec3b& Image::getPixel(int x, int y)
{
  check_coordinates_(x, y);
  return image_.at<cv::Vec3b>(x, y);
}

void Image::setPixel(int x, int y, Color color)
{
  check_coordinates_(x, y);
  image_.at<cv::Vec3b>(x, y)[0] = color.r;
  image_.at<cv::Vec3b>(x, y)[1] = color.g;
  image_.at<cv::Vec3b>(x, y)[2] = color.b;
}

int Image::getWidth() const
{
  return image_.rows;
}

int Image::getHeight() const
{
  return image_.cols;
}

void Image::check_coordinates_(int x, int y) const
{
  if (x < 0 || y < 0 || x >= getWidth() || y >= getHeight())
    throw std::invalid_argument("Invalid coordinates. Outside boundaries");
}

void Image::save(const std::string path) const
{
  if (!cv::imwrite(path, image_))
    std::runtime_error("Could not save file");
}
