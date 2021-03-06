#include <iostream>
#include <cstdlib>
#include <ctime>

#include "GameManager.hpp"

GameManager::GameManager(uint width, uint height, uint unit) :
  _score(0),
  _old(QPoint(0, 0))
{
  _land = new Land(width, height, unit);
  _snake = new Snake(QPoint(width / 2, height / 2), 4, this->getLand());
  popFood();
  srand(time(NULL));
}
GameManager::~GameManager(void)
{
  std::cout << "GameManager say goodbye" << std::endl;
  delete _snake;
  delete _land;
}

Land    &GameManager::getLand()
{
  return *_land;
}

Snake   &GameManager::getSnake()
{
  return *_snake;
}

uint    GameManager::score() const
{
  return _score;
}

bool    GameManager::checkAround(uint x, uint y) const
{
  uint  t_x = (x > 0) ? (x - 1) : (x);
  uint  t_y = (y > 0) ? (y - 1) : (y);
  uint  b_x = (x < _land->width() - 1) ? (x + 1) : (x);
  uint  b_y = (y < _land->height() - 1) ? (y + 1) : (y);
  uint  i = t_x;
  uint  j;

  while (i < b_x)
  {
    j = t_y;
    while (j < b_y)
    {
      if (i != x && j != y)
      {
        if (_land->getCell(i, j) == 's')
          return false;
      }
      ++j;
    }
    ++i;
  }
  return true;
}

bool    GameManager::popFood()
{
  std::vector<QPoint> empty;
  uint                random;

  for (uint i = 1; i < _land->width() - 1; i++)
    for (uint j = 1; j < _land->height() - 1; j++)
      if (_land->getCell(i, j) == 0)
        if (checkAround(i, j))
          empty.push_back(QPoint(i, j));
  std::cout << "Free cells : " << empty.size() << std::endl;
  if (empty.size() == 0)
    return false;
  random = rand() % empty.size();
  std::cout << "Rand : " << random << std::endl;
  std::cout << "New apple in [" << empty[random].x() << "][" << empty[random].y() << "]" << std::endl;
  if (empty[random] != _old)
  {
    _land->getCell(empty[random]) = 'f';
    _old = empty[random];
  }
  else if (empty.size() <= 0)
    return false;
  else
    return (popFood());
  return true;
}
