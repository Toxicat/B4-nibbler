#include "Canvas.hpp"

# if defined(__GNUG__)
# define EXPORT /*Nothing to do here*/
#elif defined(_MSC_VER)
# define EXPORT __declspec(dllexport)
# else
#  error G++ or MS compiler required
#endif

extern "C"
{
  typedef std::deque<QPoint> SnakeBody;

  EXPORT Canvas   *newCanvas(QWidget &parent, const QPoint &pos, const QSize &size, const QPoint &head, const SnakeBody &body, const Direction &dir, const bool &die, char **&land) {
    return new Canvas(parent, pos, size, head, body, dir, die, land);
  };
  EXPORT void     showCanvas(Canvas *canvas) { canvas->show(); };
  EXPORT  void    deleteCanvas(Canvas *canvas) { delete canvas; };
}
