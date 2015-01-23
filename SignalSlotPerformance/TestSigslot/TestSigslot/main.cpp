// TestSigslot.cpp : Defines the entry point for the console application.
//

#include "AsynSlot.h"
#include "TestSendReceive.hpp"

int main(int argc, char* argv[])
{
  TestSendThread testSend;
  
  AsynSlot asynSlot;
  testSend.send.connect(&asynSlot, &AsynSlot::reset);
  asynSlot.start();
  std::cout <<  boost::this_thread::get_id() << "]: start at " << boost::posix_time::microsec_clock::local_time() << std::endl;
  testSend.doSend();
  asynSlot.stop();
}

