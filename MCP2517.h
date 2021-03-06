/*
 * MCP2517.h
 *
 * Created: 01/07/2021 17:36:38
 *  Author: GuavTek
 */ 


#ifndef MCP2517_H_
#define MCP2517_H_

#include "SPI.h"

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

struct CAN_Config_t {
	enum {	CAN_Rx_Interrupt,
			CAN_Rx_RTC } rxMethod = CAN_Rx_Interrupt;
	uint8_t interruptPin = 0;
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
	uint32_t ID : 29;
	bool matchBothIDTypes : 1;
	uint32_t maskID: 29;
};

struct CAN_FIFO_t {
	bool enabled : 1;
	uint8_t payloadSize;
	uint8_t fifoDepth : 5;
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

extern CAN_Filter_t CAN_FLT0;
extern CAN_Filter_t CAN_FLT1;
extern CAN_Filter_t CAN_FLT2;
extern CAN_Filter_t CAN_FLT3;
extern CAN_Filter_t CAN_FLT4;
extern CAN_Filter_t CAN_FLT5;
extern CAN_Filter_t CAN_FLT6;
extern CAN_Filter_t CAN_FLT7;
extern CAN_Filter_t CAN_FLT8;
extern CAN_Filter_t CAN_FLT9;
extern CAN_Filter_t CAN_FLT10;
extern CAN_Filter_t CAN_FLT11;
extern CAN_Filter_t CAN_FLT12;
extern CAN_Filter_t CAN_FLT13;
extern CAN_Filter_t CAN_FLT14;
extern CAN_Filter_t CAN_FLT15;
extern CAN_Filter_t CAN_FLT16;
extern CAN_Filter_t CAN_FLT17;
extern CAN_Filter_t CAN_FLT18;
extern CAN_Filter_t CAN_FLT19;
extern CAN_Filter_t CAN_FLT20;
extern CAN_Filter_t CAN_FLT21;
extern CAN_Filter_t CAN_FLT22;
extern CAN_Filter_t CAN_FLT23;
extern CAN_Filter_t CAN_FLT24;
extern CAN_Filter_t CAN_FLT25;
extern CAN_Filter_t CAN_FLT26;
extern CAN_Filter_t CAN_FLT27;
extern CAN_Filter_t CAN_FLT28;
extern CAN_Filter_t CAN_FLT29;
extern CAN_Filter_t CAN_FLT30;
extern CAN_Filter_t CAN_FLT31;

extern CAN_Filter_t* Filter_Settings[32];

extern CAN_FIFO_t CAN_TXQ;
extern CAN_FIFO_t CAN_FIFO1;
extern CAN_FIFO_t CAN_FIFO2;
extern CAN_FIFO_t CAN_FIFO3;
extern CAN_FIFO_t CAN_FIFO4;
extern CAN_FIFO_t CAN_FIFO5;
extern CAN_FIFO_t CAN_FIFO6;
extern CAN_FIFO_t CAN_FIFO7;
extern CAN_FIFO_t CAN_FIFO8;
extern CAN_FIFO_t CAN_FIFO9;
extern CAN_FIFO_t CAN_FIFO10;
extern CAN_FIFO_t CAN_FIFO11;
extern CAN_FIFO_t CAN_FIFO12;
extern CAN_FIFO_t CAN_FIFO13;
extern CAN_FIFO_t CAN_FIFO14;
extern CAN_FIFO_t CAN_FIFO15;
extern CAN_FIFO_t CAN_FIFO16;
extern CAN_FIFO_t CAN_FIFO17;
extern CAN_FIFO_t CAN_FIFO18;
extern CAN_FIFO_t CAN_FIFO19;
extern CAN_FIFO_t CAN_FIFO20;
extern CAN_FIFO_t CAN_FIFO21;
extern CAN_FIFO_t CAN_FIFO22;
extern CAN_FIFO_t CAN_FIFO23;
extern CAN_FIFO_t CAN_FIFO24;
extern CAN_FIFO_t CAN_FIFO25;
extern CAN_FIFO_t CAN_FIFO26;
extern CAN_FIFO_t CAN_FIFO27;
extern CAN_FIFO_t CAN_FIFO28;
extern CAN_FIFO_t CAN_FIFO29;
extern CAN_FIFO_t CAN_FIFO30;
extern CAN_FIFO_t CAN_FIFO31;

extern CAN_FIFO_t* FIFO_Settings[32];

class MCP2517_C : SPI_C {
	public:
		void Init(const CAN_Config_t canConfig, const spi_config_t spiConfig);
		void Reconfigure_Filters(uint32_t mask);
		inline void Set_Rx_Callback(void (*cb)(CAN_Rx_msg_t*)){ Rx_Callback = cb; }
		uint8_t Transmit_Message(CAN_Tx_msg_t* msg, uint8_t fifoNum);
		uint32_t GetID(uint16_t SID, uint32_t EID);
		void State_Machine();
		inline void Handler();
		inline uint8_t Get_DLC(uint8_t dataLength);
		inline uint8_t Get_Data_Length(uint8_t DLC);
		using SPI_C::SPI_C;
	protected:
		void Reset();
		inline void Filter_Init(CAN_Filter_t* setting, uint8_t filterNum);
		inline void FIFO_Init(CAN_FIFO_t* setting, uint8_t fifoNum);
		void Write_Word_Blocking(enum ADDR_E addr, uint32_t data);
		uint32_t Receive_Word_Blocking(enum ADDR_E addr);
		uint8_t Send_Buffer(enum ADDR_E addr, char* data, uint8_t length);
		uint8_t Receive_Buffer(enum ADDR_E addr, uint8_t length);
		void (*Rx_Callback)(CAN_Rx_msg_t*);
		void Check_Rx_Int();
		void Check_Rx_RTC();
		void Check_Int_Reg();
		inline uint16_t Get_FIFOCON_Addr(uint8_t fifoNum);
		inline uint16_t Get_FIFOSTA_Addr(uint8_t fifoNum);
		inline uint16_t Get_FIFOUA_Addr(uint8_t fifoNum);
		void Send_Message_Object(uint16_t addr);
		void FIFO_Increment(uint8_t fifoNum, uint8_t txRequest);
		void FIFO_User_Address(uint8_t fifoNum);
		void Check_FIFO_Status(uint8_t fifoNum);
		void Check_Rx_Flags_Reg();
		bool useInterrupt;
		uint8_t interruptPin;
		uint32_t filterTimestamp;
		uint8_t currentFifo;
		CAN_Tx_msg_t currentMsg;
		enum {Msg_Idle = 0,
			Msg_Rx_Flags, Msg_FIFO_Int, Msg_Status, Msg_Rx_Addr, Msg_Rx_Data, Msg_Rx_FIFO,
			Msg_Tx_Addr, Msg_Tx_Data, Msg_Tx_FIFO} msgState;
};

inline void MCP2517_C::Filter_Init(CAN_Filter_t* setting, uint8_t filterNum){
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
	
	filterTimestamp &= ~(1 << filterNum);
	filterTimestamp |= (FIFO_Settings[filterNum]->receiveTimestamp ? 1 : 0) << filterNum;
}

inline void MCP2517_C::FIFO_Init(CAN_FIFO_t* setting, uint8_t fifoNum){
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
	switch(dataLength){
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
		case 12:
			return 9;
		case 16:
			return 10;
		case 20:
			return 11;
		case 24:
			return 12;
		case 32:
			return 13;
		case 48:
			return 14;
		case 64:
			return 15;
		default:
			return 255;
	}
}

inline uint8_t MCP2517_C::Get_Data_Length(uint8_t DLC){
	switch(DLC){
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

// Interrupt handler for CAN controller
inline void MCP2517_C::Handler(){
	if (com->SPI.INTFLAG.bit.TXC && com->SPI.INTENSET.bit.TXC) {
		com->SPI.INTENCLR.reg = SERCOM_SPI_INTENCLR_TXC;
		// End transmission
		Select_Slave(false);
		currentState = Idle;
	}
	if (com->SPI.INTFLAG.bit.DRE && com->SPI.INTENSET.bit.DRE) {
		// Data register empty
		com->SPI.INTFLAG.reg = SERCOM_SPI_INTENSET_TXC;		// Clear flag
		if (currentState == Tx) {
			com->SPI.DATA.reg = msgBuff[txIndex];
		} else {
			if (txIndex <= 2){
				// Send instruction and address bytes
				com->SPI.DATA.reg = msgBuff[txIndex];
			} else {
				// Send dummy byte
				com->SPI.DATA.reg = 0;		
			}
			
		}
		
		txIndex++;
		
		if (txIndex >= msgLength) {
			com->SPI.INTENCLR.reg = SERCOM_SPI_INTENCLR_DRE;
			if (currentState == Tx) {
				com->SPI.INTENSET.reg = SERCOM_SPI_INTENSET_TXC;	// Wait for transmission complete
			}
		}
	}
	if (com->SPI.INTFLAG.bit.RXC && com->SPI.INTENSET.bit.RXC) {
		if (currentState == Rx) {
			msgBuff[rxIndex++] = com->SPI.DATA.reg;
			if (rxIndex >= msgLength) {
				Select_Slave(false);
				currentState = Rx_Ready;
			}
		} else {
			volatile uint8_t dumdum = com->SPI.DATA.reg;
		}
	}
	
}

#endif /* MCP2517_H_ */