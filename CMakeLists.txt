cmake_minimum_required(VERSION 3.7)
project(P2PGamePlatform)
find_package(Threads)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        ClientHandler.h
        Dispatcher.cpp Dispatcher.h
        FileInterface.h
        Guard.h
        MessageHandler.h
        MThread.cpp MThread.h
        MultipleTCPSocketsListener.cpp MultipleTCPSocketsListener.h
        RecvThread.h
        Socket.cpp Socket.h
        TCPClient.cpp TCPClient.h
        TCPRecvThread.cpp TCPRecvThread.h
        TCPServer.cpp TCPServer.h
        TCPSocket.cpp TCPSocket.h
        UDPSocket.cpp UDPSocket.h
        Broker.h Broker.cpp
        AuthService.cpp AuthService.h UDPRecvThread.cpp UDPRecvThread.h)
add_library(P2PGamePlatform ${SOURCE_FILES})