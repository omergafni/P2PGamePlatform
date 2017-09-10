/*
 * TCPRecvThread.cpp
 *
 *  Created on: May 10, 2017
 *      Author: root
 */

#include "TCPRecvThread.h"

namespace networkingLab {

    TCPRecvThread::TCPRecvThread(TCPSocket *socket, MessageHandler* msgHandler) {
        this->socket = socket;
        this->msgHandler = msgHandler;
    }

    TCPRecvThread::~TCPRecvThread() {}

    void TCPRecvThread::run() {
        isRunning = true;
        receiver(&socket);
    }

    void TCPRecvThread::receiver(void *args) {
        string message;
        while (isRunning) {
            message = readFromClient(socket);
            msgHandler->handleMessage(message);
        }
    }

    void TCPRecvThread::stop() {
        isRunning = false;
    }

    string TCPRecvThread::readFromClient(TCPSocket *client) {
        char buff[1024];
        ::bzero(buff,sizeof(buff));
        client->read(buff,sizeof(buff));
        return string(buff);
    }
}
