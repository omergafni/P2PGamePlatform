//
// Created by user on 11/09/17.
//

#ifndef P2PGAMEPLATFORM_UDPRECVTHREAD_H
#define P2PGAMEPLATFORM_UDPRECVTHREAD_H

#define SIZE 1024

#include "RecvThread.h"
#include "UDPSocket.h"
#include "MessageHandler.h"

namespace networkingLab {

    class UDPRecvThread : public RecvThread {

    protected:
        UDPSocket* socket;
        bool isRunning = true;
        MessageHandler* msgHandler;

    public:
        UDPRecvThread(UDPSocket* socket, MessageHandler* msgHandler);
        virtual ~UDPRecvThread();

        virtual void run();
        virtual void receiver(void* args);
        virtual void stop();

        string readFromClient(UDPSocket *client);
    };
}


#endif //P2PGAMEPLATFORM_UDPRECVTHREAD_H
