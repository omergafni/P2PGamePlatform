/*
 * UDPSocket.h
 *
 *  Created on: Apr 3, 2017
 *      Author: user
 */

#ifndef SRC_UDPSOCKET_H_
#define SRC_UDPSOCKET_H_
#include <strings.h>
#include <stdlib.h>
#include <iostream>
#include <netinet/in.h>
#include "Socket.h"

using namespace std;
namespace networkingLab {

class UDPSocket : public Socket {

private:

public:
	virtual ~UDPSocket();
	UDPSocket(int port = 9999);

	virtual int read(char* buff, int size);
	virtual int write(const char* msg, int length);
	int reply(string msg);

};

}

#endif
