/*
 * Socket.cpp
 *
 *  Created on: May 19, 2017
 *      Author: root
 */

#include "Socket.h"

namespace networkingLab {

Socket::Socket(int style) {

	//style could be either SOCK_DGRAM or SOCK_STREAM
	socketType = style;
	sockfd = socket(AF_INET,style,0);
	if(sockfd < 0){
		perror("error opening socket");
		::close(sockfd);
		exit(1);
	}
    int optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);

}

Socket::~Socket() {
	close();
}

int Socket::bind(int port) {


	bzero((char *) &localAddr, sizeof(localAddr));
	localAddr.sin_family = (short)AF_INET;
	localAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	localAddr.sin_port = htons(port);

	return ::bind(sockfd, (struct sockaddr *)&localAddr, sizeof(localAddr));

}

/*
 * For UDP socket: the given IP will be stored into the remoteAddr structure for future use.
 *
 * */
int Socket::connect(string ip, int port) {

	bzero((char *) &remoteAddr, sizeof(remoteAddr));
	remoteAddr.sin_family = (short)AF_INET;
	remoteAddr.sin_port = htons(port);
	inet_aton(ip.c_str(),&remoteAddr.sin_addr);

	// If socket is TCP a connection will happen
	int ret;
	if(socketType == SOCK_STREAM){
		ret = ::connect(sockfd,(struct sockaddr*)&remoteAddr,(socklen_t)sizeof(remoteAddr));
		if(ret < 0){
				perror("error establishing communication");
				::close(sockfd);
				exit(1);
			}
			cout << "client is connected to ip: " << ip << " on port: " << port << endl;
	}

	return ret;

}

int Socket::getSockfd(){
	return this->sockfd;
}

void Socket::close(){

	::close(sockfd);
}

int Socket::returnPort() {

	return ntohs(localAddr.sin_port);
}


string Socket::fromAddr() {

	struct sockaddr_in sin;
	unsigned int addrlen = sizeof(sin);

	if(getsockname(sockfd, (struct sockaddr *)&sin, &addrlen) == 0 &&
			sin.sin_family == AF_INET &&
			addrlen == sizeof(sin))
	{
		return inet_ntoa(sin.sin_addr);
	}
	return NULL;
}



}

