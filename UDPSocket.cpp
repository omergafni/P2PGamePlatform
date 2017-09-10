/*
 * UDPSocket.cpp
 *
 *  Created on: Apr 3, 2017
 *      Author: user
 */

#include "UDPSocket.h"
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

namespace networkingLab {

UDPSocket::~UDPSocket() {
	close();
}


UDPSocket::UDPSocket(int port) : Socket(SOCK_DGRAM) {

	bind(port);
}




int UDPSocket::read(char* buff, int size){

	int ret;
	unsigned int size_a = sizeof(remoteAddr);
    ret = recvfrom(sockfd,buff,size,0,(struct sockaddr *)&remoteAddr,&size_a);

    if(ret < 0) {
    	printf("error in recv\n");
    }

	return ret;
}

int UDPSocket::write(const char* msg, int length){

	int ret;
	unsigned int size = sizeof(remoteAddr);

	ret = sendto(sockfd,msg,(unsigned int)length,0,(struct sockaddr *)&remoteAddr,size);
	if(ret < 0) {
		printf("error in sendTo\n");
	}

	return ret;
}


int UDPSocket::reply(string msg){

	int ret;
	unsigned int size = sizeof(remoteAddr);

	ret = sendto(sockfd,msg.c_str(),msg.length(),0,(struct sockaddr *)&remoteAddr,size);
	if(ret < 0){
		printf("error in reply\n");
	}

	return ret;
}


}
