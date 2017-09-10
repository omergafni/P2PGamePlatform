
#ifndef TCPCLIENT_H_
#define TCPCLIENT_H_

#include <stdio.h>
#include "TCPSocket.h"
#include "TCPRecvThread.h"

using namespace std;

namespace networkingLab {

class TCPClient {

protected:
	TCPSocket* socket;
	TCPRecvThread* tcpRecvThread;
public:
	TCPClient(int port);
    void setTCPRecvThread(TCPRecvThread* thread);
	virtual ~TCPClient();
    TCPSocket* getTcpSocket(){return socket;};
	bool open(string ip, int port);
	void send(string msg);
};

}

#endif
