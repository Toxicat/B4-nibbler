//
// Snake.hpp for  in /home/aubert_n/rep/nibbler/Nibbler4.0
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Fri Apr  4 17:45:09 2014 Nathan AUBERT
// Last update Fri Apr  4 17:45:10 2014 Nathan AUBERT
//

#ifndef NIBLER_SNAKE_HPP_
# define NIBLER_SNAKE_HPP_
#include <QtCore/QtCore>
#include <deque>

#include "Nibbler.hpp"
#include "Land.hpp"

class Snake
{
public:
  typedef std::deque<QPoint> Body;

  Snake(const QPoint &, uint, Land &);
  ~Snake(void) {};

  const QPoint  &getPos(void) const;
  Direction     getDir(void) const;
  const Body    &getBody(void) const;
  bool          isDie(void) const;

  void  setPos(const QPoint &);
  void  setDir(Direction);

  void  addBody(void);
  void  move(const QPoint &);
  void  die(void);
  void  printMap();

private:
  Body        _body;
  QPoint      _pos;
  Direction   _dir;
  bool        _die;
  Land        &_land;
};

#endif /* !NIBLER_SNAKE_HPP_ */
