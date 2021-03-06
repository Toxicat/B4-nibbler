//
// Land.hpp for  in /home/aubert_n/rep/nibbler/Nibbler4.0
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Thu Apr  3 21:32:32 2014 Nathan AUBERT
// Last update Thu Apr  3 21:32:32 2014 Nathan AUBERT
//

#ifndef NIBLER_LAND_HPP_
# define NIBLER_LAND_HPP_

#include "Cell.hpp"

class Land
{
public:
  Land(uint, uint, uint);
  ~Land();

  Cell  &getCell(const QPoint &);
  Cell  &getCell(uint, uint);

  uint  width() const;
  uint  height() const;
  uint  unit() const;

private:
  Cell  ***_land;
  uint  _width;
  uint  _height;
  uint  _unit;
};

#endif /* !NIBLER_LAND_HPP_ */
