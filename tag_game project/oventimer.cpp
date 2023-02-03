

#include "oventimer.h"

const double DegreesPerMinute = 7.0;
const double DegreesPerSecond = DegreesPerMinute / 60;
const int MaxMinutes = 45;
const int MaxSeconds = MaxMinutes * 60;
const int UpdateInterval = 10;

OvenTimer::OvenTimer(QWidget *parent, const char *name)
    : QWidget(parent, name)
{
  finishTime = QDateTime::currentDateTime();
  updateTimer = new QTimer(this);
  finishTimer = new QTimer(this);
  connect(updateTimer, SIGNAL(timeout()), this, SLOT(update()));
  connect(finishTimer, SIGNAL(timeout()), this, SIGNAL(timeout()));
}
