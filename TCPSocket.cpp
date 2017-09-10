#include "TCPSocket.h"
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

namespace networkingLab {

// Server C'TOR
TCPSocket::TCPSocket(int port) : Socket(SOCK_STREAM) {

	bind(port);
}


// Connected-peer C'TOR (building a TCPSocket for the accepted client)
TCPSocket::TCPSocket(struct sockaddr_in* server, int connected_sock) : Socket(SOCK_STREAM) {

	localAddr.sin_family = server->sin_family;
	localAddr.sin_port = server->sin_port;
	localAddr.sin_addr = server->sin_addr;
	this->sockfd = connected_sock;

}

TCPSocket::~TCPSocket() {

	close();
}

TCPSocket* TCPSocket::listenAndAccept(){

	listen(sockfd,1);
	socklen_t len = sizeof(localAddr);
	int connect_sock = accept(sockfd,(struct sockaddr*)&remoteAddr,&len);

	// Creating a new TCPSocket for the accepted client using the specified C'TOR
	TCPSocket* connected_client = new TCPSocket((struct sockaddr_in*)&remoteAddr,connect_sock);

	return connected_client;
}

int TCPSocket::read(char* buff, int size) {

	int ret = ::read(sockfd,buff,size);
	return ret;
}


int TCPSocket::write(const char* msg, int length) {
	int ret = ::write(sockfd,msg,length);
	return ret;
}


bool TCPSocket::equals(string ip, int port) {

	if(this->fromAddr() == ip && this->returnPort() == port)
		return true;
	return false;
}

bool TCPSocket::equals(Socket* socket) {
	return (this->sockfd == socket->getSockfd());
}

}

