/*
 * MessageHandler.h
 *
 *  Created on: Jun 19, 2017
 *      Author: root
 */

#ifndef MESSAGEHANDLER_H_
#define MESSAGEHANDLER_H_
#include <string>

using namespace std;

namespace networkingLab {

class MessageHandler {

public:
    MessageHandler(){};
	virtual ~MessageHandler(){};
	virtual void handleMessage(string msg) = 0;
};

}

#endif /* MESSAGEHANDLER_H_ */
