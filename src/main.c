#include "main.h"

void setLED(){
  SET_LED;
  SET_PORT_LED;
}

void setPIT(){
  SIM_SCGC6 |= SIM_SCGC6_PIT;                        //PIT clk

  PIT_MCR = 0;                                       // Enable PIT
  PIT_LDVAL0 = seconds(1);                           // Every 1 second
  PIT_TCTRL0 = PIT_TCTRL_TIE | PIT_TCTRL_TEN;        // Have an interrupt. START!

  NVIC_ENABLE_IRQ(IRQ_PIT_CH0);                      // Interrupt launched
}


void setPDB(){
  SIM_SCGC6 |= SIM_SCGC6_PDB;                          //PDB Clk

  PDB0_MOD = 37500;                                    // 1 seg
  
  PDB0_SC = PDB_SC_TRGSEL(15) | PDB_SC_PDBEN | 
            PDB_SC_PDBIE | PDB_SC_CONT | 
            PDB_SC_PRESCALER(4) | PDB_SC_MULT(1);      // Config
  
  PDB0_IDLY = 0;                                       // Interruption delay

  PDB0_SC |= PDB_SC_SWTRIG;                            // Sw trigger enabeled
  
  NVIC_ENABLE_IRQ(IRQ_PDB);                            // Interrupt launched
}

void setup() {
  setLED(); 
  //setPDB();
  //setPIT;
  LED_ON;
}

void pit0_isr(){
  PIT_TFLG0 |= 1;
  LED_TOGGLE;
}

void pdb_isr(void){ 
  PDB0_SC &= ~PDB_SC_PDBIF;                            // Clear flag
  LED_TOGGLE;
}

void loop() {
}