/*
 * RecvThread.h
 *
 *  Created on: May 10, 2017
 *      Author: root
 */

#ifndef SRC_RECVTHREAD_H_
#define SRC_RECVTHREAD_H_

#include "MThread.h"

namespace networkingLab {

class RecvThread : public MThread {
public:
	RecvThread() {};
	virtual ~RecvThread() {};

	virtual void run() = 0;
	virtual void receiver(void* args) = 0;
	virtual void stop() = 0;

};

}

#endif
