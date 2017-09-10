/*
 * Dispatcher.cpp
 *
 *  Created on: Jun 19, 2017
 *      Author: root
 */
#include <sstream>
#include "Dispatcher.h"
#include "Broker.h"
using namespace std;


namespace networkingLab {

Dispatcher::Dispatcher() {
	this->peers = new MultipleTCPSocketsListener();
	this->brokers = new vector<Broker*>();
	this->isRunning = true;
}


void Dispatcher::removeClientFromDispatcher(TCPSocket *client) {

	peers->removeSocket(client);
	cout << "Dispatcher: removing client" << "[" << client->fromAddr() << ":" << client->returnPort() << "]" << endl;
}

void Dispatcher::addClientToDispatcher(TCPSocket *client) {
	peers->addSocket(client);
	cout << "Dispatcher: client added" << endl << flush;
}

void Dispatcher::badRequest(TCPSocket* client) {

	sendErrorToClient(client, "Bad request");
	cout << "Server: bad command request from client" << "[" << client->fromAddr() << ":" << client->returnPort() << "]" << endl;
}

Dispatcher::~Dispatcher() {
	close();
	delete peers;
	delete brokers;
}

void Dispatcher::run() {
	while(isRunning){
		readFromClients();
	}
}

void Dispatcher::close() {
	this->isRunning = false;

}

void Dispatcher::sendErrorToClient(TCPSocket* client, string msg){
	string error = "ERROR: ";
	error.append(msg);
	client->write(error.c_str(),error.length());
}


void Dispatcher::removeBroker(Broker* broker) {

	vector<Broker*>::iterator begin = brokers->begin();
	vector<Broker*>::iterator end = brokers->end();

	for(; begin != end; ++begin){
		if((*begin) == broker){
			cout << "Dispatcher: erasing broker" << endl<<flush;
			brokers->erase(begin);
		}
	}
}

}

