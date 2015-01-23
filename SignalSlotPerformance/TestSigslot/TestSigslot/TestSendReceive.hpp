#pragma once
#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread.hpp>

#include "sigslot.h"

class TestSendThread
{
public:
  TestSendThread()
  {
  }
  
  void doSend()
  {
    for (int i = 0; i < 100000; i++)
    {
      send(i);
    }
  }

public:
  sigslot::signal1<int> send;
};
