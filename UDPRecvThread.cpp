//
// Created by user on 11/09/17.
//

#include "UDPRecvThread.h"

namespace networkingLab {

    UDPRecvThread::UDPRecvThread(UDPSocket *socket, MessageHandler* msgHandler) {
        this->socket = socket;
        this->msgHandler = msgHandler;
    }

    UDPRecvThread::~UDPRecvThread() {

    }

    void UDPRecvThread::run() {
        isRunning = true;
        receiver(&socket);
    }

    void UDPRecvThread::receiver(void *args) {
        string message;
        while(isRunning){
            message = readFromClient(socket);
            msgHandler->handleMessage(message);
        }
    }

    void UDPRecvThread::stop() {
        isRunning = false;
    }

    string UDPRecvThread::readFromClient(UDPSocket *client) {
        char buff[1024];
        ::bzero(buff,sizeof(buff));
        client->read(buff,sizeof(buff));
        return string(buff);
    }
}
