﻿/*
 * SPI_RP2040.h
 *
 * Created: 25/09/2023
 *  Author: GuavTek
 */ 


#ifndef SPI_RP2040_H_
#define SPI_RP2040_H_
#include "communication_base.h"
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/dma.h"

struct spi_config_t {
	uint8_t dma_irq_num;
	spi_cpha_t phase;
	spi_cpol_t polarity;
	spi_order_t order;
	uint32_t speed;
	uint8_t pin_tx;
	uint8_t pin_rx;
	uint8_t pin_ck;
	uint8_t pin_cs[16];
};

class SPI_RP2040_C : public communication_base_c
{
	public:
		void Init(const spi_config_t config);
		inline void Handler();
		uint8_t Transfer(char* buff, uint8_t length, com_state_e state);
		inline int8_t get_dma_rx() {return dmaRx;}
		inline int8_t get_dma_tx() {return dmaTx;}
		virtual inline uint8_t Select_Slave(uint8_t slaveNum, uint8_t enabled);
		SPI_RP2040_C(spi_inst_t* const comInstance, uint8_t num_ss) : communication_base_c(num_ss), com(comInstance){} ;
		~SPI_RP2040_C(){};
	protected:
		spi_inst_t* const com;
		uint8_t dmaNum;
		int8_t dmaRx;
		int8_t dmaTx;
		uint8_t lastSlave;
		uint8_t slaveSelected;
		uint8_t* csPin;
};

inline uint8_t SPI_RP2040_C::Select_Slave(uint8_t slaveNum, uint8_t enabled) {
	if (enabled && !slaveSelected){
		gpio_put(csPin[slaveNum], 0);
		lastSlave = slaveNum;
		slaveSelected = 1;
		return 1;
	} else if (slaveNum == lastSlave) {
		gpio_put(csPin[slaveNum], 1);
		slaveSelected = 0;
		return 1;
	}
	return 0;
}

// SPI interrupt handler
inline void SPI_RP2040_C::Handler(){
	if (currentState == Idle){
		return;
	}
	if (dma_irqn_get_channel_status(dmaNum, dmaRx)){
		dma_irqn_acknowledge_channel(dmaNum, dmaRx);
		currentState = (com_state_e) (currentState & ~Rx);
	}
	if (dma_irqn_get_channel_status(dmaNum, dmaTx)){
		dma_irqn_acknowledge_channel(dmaNum, dmaTx);
		currentState = (com_state_e) (currentState & ~Tx);
	}
	if (currentState == Idle){
		slaveCallbacks[lastSlave]->com_cb();
	}
}

#endif /* SPI_RP2040_H_ */