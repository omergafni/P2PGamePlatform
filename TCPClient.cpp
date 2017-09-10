/*
 * TCPClient.cpp
 *
 *  Created on: May 8, 2017
 *      Author: root
 */

#include "TCPClient.h"

namespace networkingLab {


    TCPClient::TCPClient(int port) {
        this->socket = new TCPSocket(port);
    }

    bool TCPClient::open(string ip, int port) {
        this->socket->connect(ip, port);
        if (socket != NULL) {
            tcpRecvThread->start();
            return true;
        }
        return false;
    }

    void TCPClient::send(string msg) {
        int wrote = this->socket->write(msg.c_str(), msg.size());
    }

    void TCPClient::setTCPRecvThread(TCPRecvThread *thread) {
        this->tcpRecvThread = thread;
    }


    TCPClient::~TCPClient() {
        if (socket != NULL) {
            tcpRecvThread->stop();
            delete socket;
        }
    }
}
