#ifndef NIBBLER_TEXCUBE_HPP_
# define NIBBLER_TEXCUBE_HPP_

#include <QtGui/QtGui>
#include <array>

#include "Point3D.hpp"

class TexCube
{
public:
  TexCube(float, float, float, float, uint);
  ~TexCube(void) {};

  void  draw();

private:
  float   _x;
  float   _y;
  float   _z;
  float   _s;
  uint    _id;
  std::vector<Point3D> _vertex;
  std::vector<QPointF> _tex;
};

#endif // !NIBBLER_TEXCUBE_HPP_
