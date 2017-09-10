/*
 * TCPRecvThread.h
 *
 *  Created on: May 10, 2017
 *      Author: root
 */

#ifndef TCPRECVTHREAD_H_
#define TCPRECVTHREAD_H_

#include "TCPSocket.h"
#include "RecvThread.h"
#include "MessageHandler.h"

namespace networkingLab {

class TCPRecvThread : public RecvThread {

protected:
	TCPSocket* socket;
	bool isRunning = true;
	MessageHandler *msgHandler;

public:
	TCPRecvThread(TCPSocket* socket, MessageHandler* msgHandler);
	virtual ~TCPRecvThread();

	virtual void run();
	virtual void receiver(void* args);
	virtual void stop();

	string readFromClient(TCPSocket *client);
};

}

#endif
