#ifndef SRC_TCPSOCKET_H_
#define SRC_TCPSOCKET_H_

#include<strings.h>
#include<stdlib.h>
#include<iostream>
#include<netinet/in.h>
#include "Socket.h"

using namespace std;

namespace networkingLab {

class TCPSocket : public Socket {

private:

	TCPSocket(struct sockaddr_in* server, int connected_sock); // for the connected peer

public:
	TCPSocket(int port);
	virtual ~TCPSocket();

	virtual int read(char* buff, int size);
	virtual int write(const char* msg, int length);
	TCPSocket* listenAndAccept();
	bool equals(string ip, int port);
	bool equals(Socket* socket);


};



}




#endif
