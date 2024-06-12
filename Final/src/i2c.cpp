#include "i2c.h"
#include <avr/io.h>
#include "Arduino.h"
#include <Wire.h>

#define wait_for_completion while(!(TWCR & (1 << TWINT)));

#define SLA_ADDRESS 0x60
#define SENSOR_CONFIGURATION 0x03
#define DISTANCE_REGISTER 0x08

void initI2C() {
  
  PRR0 &= ~(1<<PRTWI);  // wake up I2C module on AT2560 power management register
  TWSR |= (1 << TWPS0);  // prescaler power = 1
  TWSR &= ~(1 << TWPS1); // prescaler power = 1 
  //𝑇𝑊𝐵𝑅=((𝐶𝑃𝑈 𝐶𝑙𝑜𝑐𝑘 𝑓𝑟𝑒𝑞𝑢𝑒𝑛𝑐𝑦)/(𝑆𝐶𝐿 𝑓𝑟𝑒𝑞𝑢𝑒𝑛𝑐𝑦)−16)/(2∗〖(4)〗^𝑇𝑊𝑃𝑆 )
  TWBR = 0xC6; // bit rate generator = 10k  (TWBR = 198)

  TWCR |= (1 << TWINT )| (1 << TWEN); // enable two wire interface

}

 
void StartI2C_Trans(unsigned char SLA) {
// this function initiates a start condition and calls slave device with SLA
  TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN); // clear TWINT, intiate a start condition and enable
  wait_for_completion;
  TWDR = (SLA << 1); // slave address + write bit '0'
  TWCR = (1<<TWINT)|(1<<TWEN);  // trigger action:clear flag and enable TWI
  wait_for_completion;
}

void StopI2C_Trans() {
  // this function sends a stop condition to stop I2C transmission

  TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO); //trigger action:  send stop condition

}
void write(unsigned char data){
  // this function loads the data passed into the I2C data register and transmits
  TWDR = data; //load data into TWDR register
  TWCR = (1<<TWINT)|(1<<TWEN);  // trigger action:  clear flag and enable TWI
  wait_for_completion;
}
void Read_from(unsigned char SLA, unsigned char MEMADDRESS){
  // this function sets up reading from SLA at the SLA MEMADDRESS 

  StartI2C_Trans(SLA);
 
  write(MEMADDRESS);
  
  TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN); // restart to switch to read mode
  wait_for_completion;
  TWDR = (SLA << 1) | 0x01; // 7 bit address for slave plus read bit
  TWCR = (1 << TWINT) | (1 << TWEN)| (1 << TWEA);// trigger with master sending ack
  wait_for_completion;
  TWCR = (1<< TWINT) | (1 << TWEN);  // master can send a nack now
  wait_for_completion;
  TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO); // Stop condition
// after this function is executed the TWDR register has the data from SLA that Master wants to read
}

unsigned char Read_data() // Returns the last byte  from the data register
{
  return TWDR;
}

// void initializeDistanceSensor() {
//   StartI2C_Trans(SLA_ADDRESS); //turns on proximity sensor
  
//   Read_from(SLA_ADDRESS, DISTANCE_REGISTER);
//   write(SENSOR_CONFIGURATION);
//   write(0x00);
//   write(0x08);

//   StopI2C_Trans();
// }

// unsigned int getDistanceFromSensor() {
//   StartI2C_Trans(SLA_ADDRESS); //turns on proximity sensor

//   Read_from(SLA_ADDRESS, DISTANCE_REGISTER);

//   return Read_data();
// }



unsigned int readWithWire(unsigned char DISTANCE_ADDRESS){
    uint16_t tempData;
    //StartI2C_Trans(SLA);
    Wire.beginTransmission(SLA_ADDRESS);
    Wire.write(DISTANCE_ADDRESS);
    Wire.endTransmission(false);
    Wire.requestFrom(SLA_ADDRESS, 2, true);
    Wire.readBytes((uint8_t*)&tempData, 2);
    return tempData;
}

void initializeDistanceSensorWithWire() {
  //turns on proximity sensor
  Wire.beginTransmission(SLA_ADDRESS);
  Wire.write(SENSOR_CONFIGURATION);
  Wire.write(0x00);
  Wire.write(0x08);
  Wire.endTransmission();
}
  