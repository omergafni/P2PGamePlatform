/*
 * TCPServer.cpp
 *
 *  Created on: Jun 19, 2017
 *      Author: root
 */

#include "TCPServer.h"

using namespace std;

namespace networkingLab {


networkingLab::TCPServer::TCPServer(Dispatcher* dispatcher, int port) {
	this->dispatcher = dispatcher;
	this->isRunning = true;
	this->socket = new TCPSocket(port);
}

networkingLab::TCPServer::~TCPServer() {}

void networkingLab::TCPServer::run() {

	TCPSocket* connectedClient = NULL;
	cout << "server is alive and listening on port: " << socket->returnPort() << endl;

	while(isRunning){
		connectedClient = socket->listenAndAccept();
        dispatcher->addClientToDispatcher(connectedClient);
		cout << "Server: client connected [" << connectedClient->fromAddr() << ":" << connectedClient->returnPort() << "]" << endl;
	}
}

void networkingLab::TCPServer::close() {
	cout << "Server: closing server.." << endl;
	isRunning = false;
	dispatcher->close();
	cout << "dispatcher closed" << endl;
}

void TCPServer::startDispatcher() {
	this->dispatcher->start();
	cout << "Server: dispatcher started" << endl;
}

}

