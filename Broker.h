/*
 * Broker.h
 *
 *  Created on: Jun 19, 2017
 *      Author: root
 */

#ifndef BROKER_H_
#define BROKER_H_
#include "MThread.h"
#include "TCPSocket.h"
#include "MultipleTCPSocketsListener.h"
#include "ClientHandler.h"
using namespace std;

namespace networkingLab {

class Dispatcher;
class Broker : public MThread {

private:
		TCPSocket* client1;
		TCPSocket* client2;
		Dispatcher* dispatcher;
		ClientHandler* clientHandler;

public:
	/**
	 * Initiate a broker between two clients
	 * @param client1
	 * @param client2
	 * @param dispatcher is the sending dispatcher
	 */
	Broker(TCPSocket* client1, TCPSocket* client2, Dispatcher* dispatcher, ClientHandler* ch);
	virtual ~Broker();

	/**
	 * Start listening to request from the peers
	 */
	virtual void run();

	/**
	 * Close the session and return clients to the dispatcher
	 */
	void closeSession();


};

}

#endif /* BROKER_H_ */
