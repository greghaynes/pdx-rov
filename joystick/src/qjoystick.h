#ifndef Q_JOYSTICK_H
#define Q_JOYSTICK_H

#include <QObject>
#include <QFileSystemWatcher>

#include <joystick.h>
#include <joystick.cpp>

class QJoystick
  : public QObject
  , public Joystick
{
  Q_OBJECT

  public:
    enum EventType
    {
      BUTTON,
      AXES
    };

    QJoystick(QObject *parent = 0);
    QString name();
    QString device();
    int numButtons();
    int numAxes();

  Q_SIGNALS:
    void eventOccoured(EventType type,
      unsigned char number,
      unsigned int time,
      short int value);
  
  private:s
    QFileSystemWatcher *filesysWatcher;

};

#endif Q_JOYSTICK_H