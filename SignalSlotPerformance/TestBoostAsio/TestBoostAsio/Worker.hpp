#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/signals2.hpp>
#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/function.hpp>

class Worker
{
public:
  explicit Worker(void)
    : ioServiceWork_(ioService_),
    pIOServiceThread_(0),
    threadId_(boost::lexical_cast<std::string>(boost::this_thread::get_id()))
  {
  }
  
  void start()
  {
    pIOServiceThread_ = new boost::thread(boost::bind(&boost::asio::io_service::run, &ioService_));
  }

  void stop()
  {
    ioService_.stop();
    pIOServiceThread_->join();
  }

  // slot
  void reset(int i)
  {
    // post the handle to io_service so to mimic async behaviour
    ioService_.post(boost::bind(&Worker::reset_, this, i)); 
    // if (i == 99999)
    //  std::cout << boost::this_thread::get_id() << "]: received " << i << " at " << boost::posix_time::microsec_clock::local_time() << std::endl;
  }

private:
  void reset_(int i)
  {
    if (i == 99999)
      std::cout << boost::this_thread::get_id() << "]: received " << i << " at " << boost::posix_time::microsec_clock::local_time() << std::endl;
  }

  boost::asio::io_service ioService_;
  boost::asio::io_service::work ioServiceWork_;
  boost::thread* pIOServiceThread_;
  std::string threadId_;
};