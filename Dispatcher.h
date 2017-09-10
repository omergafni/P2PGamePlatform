/*
 * Dispatcher.h
 *
 *  Created on: Jun 19, 2017
 *      Author: root
 */

#ifndef DISPATCHER_H_
#define DISPATCHER_H_
#include <vector>
#include "TCPSocket.h"
#include "MThread.h"
#include "MultipleTCPSocketsListener.h"
#include "ClientHandler.h"
using namespace std;

namespace networkingLab {

class Broker;
class Dispatcher : public MThread {


protected:
	MultipleTCPSocketsListener* peers;
	vector<Broker*>* brokers;
	bool isRunning;

	/**
	 * Receive and parse messages from clients
	*/

	virtual void readFromClients() = 0;


	/**
	 * Performing "EXIT" request from client.
	 * @param client
	 */
	void removeClientFromDispatcher(TCPSocket *client);

	/**
	 * Handle a wrong request from client.
	 * @param client
	 */
	void badRequest(TCPSocket* client);

	/**
	 * Handle an error from a client request
	 * @param client is the client that will get the error
	 * @param msg is the error message
	 */
	void sendErrorToClient(TCPSocket* client, string msg);

public:
	Dispatcher();
	virtual ~Dispatcher();
	virtual string getInstructions() = 0;

	/**
	 * Start listening to request from the peers
	 */
	virtual void run();

	/**
	 * Adding a client to the clients pool
	 * @param client
	 */
	virtual void addClientToDispatcher(TCPSocket *client);

	/**
	 * Remove the broker from the brokers vector
	 * @param broker is the broker object to be removed
	 */

	virtual void returnClientAfterSession(TCPSocket* client)=0;
	void removeBroker(Broker* broker);

	/**
	 * Close the dispatcher
	 */
	virtual void close();

};

}

#endif /* DISPATCHER_H_ */
