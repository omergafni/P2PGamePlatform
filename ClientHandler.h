/*
 * ClientHandler.h
 *
 *  Created on: Sep 7, 2017
 *      Author: user
 */

#ifndef CLIENTHANDLER_H_
#define CLIENTHANDLER_H_

namespace networkingLab{

	class ClientHandler {

	public:
		ClientHandler(){};
		virtual void handleClients() = 0;
		virtual ~ClientHandler(){};
	};

}




#endif /* CLIENTHANDLER_H_ */
