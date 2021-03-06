//
// Snake.hpp for  in /home/aubert_n/rep/nibbler/Nibbler5.0
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Sun Apr  6 12:21:34 2014 Nathan AUBERT
// Last update Sun Apr  6 12:21:35 2014 Nathan AUBERT
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
  const Direction     &getDir(void) const;
  const Body    &getBody(void) const;
  const bool    &isDie(void) const;

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
