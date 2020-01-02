#include <Arduino.h>

#define SET_LED              GPIOC_PDDR |= (1 << 5) 
#define SET_PORT_LED         PORTC_PCR5 |= (1 << 8)
#define LED_ON               GPIOC_PSOR |= (1 << 5)
#define LED_OFF              GPIOC_PCOR |= (1 << 5)
#define LED_TOGGLE           GPIOC_PTOR |= (1 << 5)

#define S_CLK                32000000
#define seconds(n)           (n)*S_CLK

void setLED(void);                            
void setPDB(void);
void setPIT(void);

