/*
 * MultipleTCPSocketsListener.h
 *
 *  Created on: May 27, 2017
 *      Author: root
 */

#ifndef SRC_MULTIPLETCPSOCKETSLISTENER_H_
#define SRC_MULTIPLETCPSOCKETSLISTENER_H_


#include <iostream>
#include <stdio.h>
#include <vector>
#include "TCPSocket.h"
using namespace std;


namespace networkingLab {


class MultipleTCPSocketsListener {

private:
	std::vector<TCPSocket*> socketVector;


public:
	MultipleTCPSocketsListener();
	virtual ~MultipleTCPSocketsListener();

	// Add the given socket to the socket list to be listen on
	void addSocket(TCPSocket* socket);

	// Set the given sockets to the socket list to be listen on
	void addSockets(vector<TCPSocket*> socketVec);

	/**
	 * This method checks to see if any of the previous given sockets are ready for reading
	 * It returns one of the Sockets that are ready.
	 */
	TCPSocket* listenToSocket();

	vector<TCPSocket*>* getSockets(){return &socketVector;}

	/**
	 * Use to find a socket in the sockets vector
	 * @param ip is the address of the client we are looking for
	 * @param port is the port of the client we are looking for
	 * @return is the TCP socket of the client we are looking for in the clients vector
	 */
	TCPSocket* findSocket(string ip, int port);

	bool removeSocket(TCPSocket* socket);

};

}

#endif
