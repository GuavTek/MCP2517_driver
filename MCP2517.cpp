/*
 * MCP2517.cpp
 *
 * Created: 10/10/2021 15:18:05
 *  Author: GuavTek
 */

#include "MCP2517.h"

CAN_FIFO_t Unused_Fifo = {
	.enabled = false,
	.payloadSize = 0,
	.fifoDepth = 0,
	.retransmitAttempt = CAN_FIFO_t::None,
	.messagePriority = 0,
	.txEnable = false,
	.autoRemote = false,
	.receiveTimestamp = false,
	.exhaustedTxInterrupt = false,
	.overflowInterrupt = false,
	.fullEmptyInterrupt = false,
	.halfFullEmptyInterrupt = false,
	.notFullEmptyInterrupt = false
};

CAN_Filter_t Unused_Filter = {
	.enabled = false,
	.fifoDestination = 1,
	.extendedID = false,
	.ID = 0,
	.matchBothIDTypes = false,
	.maskID = 0
};

extern const CAN_Filter_t CAN_FLT0 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT1 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT2 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT3 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT4 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT5 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT6 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT7 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT8 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT9 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT10 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT11 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT12 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT13 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT14 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT15 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT16 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT17 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT18 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT19 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT20 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT21 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT22 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT23 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT24 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT25 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT26 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT27 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT28 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT29 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT30 __attribute__ ((weak, alias("Unused_Filter")));
extern const CAN_Filter_t CAN_FLT31 __attribute__ ((weak, alias("Unused_Filter")));

extern const CAN_FIFO_t CAN_TXQ __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO1 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO2 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO3 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO4 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO5 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO6 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO7 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO8 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO9 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO10 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO11 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO12 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO13 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO14 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO15 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO16 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO17 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO18 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO19 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO20 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO21 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO22 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO23 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO24 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO25 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO26 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO27 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO28 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO29 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO30 __attribute__ ((weak, alias("Unused_Fifo")));
extern const CAN_FIFO_t CAN_FIFO31 __attribute__ ((weak, alias("Unused_Fifo")));

// Initializes the MCP2517 chip
void MCP2517_C::Init(const CAN_Config_t canConfig){
	msgState = MCP2517_C::Msg_Idle;

	Reset();

	uint32_t temp;

	temp = 0;
	temp |= 1 << 27;							// Abort all pending transmissions
	temp |= ((uint8_t) CAN_MODE_E::Configuration) << 24;	// Request config mode
	Write_Word_Blocking(ADDR_E::C1CON, temp);

	// Wait for config mode
	do {
		temp = Receive_Word_Blocking(ADDR_E::C1CON);
	} while ((temp & (0b111 << 21)) != (0b100 << 21));

	fifoTimestamp = 0;
	for (uint8_t i = 0; i < 32; i++){
		// Configure filters
		if (Filter_Settings[i]->enabled){
			Filter_Init(Filter_Settings[i], i);
		}
		// Configure FIFOs
		if (FIFO_Settings[i]->enabled){
			FIFO_Init(FIFO_Settings[i], i);
		}
	}

	// Configure interrupts
	temp = 0;
	temp |= (canConfig.enableIntInvalidMessage ? 1 : 0) << 31;
	temp |= (canConfig.enableIntWakeup ? 1 : 0) << 30;
	temp |= (canConfig.enableIntBusError ? 1 : 0) << 29;
	temp |= (canConfig.enableIntSysError ? 1 : 0) << 28;
	temp |= (canConfig.enableIntRxOverflow ? 1 : 0) << 27;
	temp |= (canConfig.enableIntTxAttempt ? 1 : 0) << 26;
	temp |= (canConfig.enableIntCrcError ? 1 : 0) << 25;
	temp |= (canConfig.enableIntEccError ? 1 : 0) << 24;
	temp |= (canConfig.enableIntTxEvent ? 1 : 0) << 20;
	temp |= (canConfig.enableIntModeChange ? 1 : 0) << 19;
	temp |= (canConfig.enableIntTimebaseCount ? 1 : 0) << 18;
	temp |= (canConfig.enableIntRxFifo ? 1 : 0) << 17;
	temp |= (canConfig.enableIntTxFifo ? 1 : 0) << 16;
	Write_Word_Blocking(ADDR_E::C1INT, temp);

	temp = 0;
	temp |= (canConfig.enableEdgeFilter ? 1 : 0) << 25;
	temp |= (canConfig.enableSID11 ? 1 : 0) << 24;
	temp |= ((uint8_t) canConfig.txDelayCompensation) << 16;
	temp |= (canConfig.txDelayCompOffset) << 8;
	Write_Word_Blocking(ADDR_E::C1TDC, temp);

	temp = 0;
	temp |= canConfig.nominalBaudPrescaler << 24;
	temp |= canConfig.nominalTSEG1 << 16;
	temp |= canConfig.nominalTSEG2 << 8;
	temp |= canConfig.nominalSyncJump;
	Write_Word_Blocking(ADDR_E::C1NBTCFG, temp);

	temp = 0;
	temp |= canConfig.dataBaudPrescaler << 24;
	temp |= canConfig.dataTSEG1 << 16;
	temp |= canConfig.dataTSEG2 << 8;
	temp |= canConfig.dataSyncJump;
	Write_Word_Blocking(ADDR_E::C1DBTCFG, temp);

	temp = 0;
	temp |= ((uint8_t) canConfig.clkOutDiv) << 5;
	temp |= (canConfig.sysClkDiv ? 1 : 0) << 4;
	temp |= (canConfig.clkDisable ? 1 : 0) << 2;
	temp |= (canConfig.pllEnable ? 1 : 0);
	Write_Word_Blocking(ADDR_E::OSC, temp);

	temp = 0;
	temp |= ((uint8_t) canConfig.txBandwidthShare) << 28;
	temp |= ((uint8_t) canConfig.opMode) << 24;
	temp |= (canConfig.txQueueEnable ? 1 : 0) << 20;
	temp |= (canConfig.txEventStore ? 1 : 0) << 19;
	temp |= (canConfig.listenOnlyOnError ? 1 : 0) << 18;
	temp |= (canConfig.restrictRetransmit ? 1 : 0) << 16;
	temp |= (canConfig.disableBitrateSwitch ? 1 : 0) << 12;
	temp |= ((uint8_t) canConfig.wakeFilter) << 9;
	temp |= (canConfig.enableWakeFilter ? 1 : 0) << 8;
	temp |= (canConfig.disableProtocolException ? 1 : 0) << 6;
	temp |= (canConfig.enableIsoCrc ? 1 : 0) << 5;
	temp |= canConfig.deviceNetFilterBits;
	Write_Word_Blocking(ADDR_E::C1CON, temp);

	// Wait for chosen mode
	do {
		temp = Receive_Word_Blocking(ADDR_E::C1CON);
	} while ((temp & (0b111 << 21)) != (((uint8_t) canConfig.opMode) << 21));

}

void MCP2517_C::Reconfigure_Filter(CAN_Filter_t* filterSetting, uint8_t filterNum){
	// Disable filter so it can be edited
	filterSetting->enabled = 0;
	Filter_Init(filterSetting, filterNum);

	// Configure and enable filter
	filterSetting->enabled = 1;
	Filter_Init(filterSetting, filterNum);
}

// Reset the CAN controller
void MCP2517_C::Reset(){
	for (uint8_t i = 0; i < 4; i++){
		msgBuff[i] = 0;
	}
	while(com->Get_Status() != Idle);
	Set_SS(1);
	com->Transfer(msgBuff, 4, Tx);
	while(com->Get_Status() != Idle);
	Set_SS(0);
}

// Sends a number of bytes to the specified address of the MCP2517
uint8_t MCP2517_C::Send_Buffer(enum ADDR_E addr, char* data, uint8_t length){
	if (com->Get_Status() == Idle){
		// Write buffer
		msgBuff[0] = ((char) MCP2517_INSTR_E::Write << 4) | ((uint16_t) addr >> 8);
		msgBuff[1] = (uint8_t) addr & 0xff;

		for (uint8_t i = 0; i < length; i++){
			msgBuff[i+2] = data[i];
		}

		Set_SS(1);
		com->Transfer(msgBuff, length+2, Tx);

		// Return success
		return 1;
	} else {
		// Return not success
		return 0;
	}
};

// Send the payload
// Payload was loaded to buffer
void MCP2517_C::Send_Buffer(enum ADDR_E addr, uint8_t length){
	msgBuff[0] = ((char) MCP2517_INSTR_E::Write << 4) | ((uint16_t) addr >> 8);
	msgBuff[1] = ((uint16_t) addr) & 0xff;

	Set_SS(1);
	com->Transfer(msgBuff, length+2, Tx);
}


// Reads a number of bytes from the specified address of the MCP2517
uint8_t MCP2517_C::Receive_Buffer(enum ADDR_E addr, uint8_t length){
	if (com->Get_Status() == Idle){
		// Write buffer
		msgBuff[0] = ((char) MCP2517_INSTR_E::Read << 4) | ((uint16_t) addr >> 8);
		msgBuff[1] = (uint8_t) addr & 0xff;

		Set_SS(1);
		com->Transfer(msgBuff, length+2, RxTx);

		return 1;
	} else {
		return 0;
	}
};

// Write a word to CAN controller and block execution until it is done
void MCP2517_C::Write_Word_Blocking(enum ADDR_E addr, uint32_t data){
	char temp[6];
	temp[0] = ((char) MCP2517_INSTR_E::Write << 4) | ((uint16_t) addr >> 8);
	temp[1] = (uint8_t) addr & 0xff;
	temp[2] = data & 0xff;
	temp[3] = (data >> 8) & 0xff;
	temp[4] = (data >> 16) & 0xff;
	temp[5] = (data >> 24) & 0xff;
	while(com->Get_Status() != Idle);
	Set_SS(1);
	com->Transfer(temp, 6, Tx);
	while(com->Get_Status() != Idle);
	Set_SS(0);
}

uint32_t MCP2517_C::Receive_Word_Blocking(enum ADDR_E addr){
	char temp[6];
	temp[0] = ((char) MCP2517_INSTR_E::Read << 4) | ((uint16_t) addr >> 8);
	temp[1] = (uint8_t) addr & 0xff;
	for (uint8_t i = 2; i < 6; i++){
		temp[i] = 0;
	}
	while(com->Get_Status() != Idle);
	Set_SS(1);
	com->Transfer(temp, 6, RxTx);
	while(com->Get_Status() != Idle);
	Set_SS(0);
	uint32_t result = temp[2] | (temp[3] << 8) | (temp[4] << 16) | (temp[5] << 24);
	return result;
}

void MCP2517_C::FIFO_Increment(uint8_t fifoNum, uint8_t txRequest){
	uint16_t addr = Get_FIFOCON_Addr(fifoNum) + 1;

	char data = 1 | (txRequest << 1);

	Send_Buffer((ADDR_E) addr, &data, 1);
}

void MCP2517_C::FIFO_User_Address(uint8_t fifoNum){
	uint16_t addr = Get_FIFOUA_Addr(fifoNum);
	Receive_Buffer((ADDR_E) addr, 2);
}

// Formats the ID field
uint32_t MCP2517_C::GetID(uint16_t SID, uint32_t EID){
	uint32_t temp = 0;
	temp = SID & 0x07ff;
	temp |= EID << 11;
	temp |= (SID >> 11) << 29;
	return temp;
}

uint8_t MCP2517_C::Write_Message(CAN_Tx_msg_t* msg, uint8_t fifoNum){
	if (msgState == Msg_Idle){
		payloadLength = Get_Data_Length(msg->dataLengthCode);
		msgAddr = msg->id & 0xffff;

		msgBuff[4] = msg->id >> 16;
		msgBuff[5] = msg->id >> 24;

		uint8_t temp = 0;
		temp |= msg->dataLengthCode;
		temp |= (msg->extendedID ? 1 : 0) << 4;
		temp |= (msg->requestRemote ? 1 : 0) << 5;
		temp |= (msg->bitrateSwitch ? 1 : 0) << 6;
		temp |= (msg->canFDFrame ? 1 : 0) << 7;
		msgBuff[6] = temp;
		txHeadTemp = temp;

		temp = 0;
		temp |= (msg->errorIndicator ? 1 : 0);
		temp |= msg->sequence << 1;
		msgBuff[7] = temp;
		msgBuff[8] = 0;
		msgBuff[9] = 0;
		txHeadTemp |= temp << 8;

		for (uint8_t i = 0; i < payloadLength; i++){
			msgBuff[i+10] = msg->payload[i];
		}

		currentFifo = fifoNum;

		sendFifo = 0;
		msgAppended = 0;
		msgState = Msg_Tx_Addr;
		FIFO_User_Address(fifoNum);
		return 1;
	}
	return 0;
}

uint8_t MCP2517_C::Append_Payload(char* data, uint8_t length){
	if (msgState == Msg_Tx_Idle){
		uint16_t addr;
		addr = msgAddr + 8 + payloadLength;
		if (Send_Buffer((ADDR_E) addr, data, length)){
			payloadLength += length;
			msgAppended = 1;
			return 1;
		}
	}
	return 0;
}

uint8_t MCP2517_C::Send_Message(){
	if((msgState == Msg_Tx_Addr) || (msgState == Msg_Tx_Data)) {
		sendFifo = 1;
		return 1;
	} else if (msgState == Msg_Tx_Idle)	{
		if (msgAppended){
			// Update payload length
			sendFifo = 1;
			msgState = Msg_Tx_Data;
			msgAppended = 0;
			msgBuff[2] = Get_DLC(payloadLength) | (txHeadTemp & 0xf0);
			msgBuff[3] = txHeadTemp >> 8;
			msgBuff[4] = 0;
			msgBuff[5] = 0;
			Send_Buffer((ADDR_E) (msgAddr+4), 4);
		} else {
			sendFifo = 0;
			msgState = Msg_Tx_FIFO;
			FIFO_Increment(currentFifo, 1);
		}
		return 1;
	}
	return 0;
}

// Request status info of FIFO
uint8_t MCP2517_C::Check_FIFO_Status(uint8_t fifoNum){
	if (msgState != Msg_Idle){
		return 0;
	}
	uint16_t addr = Get_FIFOSTA_Addr(fifoNum);
	msgState = Msg_FIFO_Int;
	currentFifo = fifoNum;
	Receive_Buffer((ADDR_E) addr, 1);
	return 1;
}

void MCP2517_C::Check_Int_Reg(){
	msgState = Msg_Status;
	Receive_Buffer(ADDR_E::C1VEC, 4);
}

void MCP2517_C::Check_Rx_Flags_Reg(){
	msgState = Msg_Rx_Flags;
	Receive_Buffer(ADDR_E::C1RXIF, 4);
}

uint8_t MCP2517_C::Check_Rx(){
	if (msgState == MCP2517_C::Msg_Idle){
		// Start checking the Rx flags
		Check_Rx_Flags_Reg();
		return 1;
	}
	return 0;
}

void MCP2517_C::com_cb(){
	if (com->Get_Status() == Idle){
		Set_SS(0);
	} else {
		// Transfer still in progress
		return;
	}
	switch(msgState){
		case Msg_Rx_Flags: {
			// Rx flags were fetched, check if data is waiting
			uint32_t intFlags = msgBuff[2] | (msgBuff[3] << 8) | (msgBuff[4] << 16) | (msgBuff[5] << 24);
			if (intFlags == 0){
				// No message
				msgState = Msg_Idle;
			} else {
				// Message waiting in buffer
				for (uint8_t i = 1; i < 32; i++){
					if (intFlags & (1 << i)){
						msgState = Msg_Rx_Addr;
						FIFO_User_Address(i);
						currentFifo = i;
						break;
					}
				}
			}
			break;
		}
		case Msg_Rx_Addr: {
			// Rx RAM address fetched, start fetching header
			msgState = Msg_Rx_Header;

			uint16_t addr = (msgBuff[3] << 8) | msgBuff[2];
			addr += (uint16_t) ADDR_E::RAM_START;
			msgAddr = addr;
			Receive_Buffer((ADDR_E) addr, 12);
			break;
		}
		case Msg_Rx_Header: {
			CAN_Rx_msg_t tempMsg;

			tempMsg.id = msgBuff[2] | (msgBuff[3] << 8) | (msgBuff[4] << 16) | (msgBuff[5] << 24);
			tempMsg.dataLengthCode = msgBuff[6] & 0x0f;
			tempMsg.extendedID = (msgBuff[6] & 0x10) ? 1 : 0;
			tempMsg.requestRemote = (msgBuff[6] & 0x20) ? 1 : 0;
			tempMsg.bitrateSwitch = (msgBuff[6] & 0x40) ? 1 : 0;
			tempMsg.canFDFrame = (msgBuff[6] & 0x80) ? 1 : 0;
			tempMsg.errorStatus = (msgBuff[7] & 0x01) ? 1 : 0;
			tempMsg.filterHit = msgBuff[7] >> 3;

			payloadLength = Get_Data_Length(tempMsg.dataLengthCode);

			if (fifoTimestamp & (1 << currentFifo)){
				tempMsg.timeStamp = msgBuff[10] | (msgBuff[11] << 8) | (msgBuff[12] << 16) | (msgBuff[13] << 24);
				tempMsg.payload = &msgBuff[14];
				msgAddr += 12;
			} else {
				tempMsg.payload = &msgBuff[10];
				msgAddr += 8;
			}
			Rx_Header_Callback(&tempMsg);
			// Fetch data
			if (payloadLength > 32){
				Receive_Buffer((ADDR_E) msgAddr, 32);
			} else {
				Receive_Buffer((ADDR_E) msgAddr, payloadLength);
			}
			msgState = Msg_Rx_Data;
			break;
		}
		case Msg_Rx_Data: {
			if (payloadLength > 32){
				payloadLength -= 32;
				msgAddr += 32;
				Rx_Data_Callback(&msgBuff[2], 32);
				Receive_Buffer((ADDR_E) msgAddr, 32);
			} else {
				// Done fetching Rx data, increment fifo
				Rx_Data_Callback(&msgBuff[2], payloadLength);
				msgState = Msg_Rx_FIFO;
				FIFO_Increment(currentFifo, 0);
			}
			break;
		}
		case Msg_Rx_FIFO: {
			// Rx done
			msgState = Msg_Idle;
			break;
		}
		case Msg_Tx_Addr: {
			// Tx RAM address was fetched, send data
			msgState = Msg_Tx_Data;

			// Swap buffer address and message ID
			uint16_t addr = (msgBuff[3] << 8) | msgBuff[2];
			addr += (uint16_t) ADDR_E::RAM_START;
			msgBuff[2] = msgAddr;
			msgBuff[3] = msgAddr >> 8;
			msgAddr = addr;
			Send_Buffer((ADDR_E) addr, payloadLength+8);	// Payload + header
			break;
		}
		case Msg_Tx_Data: {
			// Tx data was sent to RAM, increment fifo and request data send
			if(sendFifo) {
				if (msgAppended){
					msgAppended = 0;
					msgBuff[2] = Get_DLC(payloadLength) | (txHeadTemp & 0xf0);
					msgBuff[3] = txHeadTemp >> 8;
					msgBuff[4] = 0;
					msgBuff[5] = 0;
					Send_Buffer((ADDR_E) (msgAddr+4), 4);
				} else {
					sendFifo = 0;
					msgState = Msg_Tx_FIFO;
					FIFO_Increment(currentFifo, 1);
				}
			} else {
				// Wait for payload append
				msgState = Msg_Tx_Idle;
			}
			break;
		}
		case Msg_Tx_FIFO: {
			// Tx done, check fifo status
			uint16_t addr = Get_FIFOSTA_Addr(currentFifo);
			msgState = Msg_FIFO_Int;
			Receive_Buffer((ADDR_E) addr, 1);
			break;
		}
		case Msg_FIFO_Int: {
			CAN_FIFO_Status_t flags;
			flags.word = msgBuff[2];
			if (FIFO_Status_Callback != nullptr){
				FIFO_Status_Callback(currentFifo, flags);
			}
			msgState = Msg_Idle;
			break;
		}
		default: {
			msgState = Msg_Idle;
			break;
		}
	}
}
