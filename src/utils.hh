#pragma once
#include <opencv2/opencv.hpp>
#include <string>

/**
** Color structure to ease setting pixel color
*/
struct Color
{
  /**
  ** Basic constructor to set an RGB color
  */
  Color(int r, int g, int b);
  int r;
  int g;
  int b;
};

class Image
{
public:
  /**
  ** Open an opencv image at the given path
  */
  Image(const std::string& path);

  /**
  ** Show the image in a basic window
  */
  void show(const std::string& window_name) const;

  /**
  ** Wait for any key before executing the next line
  */
  void waitKey() const;

  /**
  ** Get pixel of an image at the position x y
  */
  cv::Vec3b& getPixel(int x, int y);

  /**
  ** Get the color of an image at the position x y
  */
  Color getColor(int x, int y) const;

  /**
  ** Set a pixel color at the position x y
  */
  void setPixel(int x, int y, Color color);

  /**
  ** Get image width
  */
  int getWidth() const;

  /**
  ** Get image height
  */
  int getHeight() const;

  /**
  ** Save the image at the given path
  */
  void save(const std::string path) const;
private:
  /**
  ** Check if coordinates are valid. If they are not, throw an exception
  */
  void check_coordinates_(int x, int y) const;

  /**
  ** Opencv image
  */
  cv::Mat image_;
};
