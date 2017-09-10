/*
 * File.h
 *
 *  Created on: May 19, 2017
 *      Author: root
 */

#ifndef SRC_FILEINTERFACE_H_
#define SRC_FILEINTERFACE_H_

class FileInterface {


public:

	FileInterface(){};
	virtual ~FileInterface(){};

	virtual int read(char* buff, int size) = 0;
	virtual int write(const char* msg, int length) = 0;
	virtual void close() = 0;


};




#endif /* SRC_FILEINTERFACE_H_ */
