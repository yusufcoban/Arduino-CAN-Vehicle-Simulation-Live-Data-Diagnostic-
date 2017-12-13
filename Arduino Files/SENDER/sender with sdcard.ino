#include <mcp_can.h>
#include <SPI.h>


/*
 * Example of getline from section 27.7.1.3 of the C++ standard
 * Demonstrates the behavior of getline for various exceptions.
 * See http://www.cplusplus.com/reference/iostream/istream/getline/
 *
 * Note: This example is meant to demonstrate subtleties the standard and
 * may not the best way to read a file.
 */
#include "SdFat.h"

//CANBUS
//#define CAN0_INT 2                              // Set INT to pin 2
MCP_CAN CAN0(9);                          // Set CS to pin 10



// SD chip select pin
const uint8_t chipSelect = 4;

// file system object
SdFat sd;

// create a serial stream
ArduinoOutStream cout(Serial);

//------------------------------------------------------------------------------
unsigned char message[8];
 char ptr1[]="engine.txt";
  char ptr2[]="airbag.txt";
  char ptr3[]="brake.txt";
  char ptr4[]="steering.txt";
  char ptr5[]="exhaust.txt";
  char ptr6[]="tachometer.txt";
  char ptr7[]="climate.txt";

int chartoint(char f) {
  if (f == 'a' || f== 'A'){
    return 10;
  }
 if (f == 'b' || f== 'B'){
    return 11;
  }
 if (f == 'c' || f== 'C'){
    return 12;
  }
 if (f == 'd' || f== 'D'){
    return 13;
  }
if (f == 'e' || f== 'E'){
    return 14;
  }
 if (f == 'f' || f== 'F'){
    return 15;
  }
  if (f == '1'){
    return 1;
  }
   if (f == '2'){
    return 2;
  }
  if (f == '3'){
    return 3;
  }
  if (f == '4'){
    return 4;
  }
  if (f == '5'){
    return 5;
  }
  if (f == '6'){
    return 6;
  }
  if (f == '7'){
    return 7;
  }
  if (f == '8'){
    return 8;
  }
  if (f == '9'){
    return 9;
  }
   if (f == '0'){
    return 0;
  }
 
 
  
}

  void sendingData(int zeile,char ptr[],int idinput) {
  const int line_buffer_size = 17;
  char buffer[line_buffer_size];
  ifstream sdin(ptr);
  int line_number = 0;
  int auswahl=zeile;
  int count = 10;
  int i=0;

  while (sdin.getline(buffer, line_buffer_size, '\n') || sdin.gcount()) {
   
    int count = sdin.gcount();
      i++;
      if(i==auswahl){
        break;
      }
      }
 
  message[0]=((chartoint(buffer[0])*16)+chartoint(buffer[1]));
  message[1]=((chartoint(buffer[2])*16)+chartoint(buffer[3]));
  message[2]=((chartoint(buffer[4])*16)+chartoint(buffer[5]));
  message[3]=((chartoint(buffer[6])*16)+chartoint(buffer[7]));
  message[4]=((chartoint(buffer[8])*16)+chartoint(buffer[9]));
  message[5]=((chartoint(buffer[10])*16)+chartoint(buffer[11]));
  message[6]=((chartoint(buffer[12])*16)+chartoint(buffer[13]));
  message[7]=((chartoint(buffer[14])*16)+chartoint(buffer[15]));

  int test=idinput;
  
  byte sndStat = CAN0.sendMsgBuf(test, 0, 8, message);
 
  /* 
   int char1=(chartoint(buffer[0]))*16+chartoint(buffer[1);
   int char2=(buffer[2]-'0')*16+(buffer[3]-'0');
   int char3=(buffer[4]-'0')*16+(buffer[5]-'0');
   int char4=(buffer[6]-'0')*16+(buffer[7]-'0');
   int char5=(buffer[8]-'0')*16+(buffer[9]-'0');
   int char6=(buffer[10]-'0')*16+(buffer[11]-'0');
   int char7=(buffer[12]-'0')*16+(buffer[13]-'0');
   int char8=(buffer[14]-'0')*16+(buffer[15]-'0');
   */
   
 /* for (int i=0;i<8;i++){
    Serial.print(message[i],HEX);
    }*/
}
//------------------------------------------------------------------------------
void setup(void) {
  Serial.begin(115200);
  
  // Wait for USB Serial 
  while (!Serial) {
    SysCall::yield();
  }

  // F stores strings in flash to save RAM
  //while (!Serial.available()) {
    SysCall::yield();
  

  // Initialize at the highest speed supported by the board that is
  // not over 50 MHz. Try a lower speed if SPI errors occur.
  if (!sd.begin(chipSelect, SD_SCK_MHZ(50))) {
    sd.initErrorHalt();
  }


  //CAN SETUP
if (CAN0.begin(MCP_STDEXT, CAN_500KBPS, MCP_16MHZ) == CAN_OK) Serial.print("MCP2515 Init Okay!!\r\n");
  else Serial.print("MCP2515 Init Failed!!\r\n");
  // pinMode(2, INPUT);                       // Setting pin 2 for /INT input
  Serial.println("MCP2515 Library Mask & Filter Example...");
  CAN0.setMode(MCP_NORMAL);                // Change to normal mode to allow messages to be transmitted


  
 

  
  for(int j=0;j<200;j++)
  {
   for (int i=0;i<200;i++){
    sendingData(i,ptr1,256);
    
    sendingData(i,ptr2,1);
   
    sendingData(i,ptr3,257);
    
    sendingData(i,ptr4,258);
    
    sendingData(i,ptr5,259);
   
    sendingData(i,ptr6,260);
    
    sendingData(i,ptr7,261);
    }

  }
 
}
//------------------------------------------------------------------------------
void loop(void) {}
