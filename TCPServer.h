/*
 * TCPServer.h
 *
 *  Created on: Jun 19, 2017
 *      Author: root
 */

#ifndef TCPSERVER_H_
#define TCPSERVER_H_
#include "MThread.h"
#include "Dispatcher.h"

namespace networkingLab {

class TCPServer : public MThread {
protected:
	Dispatcher* dispatcher;
	bool isRunning;
	TCPSocket* socket;

public:
	TCPServer(Dispatcher* dispatcher, int port);
	virtual ~TCPServer();
	virtual void run();
	void close();
	void startDispatcher();
	virtual string serverWelcomeMessage() = 0;

};

}

#endif /* TCPSERVER_H_ */


