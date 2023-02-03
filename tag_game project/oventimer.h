#include <qpainter.h>
#include <qpixmap.h>
#include <qtimer.h>

#include <cmath>
using namespace std;

class OvenTimer : public QWidget
{
  Q_OBJECT

public:
  OvenTimer(QWidget *parent, const char *name = 0);

  void setDuration(int secs);
  int duration() const;
  void draw(QPainter *painter);

signals:
  void timeout();

protected:
  void paintEvent(QPaintEvent *event);
  void mousePressEvent(QMouseEvent *event);

private:
  QDateTime finishTime;
  QTimer *updateTimer;
  QTimer *finishTimer;
};
