#pragma once
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/make_shared.hpp>
#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>


#include "sigslot.h"

class AsynSlot: public sigslot::has_slots<>
{
public:
  AsynSlot(void)
    : ioServiceWork_(ioService_)
  {
  }

  void start(void)
  {
    pIOServiceThread_ = boost::make_shared<boost::thread>(boost::bind(&boost::asio::io_service::run, &ioService_));
  }

  void stop(void)
  {
    ioService_.stop();
    pIOServiceThread_->join();
  }

// slot
  void reset(int i)
  {
    ioService_.post(boost::bind(&AsynSlot::reset_, this, i));
  }
private:
  void reset_(int i)
  {
    if (i == 99999)
    {
      std::cout << boost::this_thread::get_id() << "]: received " << i << " at " << boost::posix_time::microsec_clock::local_time() << std::endl;
    }
  }

  boost::asio::io_service ioService_;
  boost::asio::io_service::work ioServiceWork_;
  boost::shared_ptr<boost::thread> pIOServiceThread_;
};

