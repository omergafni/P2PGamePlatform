/*
 * Broker.cpp
 *
 *  Created on: Jun 19, 2017
 *      Author: root
 */

#include "Broker.h"
#include "Dispatcher.h"

namespace networkingLab {


Broker::Broker(TCPSocket* client1, TCPSocket* client2, Dispatcher* dispatcher, ClientHandler* ch) {
	this->clientHandler = ch;
	this->client1 = client1;
	this->client2 = client2;
	this->dispatcher = dispatcher;
	cout << "[*] Broker started" << endl;
}

Broker::~Broker() {}

void Broker::run() {
	cout << "***** Calling handle clients from broker *****" << endl;
	clientHandler->handleClients();
    cout << "***** Finished handling clients in broker *****" << endl;
	closeSession();
}


void Broker::closeSession() {
	dispatcher->returnClientAfterSession(client1);
	dispatcher->returnClientAfterSession(client2);
	this->dispatcher->removeBroker(this);
}

}

