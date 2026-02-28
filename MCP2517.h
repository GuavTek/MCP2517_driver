/*
 * MCP2517.h
 *
 * Created: 01/07/2021 17:36:38
 *  Author: GuavTek
 */


#ifndef MCP2517_H_
#define MCP2517_H_

#include <stdint.h>
#include "communication_base.h"

enum class MCP2517_INSTR_E {
	Reset			= 0b0000,
	Read			= 0b0011,
	Write			= 0b0010,
	Read_CRC		= 0b1011,
	Write_CRC		= 0b1010,
	Write_Safe		= 0b1100
};

enum class MCP2517_ICODE_E {
	TXQ = 0x00,
	FIFO1 = 0x01,
	FIFO2 = 0x02,
	FIFO3 = 0x03,
	FIFO4 = 0x04,
	FIFO5 = 0x05,
	FIFO6 = 0x06,
	FIFO7 = 0x07,
	FIFO8 = 0x08,
	FIFO9 = 0x09,
	FIFO10 = 0x0a,
	FIFO11 = 0x0b,
	FIFO12 = 0x0c,
	FIFO13 = 0x0d,
	FIFO14 = 0x0e,
	FIFO15 = 0x0f,
	FIFO16 = 0x10,
	FIFO17 = 0x11,
	FIFO18 = 0x12,
	FIFO19 = 0x13,
	FIFO20 = 0x14,
	FIFO21 = 0x15,
	FIFO22 = 0x16,
	FIFO23 = 0x17,
	FIFO24 = 0x18,
	FIFO25 = 0x19,
	FIFO26 = 0x1a,
	FIFO27 = 0x1b,
	FIFO28 = 0x1c,
	FIFO29 = 0x1d,
	FIFO30 = 0x1e,
	FIFO31 = 0x1f,
	NoInt = 0x80,
	ErrorInt = 0x81,
	WakeUp = 0x82,
	RxOverflow = 0x83,
	AddressError = 0x84,
	MABFlow = 0x85,
	TBCOverflow = 0x86,
	OpModeChanged = 0x87,
	InvalidMessage = 0x88,
	TxEvent = 0x89,
	TxAttempt = 0x8a
};

enum class ADDR_E : uint16_t {
	C1CON			= 0x000,
	C1NBTCFG		= 0x004,
	C1DBTCFG		= 0x008,
	C1TDC			= 0x00c,
	C1TBC			= 0x010,
	C1TSCON			= 0x014,
	C1VEC			= 0x018,
	C1INT			= 0x01c,
	C1RXIF			= 0x020,
	C1TXIF			= 0x024,
	C1RXOVIF		= 0x028,
	C1TXATIF		= 0x02c,
	C1TXREQ			= 0x030,
	C1TREC			= 0x034,
	C1BDIAG0		= 0x038,
	C1BDIAG1		= 0x03c,
	C1TEFCON		= 0x040,
	C1TEFSTA		= 0x044,
	C1TEFUA			= 0x048,
	C1TXQCON		= 0x050,
	C1TXQSTA		= 0x054,
	C1TXQUA			= 0x058,
	C1FIFOCON1		= 0x05c,
	C1FIFOSTA1		= 0x060,
	C1FIFOUA1		= 0x064,
	C1FIFOCON2		= 0x068,
	C1FIFOSTA2		= 0x06c,
	C1FIFOUA2		= 0x070,
	C1FLTCON0		= 0x1d0,
	C1FLTCON1		= 0x1d4,
	C1FLTCON2		= 0x1d8,
	C1FLTCON3		= 0x1dc,
	C1FLTCON4		= 0x1e0,
	C1FLTCON5		= 0x1e4,
	C1FLTCON6		= 0x1e8,
	C1FLTCON7		= 0x1ec,
	C1FLTOBJ0		= 0x1f0,
	C1MASK0			= 0x1f4,
	C1FLTOBJ1		= 0x1f8,
	C1MASK1			= 0x1fc,
	RAM_START		= 0x400,
	RAM_END			= 0xbff,
	OSC				= 0xe00,
	IOCON			= 0xe04,
	CRC				= 0xe08,
	ECCCON			= 0xe0c,
	ECCSTAT			= 0xe10
};

enum class CAN_MODE_E {
	Normal_FD			= 0b000,
	Sleep				= 0b001,
	Internal_Loopback	= 0b010,
	Listen_Only			= 0b011,
	Configuration		= 0b100,
	External_Loopback	= 0b101,
	Normal_2			= 0b110,
	Restricted			= 0b111
};

struct CAN_FIFO_Status_t {
	union {
		struct {
			bool notFull : 1;
			bool halfEmpty : 1;
			bool empty : 1;
			bool unused : 1;
			bool attemptsSpent : 1;
			bool error : 1;
			bool lostArbitration : 1;
			bool aborted : 1;
		} tx;
		struct {
			bool notEmpty : 1;
			bool halfFull : 1;
			bool full : 1;
			bool overflow : 1;
			bool unused : 1;
			bool error : 1;
			bool lostArbitration : 1;
			bool aborted : 1;
		} rx;
		uint8_t word;
	};
};

struct CAN_Config_t {
	enum {	clkOutDiv1 = 0b00,
			clkOutDiv2 = 0b01,
			clkOutDiv4 = 0b10,
			clkOutDiv10 = 0b11} clkOutDiv = clkOutDiv1;
	bool sysClkDiv = false;
	bool clkDisable = false;
	bool pllEnable = false;		// Multiply system clk x10
	enum {	BW_Share0 = 0b0000,
			BW_Share2 = 0b0001,
			BW_Share4 = 0b0010,
			BW_Share8 = 0b0011,
			BW_Share16 = 0b0100,
			BW_Share32 = 0b0101,
			BW_Share64 = 0b0110,
			BW_Share128 = 0b0111,
			BW_Share256 = 0b1000,
			BW_Share512 = 0b1001,
			BW_Share1024 = 0b1010,
			BW_Share2048 = 0b1011,
			BW_Share4096 = 0b1100} txBandwidthShare = BW_Share0;
	enum CAN_MODE_E opMode = CAN_MODE_E::Normal_FD;
	bool txQueueEnable = false;
	bool txEventStore = false;
	bool listenOnlyOnError = false;
	bool restrictRetransmit = false;
	bool disableBitrateSwitch = false;
	enum {	Wake_Filter_40_75ns		= 0b00,
			Wake_Filter_70_120ns	= 0b01,
			Wake_Filter_125_215ns	= 0b10,
			Wake_Filter_225_390ns	= 0b11} wakeFilter = Wake_Filter_40_75ns;
	bool enableWakeFilter = false;
	bool disableProtocolException = false;
	bool enableIsoCrc = true;
	uint8_t deviceNetFilterBits = 0;
	uint8_t nominalBaudPrescaler;
	uint8_t nominalTSEG1;
	uint8_t nominalTSEG2 : 7;
	uint8_t nominalSyncJump : 7;
	uint8_t dataBaudPrescaler;
	uint8_t dataTSEG1 : 5;
	uint8_t dataTSEG2 : 4;
	uint8_t dataSyncJump : 4;
	bool enableEdgeFilter = true;
	bool enableSID11 = false;
	enum {	TdcDisabled		= 0b00,
			TdcManual		= 0b01,
			TdcAuto			= 0b10} txDelayCompensation = TdcAuto;
	int8_t txDelayCompOffset = 0;
	bool enableIntInvalidMessage = false;
	bool enableIntWakeup = false;
	bool enableIntBusError = false;
	bool enableIntSysError = false;
	bool enableIntRxOverflow = false;
	bool enableIntTxAttempt = false;
	bool enableIntCrcError = false;
	bool enableIntEccError = false;
	bool enableIntTxEvent = false;
	bool enableIntModeChange = false;
	bool enableIntTimebaseCount = false;
	bool enableIntRxFifo = false;
	bool enableIntTxFifo = false;
};

struct CAN_Rx_msg_t {
	uint32_t id;
	uint8_t filterHit;
	bool errorStatus = false;
	bool canFDFrame = true;
	bool bitrateSwitch = false;
	bool requestRemote = false;
	bool extendedID = false;
	uint8_t dataLengthCode;
	uint32_t timeStamp;
	char* payload;
};

struct CAN_Tx_msg_t {
	uint32_t id;
	uint8_t sequence;
	bool errorIndicator = false;
	bool canFDFrame = true;
	bool bitrateSwitch = false;
	bool requestRemote = false;
	bool extendedID = false;
	uint8_t dataLengthCode;
	char* payload;
};

struct CAN_Filter_t {
	bool enabled : 1;
	uint8_t fifoDestination : 5;
	bool extendedID : 1;
	uint32_t ID : 32;
	bool matchBothIDTypes : 1;
	uint32_t maskID: 32;
};

struct CAN_FIFO_t {
	bool enabled : 1;
	uint8_t payloadSize;
	uint8_t fifoDepth : 8; // Is only 5 bits, but use 8 to make struct 32 bit
	enum {None = 0, three = 1, unlimited = 2} retransmitAttempt : 2;
	uint8_t messagePriority : 5;
	bool txEnable : 1;
	bool autoRemote : 1;
	bool receiveTimestamp : 1;
	bool exhaustedTxInterrupt : 1;
	bool overflowInterrupt : 1;
	bool fullEmptyInterrupt : 1;
	bool halfFullEmptyInterrupt : 1;
	bool notFullEmptyInterrupt : 1;
};

extern const CAN_Filter_t CAN_FLT0;
extern const CAN_Filter_t CAN_FLT1;
extern const CAN_Filter_t CAN_FLT2;
extern const CAN_Filter_t CAN_FLT3;
extern const CAN_Filter_t CAN_FLT4;
extern const CAN_Filter_t CAN_FLT5;
extern const CAN_Filter_t CAN_FLT6;
extern const CAN_Filter_t CAN_FLT7;
extern const CAN_Filter_t CAN_FLT8;
extern const CAN_Filter_t CAN_FLT9;
extern const CAN_Filter_t CAN_FLT10;
extern const CAN_Filter_t CAN_FLT11;
extern const CAN_Filter_t CAN_FLT12;
extern const CAN_Filter_t CAN_FLT13;
extern const CAN_Filter_t CAN_FLT14;
extern const CAN_Filter_t CAN_FLT15;
extern const CAN_Filter_t CAN_FLT16;
extern const CAN_Filter_t CAN_FLT17;
extern const CAN_Filter_t CAN_FLT18;
extern const CAN_Filter_t CAN_FLT19;
extern const CAN_Filter_t CAN_FLT20;
extern const CAN_Filter_t CAN_FLT21;
extern const CAN_Filter_t CAN_FLT22;
extern const CAN_Filter_t CAN_FLT23;
extern const CAN_Filter_t CAN_FLT24;
extern const CAN_Filter_t CAN_FLT25;
extern const CAN_Filter_t CAN_FLT26;
extern const CAN_Filter_t CAN_FLT27;
extern const CAN_Filter_t CAN_FLT28;
extern const CAN_Filter_t CAN_FLT29;
extern const CAN_Filter_t CAN_FLT30;
extern const CAN_Filter_t CAN_FLT31;

const CAN_Filter_t* const Filter_Settings[32] = {
	&CAN_FLT0, &CAN_FLT1, &CAN_FLT2, &CAN_FLT3, &CAN_FLT4,
	&CAN_FLT5, &CAN_FLT6, &CAN_FLT7, &CAN_FLT8, &CAN_FLT9,
	&CAN_FLT10, &CAN_FLT11, &CAN_FLT12, &CAN_FLT13, &CAN_FLT14,
	&CAN_FLT15, &CAN_FLT16, &CAN_FLT17, &CAN_FLT18, &CAN_FLT19,
	&CAN_FLT20, &CAN_FLT21, &CAN_FLT22, &CAN_FLT23, &CAN_FLT24,
	&CAN_FLT25, &CAN_FLT26, &CAN_FLT27, &CAN_FLT28, &CAN_FLT29,
	&CAN_FLT30, &CAN_FLT31
};

extern const CAN_FIFO_t CAN_TXQ;
extern const CAN_FIFO_t CAN_FIFO1;
extern const CAN_FIFO_t CAN_FIFO2;
extern const CAN_FIFO_t CAN_FIFO3;
extern const CAN_FIFO_t CAN_FIFO4;
extern const CAN_FIFO_t CAN_FIFO5;
extern const CAN_FIFO_t CAN_FIFO6;
extern const CAN_FIFO_t CAN_FIFO7;
extern const CAN_FIFO_t CAN_FIFO8;
extern const CAN_FIFO_t CAN_FIFO9;
extern const CAN_FIFO_t CAN_FIFO10;
extern const CAN_FIFO_t CAN_FIFO11;
extern const CAN_FIFO_t CAN_FIFO12;
extern const CAN_FIFO_t CAN_FIFO13;
extern const CAN_FIFO_t CAN_FIFO14;
extern const CAN_FIFO_t CAN_FIFO15;
extern const CAN_FIFO_t CAN_FIFO16;
extern const CAN_FIFO_t CAN_FIFO17;
extern const CAN_FIFO_t CAN_FIFO18;
extern const CAN_FIFO_t CAN_FIFO19;
extern const CAN_FIFO_t CAN_FIFO20;
extern const CAN_FIFO_t CAN_FIFO21;
extern const CAN_FIFO_t CAN_FIFO22;
extern const CAN_FIFO_t CAN_FIFO23;
extern const CAN_FIFO_t CAN_FIFO24;
extern const CAN_FIFO_t CAN_FIFO25;
extern const CAN_FIFO_t CAN_FIFO26;
extern const CAN_FIFO_t CAN_FIFO27;
extern const CAN_FIFO_t CAN_FIFO28;
extern const CAN_FIFO_t CAN_FIFO29;
extern const CAN_FIFO_t CAN_FIFO30;
extern const CAN_FIFO_t CAN_FIFO31;

const CAN_FIFO_t* const FIFO_Settings[32] = {
	&CAN_TXQ, &CAN_FIFO1, &CAN_FIFO2, &CAN_FIFO3, &CAN_FIFO4,
	&CAN_FIFO5, &CAN_FIFO6, &CAN_FIFO7, &CAN_FIFO8, &CAN_FIFO9,
	&CAN_FIFO10, &CAN_FIFO11, &CAN_FIFO12, &CAN_FIFO13, &CAN_FIFO14,
	&CAN_FIFO15, &CAN_FIFO16, &CAN_FIFO17, &CAN_FIFO18, &CAN_FIFO19,
	&CAN_FIFO20, &CAN_FIFO21, &CAN_FIFO22, &CAN_FIFO23, &CAN_FIFO24,
	&CAN_FIFO25, &CAN_FIFO26, &CAN_FIFO27, &CAN_FIFO28, &CAN_FIFO29,
	&CAN_FIFO30, &CAN_FIFO31
};

class MCP2517_C : public com_driver_c {
	public:
		void Init(const CAN_Config_t canConfig);	// Apply the configuration to the controller
		void Reconfigure_Filter(CAN_Filter_t* filterSetting, uint8_t filterNum);		// Change the configuration of a filter
		inline void Set_Rx_Header_Callback(void (*cb)(CAN_Rx_msg_t*)){ Rx_Header_Callback = cb; }			// Set function to send the received CAN headers to
		inline void Set_Rx_Data_Callback(void (*cb)(char*, uint8_t)){ Rx_Data_Callback = cb; }			// Set function to send the received payloads to
		inline void Set_FIFO_Status_Callback(void (*cb)(uint8_t,CAN_FIFO_Status_t)){ FIFO_Status_Callback = cb; }			// Set function to send the FIFO status interrupt number to
		uint8_t Check_FIFO_Status(uint8_t fifoNum);	// Fetch the fifo status
		uint8_t Check_Rx();	// Try reading from MCP2517, return 0 if busy. Suggest triggering this via an RTC or checking the intpin
		uint8_t Write_Message(CAN_Tx_msg_t* msg, uint8_t fifoNum);	// Write a message object to controller RAM, use Send_Message() to transmit this message on the CAN bus
		uint8_t Append_Payload(char* data, uint8_t length);		// Append payload to previous message	TODO? verify payload size not overflowing
		uint8_t Send_Message();		// Send the message which was written to controller RAM
		uint32_t GetID(uint16_t SID, uint32_t EID);		// Convert the ID to the format used in controller
		inline uint8_t Get_DLC(uint8_t dataLength);		// Convert payload length to the length code used in headers
		inline uint8_t Get_Data_Length(uint8_t DLC);	// Convert the length code from a header to the payload length
		inline uint8_t Ready();		// Check if CAN controller is idle
		virtual void com_cb();	// The callback called when the com object is done transmitting data
		using com_driver_c::com_driver_c;
	protected:
		void Reset();	// Send a RESET command to the MCP2517
		inline void Filter_Init(const CAN_Filter_t* setting, uint8_t filterNum);	// Write a filter setting to the MCP2517
		inline void FIFO_Init(const CAN_FIFO_t* setting, uint8_t fifoNum);		// Write a fifo setting to the MCP2517
		void Write_Word_Blocking(enum ADDR_E addr, uint32_t data);		// A blocking write to the MCP2517
		uint32_t Receive_Word_Blocking(enum ADDR_E addr);				// A blocking read to the MCP2517
		uint8_t Send_Buffer(enum ADDR_E addr, char* data, uint8_t length);	// Send the contents of data to the MCP2517
		void Send_Buffer(enum ADDR_E addr, uint8_t length);	// Send data from the internal buffer to the MCP2517
		uint8_t Receive_Buffer(enum ADDR_E addr, uint8_t length);	// Fetch data to the internal buffer from the MCP2517
		void (*Rx_Header_Callback)(CAN_Rx_msg_t*);	// The callback function for header objects
		void (*Rx_Data_Callback)(char*, uint8_t);	// The callback function for payloads
		void (*FIFO_Status_Callback)(uint8_t,CAN_FIFO_Status_t);	// The callback function for FIFO status, gives fifo number as argument
		void Check_Int_Reg();	// Read the interrupt register of the MCP2517
		inline uint16_t Get_FIFOCON_Addr(uint8_t fifoNum);	// Get the address of a fifo's control register
		inline uint16_t Get_FIFOSTA_Addr(uint8_t fifoNum);	// Get the address of a fifo's status register
		inline uint16_t Get_FIFOUA_Addr(uint8_t fifoNum);	// Get the address of a fifo's user address register (gives address the fifo points at)
		void FIFO_Increment(uint8_t fifoNum, uint8_t txRequest);	// Increments the FIFO after reading/writing to it, optionally request a transmission
		void FIFO_User_Address(uint8_t fifoNum);	// Fetch the current fifo address from the MCP2517
		void Check_Rx_Flags_Reg();	// Fetch the rx interrupt flags
		uint32_t fifoTimestamp;		// Mask of which fifos use timestamps
		uint16_t msgAddr;		// Current message address
		uint16_t txHeadTemp;	// Save T1 of the tx header in case the DLC must be updated
		uint8_t sendFifo : 1;	// Will the fifo be incremented when data has been transferred?
		uint8_t msgAppended : 1;	// Has the payload been appended?
		uint8_t currentFifo : 5;	// The current fifo being accessed
		uint8_t payloadLength;	// The length of the payload
		char msgBuff[74];		// The internal buffer
		enum {Msg_Idle = 0,
			Msg_Rx_Flags, Msg_FIFO_Int, Msg_Status,
			Msg_Rx_Addr, Msg_Rx_Header, Msg_Rx_Data, Msg_Rx_FIFO,
			Msg_Tx_Addr, Msg_Tx_Data, Msg_Tx_Idle, Msg_Tx_FIFO} msgState;	// The controller state
};

inline uint8_t MCP2517_C::Ready(){
	return (msgState == Msg_Idle);
}

inline void MCP2517_C::Filter_Init(const CAN_Filter_t* setting, uint8_t filterNum){
	// Set mask
	uint32_t temp = 0;
	temp |= (setting->matchBothIDTypes ? 0 : 1) << 30;
	temp |= setting->maskID << 0;				// set Mask (SID11, EID, SID10-0)
	Write_Word_Blocking(ADDR_E(uint16_t(ADDR_E::C1MASK0) + 8 * filterNum), temp);

	// Set ID
	temp = 0;
	temp |= (setting->extendedID ? 1 : 0) << 30;
	temp |= setting->ID << 0;					// set ID (SID11, EID, SID10-0)
	Write_Word_Blocking(ADDR_E(uint16_t(ADDR_E::C1FLTOBJ0) + 8 * filterNum), temp);

	// Enable filter and set destination
	temp = Receive_Word_Blocking(ADDR_E(uint16_t(ADDR_E::C1FLTCON0) + 4*(filterNum >> 2)));
	if (setting->enabled){
		temp |= 1 << (7 + 8 * (filterNum % 4));
	} else {
		temp &= ~(1 << (7 + 8 * (filterNum % 4)));
	}
	temp |= (setting->fifoDestination) << (8 * (filterNum % 4));
	Write_Word_Blocking(ADDR_E(uint16_t(ADDR_E::C1FLTCON0) + 4*(filterNum >> 2)), temp);
}

inline void MCP2517_C::FIFO_Init(const CAN_FIFO_t* setting, uint8_t fifoNum){
	uint32_t temp = 0;

	// Find required DLC size
	uint8_t tempDLC;
	if (setting->payloadSize > 48){
		tempDLC = 0b111;
	} else if (setting->payloadSize > 32){
		tempDLC = 0b110;
	} else if (setting->payloadSize > 24){
		tempDLC = 0b101;
	} else if (setting->payloadSize > 20){
		tempDLC = 0b100;
	} else if (setting->payloadSize > 16){
		tempDLC = 0b011;
	} else if (setting->payloadSize > 12){
		tempDLC = 0b010;
	} else if (setting->payloadSize > 8){
		tempDLC = 0b001;
	} else {
		tempDLC = 0b000;
	}

	fifoTimestamp &= ~(1 << fifoNum);
	fifoTimestamp |= (setting->receiveTimestamp ? 1 : 0) << fifoNum;

	temp |= tempDLC << 29;
	temp |= setting->fifoDepth << 24;
	temp |= setting->retransmitAttempt << 21;
	temp |= setting->messagePriority << 16;
	temp |= (setting->txEnable ? 1 : 0) << 7;
	temp |= (setting->autoRemote ? 1 : 0) << 6;
	temp |= (setting->receiveTimestamp ? 1 : 0) << 5;
	temp |= (setting->exhaustedTxInterrupt ? 1 : 0) << 4;
	temp |= (setting->overflowInterrupt ? 1 : 0) << 3;
	temp |= (setting->fullEmptyInterrupt ? 1 : 0) << 2;
	temp |= (setting->halfFullEmptyInterrupt ? 1 : 0) << 1;
	temp |= (setting->notFullEmptyInterrupt ? 1 : 0) << 0;
	Write_Word_Blocking(ADDR_E(uint16_t(ADDR_E::C1TXQCON) + 12 * fifoNum), temp);
}

inline uint8_t MCP2517_C::Get_DLC(uint8_t dataLength){
	if (dataLength > 48){
		return 15;
	} else if (dataLength > 32){
		return 14;
	} else if (dataLength > 24){
		return 13;
	} else if (dataLength > 20){
		return 12;
	} else if (dataLength > 16){
		return 11;
	} else if (dataLength > 12){
		return 10;
	} else if (dataLength > 8){
		return 9;
	} else {
		return dataLength;
	}
}

inline uint8_t MCP2517_C::Get_Data_Length(uint8_t DLC){
	switch(DLC){
		case 0:
			return 0;
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			return 3;
		case 4:
			return 4;
		case 5:
			return 5;
		case 6:
			return 6;
		case 7:
			return 7;
		case 8:
			return 8;
		case 9:
			return 12;
		case 10:
			return 16;
		case 11:
			return 20;
		case 12:
			return 24;
		case 13:
			return 32;
		case 14:
			return 48;
		case 15:
			return 64;
		default:
			return 0;
	}
}

inline uint16_t MCP2517_C::Get_FIFOCON_Addr(uint8_t fifoNum){
	return ((uint16_t) ADDR_E::C1TXQCON + (0xc * fifoNum));
}

inline uint16_t MCP2517_C::Get_FIFOSTA_Addr(uint8_t fifoNum){
	return ((uint16_t) ADDR_E::C1TXQSTA + (0xc * fifoNum));
}

inline uint16_t MCP2517_C::Get_FIFOUA_Addr(uint8_t fifoNum){
	return ((uint16_t) ADDR_E::C1TXQUA + (0xc * fifoNum));
}

#endif /* MCP2517_H_ */