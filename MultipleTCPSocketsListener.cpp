/*
 * MultipleTCPSocketsListener.cpp
 *
 *  Created on: May 27, 2017
 *      Author: root
 */

#include "MultipleTCPSocketsListener.h"

namespace networkingLab {

    MultipleTCPSocketsListener::MultipleTCPSocketsListener() {

    }

    MultipleTCPSocketsListener::~MultipleTCPSocketsListener() {

    }

// Add the given socket to the socket list to be listen on
    void MultipleTCPSocketsListener::addSocket(TCPSocket *socket) {

        std::vector<TCPSocket *>::iterator it = socketVector.end();
        this->socketVector.insert(it, socket);
    }

// Set the given sockets to the socket list to be listen on
    void MultipleTCPSocketsListener::addSockets(vector<TCPSocket *> socketVec) {
        this->socketVector = socketVec;
    }

/*
 * This method checks to see if any of the previous given sockets are ready for reading
 * It returns one of the Sockets that are ready.
 */
    TCPSocket *MultipleTCPSocketsListener::listenToSocket() {
        //cout << "MSL: start listening to sockets" << endl;
        // creates a local set for the select function (fd_set)
        fd_set masterfds;
        fd_set readfds;
        int fdmax = 0;
        FD_ZERO(&readfds);

        // fills the set with file descriptors from the socket list using FD_SET macro
        vector<TCPSocket *>::iterator it;
        for (it = socketVector.begin(); it != socketVector.end(); ++it) {
            FD_SET((*it)->getSockfd(), &masterfds);
            // tracking for the maximum fd
            if (fdmax < (*it)->getSockfd()) {
                fdmax = (*it)->getSockfd();
            }
        }

        struct timeval tv;
        tv.tv_sec = 3;
        tv.tv_usec = 0;

        // perform the select
        readfds = masterfds; // copying the masterfds to keep all sockfd's. select will change this fd_set
        if (select(fdmax + 1, &readfds, NULL, NULL, &tv) == -1) {
            perror("error in select");
            exit(1);
        }
        // now readfds contains ready-to-read sockets

        // checks the returned value from the select to find the socket that is ready
        // if select() return a valid socket, return the matching TCPSocket object, otherwise return NULL
        for (int i = 0; i < fdmax + 1; i++) {
            if (FD_ISSET(i, &readfds)) { // found a socket to read from..
                for (it = socketVector.begin(); it != socketVector.end(); ++it) {
                    if (i == (*it)->getSockfd()) {
                        //cout << "MSL: returning socket" << endl;
                        return (*it);
                    }
                }
            }
        }
        return NULL;
    }

    TCPSocket *MultipleTCPSocketsListener::findSocket(string ip, int port) {

        vector<TCPSocket *>::iterator begin = socketVector.begin();
        vector<TCPSocket *>::iterator end = socketVector.end();

        for (; begin != end; ++begin) {
            if ((*begin)->equals(ip, port)) {
                return (*begin);
            }
        }
        return NULL;
    }

    bool MultipleTCPSocketsListener::removeSocket(TCPSocket *socket) {

        vector<TCPSocket *>::iterator begin = socketVector.begin();
        vector<TCPSocket *>::iterator end = socketVector.end();

        for (; begin != end; ++begin) {
            if ((*begin)->equals(socket)) {
                socketVector.erase(begin);
                return true;
            }
        }
        return false;
    }

}

