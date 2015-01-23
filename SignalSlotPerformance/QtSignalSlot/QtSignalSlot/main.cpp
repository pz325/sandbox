
#include <QtCore/QCoreApplication>
#include "TestSendReceive.hpp"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TestSendThread pTestSend;
    TestReceiveThread pTestReceive;

    QObject::connect(&pTestSend, SIGNAL(send(int)), &pTestReceive, SLOT(onReceived(int)), Qt::DirectConnection);
    //QObject::connect(&pTestSend, SIGNAL(send(int)), &pTestReceive, SLOT(onReceived(int)), Qt::BlockingQueuedConnection);
    //QObject::connect(&pTestSend, SIGNAL(send(int)), &pTestReceive, SLOT(onReceived(int)), Qt::QueuedConnection);

    std::cout << boost::this_thread::get_id() << "]: start at " << boost::posix_time::microsec_clock::local_time() << std::endl;  
    pTestReceive.start();
    pTestSend.doSend();
    pTestReceive.stop();
    
    return a.exec();
}
