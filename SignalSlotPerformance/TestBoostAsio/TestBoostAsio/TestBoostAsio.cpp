#include "Worker.hpp"

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/signals2.hpp>
#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/function.hpp>

#include <stdlib.h>
#include <time.h>

int main()
{
  srand(static_cast<unsigned int>(time(0)));

  Worker w;
  w.start();
  
  boost::signals2::signal<void (int)> mainStateChangedSignal;
  mainStateChangedSignal.connect(boost::bind(&Worker::reset, &w, _1));
  
  int l = 0;
  std::cout << boost::this_thread::get_id() << "]: start at " << boost::posix_time::microsec_clock::local_time() << std::endl;  
  while (l < 100000)
  {
    w.reset(l);
    //mainStateChangedSignal(l);
    ++l;
  }

  w.stop();
}