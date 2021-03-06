#include <iostream>

#include "Canvas.hpp"

Canvas::Canvas(QWidget &parent, const QPoint &pos, const QSize &size, GameManager &engine) :
  QtCanvas(parent, pos, size, 60),
  _engine(engine)
{
}

void    Canvas::OnInit()
{
  _engine.popFood();
  std::cout << "Canvas init !" << std::endl;
}

void    Canvas::OnUpdate(QPainter &painter)
{
  DrawMap(painter, _engine.getLand());
  DrawSnakeBody(painter, _engine.getSnake().getBody());
  //DrawSnakeTongue(painter, QPoint(12, 10), RIGHT);
  DrawSnakeHead(painter, _engine.getSnake().getPos(),_engine.getSnake().getDir());
  if (_engine.getSnake().isDie())
    _t.stop();
}

void    Canvas::DrawMap(QPainter &painter, Land &land)
{
  QColor  green(qRgb(28, 120, 0));

  for (uint i = 0; i < land.width(); i++)
    for (uint j = 0; j < land.height(); j++)
    {
      painter.setBrush(green);
      painter.drawRect(i * land.unit(), j * land.unit(), land.unit(), land.unit());
      if (land.getCell(i, j).getContent() == 'f')
        DrawFood(painter, QPoint(i, j), land.unit());
    }
}

void    Canvas::DrawFood(QPainter &painter, const QPoint &p, uint s)
{
  QColor  red(qRgb(255, 0, 0));

  painter.setBrush(red);
  painter.drawEllipse(p.x() * s, p.y() * s, s, s);
}

void    Canvas::DrawSnakeBody(QPainter &painter, const Snake::Body &body)
{
  QColor  yellow(qRgb(254, 231, 0));
  uint    i = 0;
  qreal   delta = ((MAP_UNIT * 3) - MAP_UNIT) / ((qreal)body.size());

  //std::cout << "Delta body : " << delta << std::endl;

  painter.setBrush(yellow);
  while (i < body.size())
  {
    //qreal     size = ((MAP_UNIT) + (delta * i)) / 2;
    qreal       size = MAP_UNIT;
    QPointF   pos = QPointF(body[i].x() * MAP_UNIT + MAP_UNIT / 2 , body[i].y() * MAP_UNIT + MAP_UNIT / 2);
    painter.drawEllipse(pos, size, size);
    //std::cout << "Body[" << i << "] C(" << body[i].x() << "/" << body[i].y() << ") P(" << pos.x() << "/" << pos.y() << ") S(" << size << ")" << std::endl;
    ++i;
  };
  //system("PAUSE");
}

void    Canvas::DrawSnakeTongue(QPainter &painter, const QPoint &pos, Direction dir)
{
  /*painter.setBrush(QBrush(black_yellow));
  painter.drawEllipse(40, 25, MAP_UNIT * 2.5, MAP_UNIT * 2.5);
  painter.setBrush(QBrush(red));
  painter.drawEllipse(70, 40, MAP_UNIT, MAP_UNIT);*/
}

// not sure of the type of pos.x() and pos.y()
static uint calcPos(uint pos, uint u, bool b)
{
  return pos * u + u - (u * b + u / 4);
}

void    Canvas::DrawSnakeHead(QPainter &painter, const QPoint &pos, Direction dir)
{
  QColor	yellow(qRgb(254, 231, 0));
  QColor	black(qRgb(0, 0, 0));
  uint		u = MAP_UNIT;

  painter.setBrush(yellow);
  painter.drawEllipse((pos.x() * u) - u, (pos.y() * u) - u, u * 3, u * 3);
  painter.setBrush(QBrush(black));
  if (dir == RIGHT || dir == LEFT)
    {
      uint posX = calcPos(pos.x(), u, dir == LEFT);
      painter.drawEllipse(posX, calcPos(pos.y(), u, 1), u / 2, u / 2);
      painter.drawEllipse(posX, calcPos(pos.y(), u, 0), u / 2, u / 2);
    }
  else if (dir == BOTTOM || dir == TOP)
    {
      uint posY = calcPos(pos.y(), u, dir == TOP);
      painter.drawEllipse(calcPos(pos.x(), u, 1), posY, u / 2, u / 2);
      painter.drawEllipse(calcPos(pos.x(), u, 0), posY, u / 2, u / 2);
    }
  else
    {
      // throw error ?
    }
}
