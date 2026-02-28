/*
 * communication_base.h
 *
 * Created: 25/02/2023 14:56:40
 *  Author: GuavTek
 */


#ifndef COMMUNICATION_BASE_H_
#define COMMUNICATION_BASE_H_

#include <stdint.h>
#include <stdlib.h>

enum com_state_e {
	Idle	= 0,
	Rx		= 0b01,
	Tx		= 0b10,
	RxTx	= 0b11
};

class com_driver_c;

// An abstract class providing a base API higher level drivers can use
class communication_base_c
{
	public:
		inline com_state_e Get_Status(){ return currentState; }		// Returns the internal state of the object
		virtual void Set_Slave_Callback(uint8_t slaveNum, com_driver_c* cb) {slaveCallbacks[slaveNum] = cb;};	// Set the object to call its com_cb function when transactions finish
		virtual uint8_t Select_Slave(uint8_t slaveNum, uint8_t enabled) {return 0;};
		virtual uint8_t Transfer(char* buff, uint8_t length, com_state_e state) {return 0;};	// Try to start a transfer, returns 0 if operation failed
		communication_base_c(uint8_t num_ss) {
			numSS = num_ss;
			slaveCallbacks = (com_driver_c**) malloc(sizeof(com_driver_c*) * num_ss); 	// Allocate memory space for function pointers
			currentState = Idle;
		};
		~communication_base_c() {free(slaveCallbacks);};
	protected:
		uint8_t numSS;
		com_driver_c** slaveCallbacks;
		com_state_e currentState;
};

// An abstract class providing a callback handle the communication base uses
class com_driver_c
{
	public:
		uint8_t Set_SS(uint8_t enabled) {return com->Select_Slave(comSlaveNum, enabled);};
		virtual void com_cb() {};
		com_driver_c(communication_base_c* const comInstance, uint8_t slaveNum) {
				com = comInstance;
				comSlaveNum = slaveNum;
				com->Set_Slave_Callback(slaveNum, this);
			};
		~com_driver_c() {};
	protected:
		communication_base_c* com;
		uint8_t comSlaveNum;
};

#endif /* COMMUNICATION_BASE_H_ */