// CAN Send Example
//

#include <mcp_can.h>
#include <SPI.h>

unsigned char inputData[8] = {0x25, 0x42, 0xa3, 0x22, 0x86, 0x61, 0xA7, 0xf8};
String mystring = "";


//#define CAN0_INT 2                              // Set INT to pin 2
MCP_CAN CAN0(9);                          // Set CS to pin 10



void setup()
{
  Serial.begin(115200);
  if (CAN0.begin(MCP_STDEXT, CAN_500KBPS, MCP_16MHZ) == CAN_OK) Serial.print("MCP2515 Init Okay!!\r\n");
  else Serial.print("MCP2515 Init Failed!!\r\n");
  // pinMode(2, INPUT);                       // Setting pin 2 for /INT input
  Serial.println("MCP2515 Library Mask & Filter Example...");
  CAN0.setMode(MCP_NORMAL);                // Change to normal mode to allow messages to be transmitted
}
    


/*
 AIRBAG = 001
 motor = 100
 brake = 101
 steering = 102
 exhaust = 103
 tachometer = 104
 climate = 105
 */
 
unsigned char engine[2][8] = {
{0xFA, 0x4E, 0x71, 0x62, 0x07, 0x14, 0x8D, 0x7E},
{0x1B, 0x86, 0x35, 0x62, 0x07, 0x14, 0x8D, 0x7E}};

unsigned char brake[8] = {0xA2, 0x41, 0x62, 0x45, 0x84, 0x94, 0x8D, 0x7E};

unsigned char steering[8] = {0xA2, 0x41, 0x62, 0x45, 0x84, 0x94, 0x8D, 0x7E};

unsigned char exhaust[8] = {0xA2, 0x41, 0x62, 0x45, 0x84, 0x94, 0x8D, 0x7E};

unsigned char tachometer[8] = {0xA2, 0x41, 0x62, 0x45, 0x84, 0x94, 0x8D, 0x7E};

unsigned char climate[8] = {0xA2, 0x41, 0x62, 0x45, 0x84, 0x94, 0x8D, 0x7E};

unsigned char airbag[8] = {0xA2, 0x41, 0x62, 0x45, 0x84, 0x94, 0x8D, 0x7E};




void loop()
{
  // send data:  ID = 0x100, Standard CAN Frame, Data length = 8 bytes, 'data' = array of data bytes to send
  for(int a=0; a<=99; a++){
    byte sndStat = CAN0.sendMsgBuf(0x100, 0, 8, engine[a]);
    delay(1000);
    sndStat = CAN0.sendMsgBuf(0x101, 0, 8, brake[a]);
    delay(1000);
    sndStat = CAN0.sendMsgBuf(0x105, 0, 8, climate[a]);
    delay(1000);
    sndStat = CAN0.sendMsgBuf(0x104, 0, 8, tachometer[a]);
    delay(1000);
    sndStat = CAN0.sendMsgBuf(0x102, 0, 8, steering[a]);
    delay(1000);
    sndStat = CAN0.sendMsgBuf(0x103, 0, 8, exhaust[a]);
    delay(1000);
    sndStat = CAN0.sendMsgBuf(0x001, 0, 8, airbag[a]);
    delay(1000);
  }
  /*if(sndStat == CAN_OK){
    Serial.println("Message Sent Successfully!");
  } 
  else {
    Serial.println("Error Sending Message...");
  }
  delay(1000);   // send data per 100ms*/
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
