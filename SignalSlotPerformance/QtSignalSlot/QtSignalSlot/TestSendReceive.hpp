#include <QObject>
#include <QThread>
#include <QDebug>
#include <QDateTime>

#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread.hpp>

class TestSendThread: public QObject
  {
  Q_OBJECT
  public:
    TestSendThread()
      {
      }
    void doSend()
      {
      for (int i = 0; i < 100000; i++)
        {
          //qDebug() << QThread::currentThreadId() << "]:Send: " << i << " at " << QDateTime::currentMSecsSinceEpoch();
          emit send(i);
        }
      }
signals:
    void send(int i);  
  };
  

class TestReceiveThread: public QObject
  {
  Q_OBJECT
  public:
    TestReceiveThread()
      {
      moveToThread(&_thread);
      }
    void start()
      {
      _thread.start();
      }
    void stop()
      {
      _thread.wait();
      }
    public slots:
      void onReceived(int i)
        {
          if (i == 99999)
            std::cout << boost::this_thread::get_id() << "]: received " << i << " at " << boost::posix_time::microsec_clock::local_time() << std::endl;          
          // qDebug() << QThread::currentThreadId() << "]:Received: " << i << " at " << QTime::currentTime();
        }
  private:
    QThread _thread;

  };