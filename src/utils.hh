#pragma once
#include <opencv2/opencv.hpp>
#include <string>

struct Color
{
  Color(int r, int g, int b);
  int r;
  int g;
  int b;
};

class Image
{
public:
  Image(const std::string& path);
  void show(const std::string& name) const;
  void waitKey() const;
  cv::Vec3b& getPixel(int x, int y);
  Color getColor(int x, int y) const;
  void setPixel(int x, int y, Color color);
  int getWidth() const;
  int getHeight() const;
  void save(const std::string path) const;
private:
  void check_coordinates_(int x, int y) const;
  cv::Mat image_;
};
