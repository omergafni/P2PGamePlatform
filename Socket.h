/*
 * Socket.h
 *
 *  Created on: May 19, 2017
 *      Author: root
 */

#ifndef SRC_SOCKET_H_
#define SRC_SOCKET_H_

#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <netinet/in.h>
#include "FileInterface.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
using namespace std;

namespace networkingLab {

class Socket : public FileInterface {

protected:
	int sockfd;
	struct sockaddr_in localAddr;
	struct sockaddr_in remoteAddr;
	int socketType;


public:
	Socket(int style);
	virtual ~Socket();

	int bind(int port);
	int connect(string ip, int port);
	virtual void close(); // Override from FileInterface
	virtual int read(char* buff, int size) = 0;
	virtual int write(const char* msg, int length) = 0;
	int getSockfd();
	int returnPort();
	string fromAddr();

};

}

#endif




