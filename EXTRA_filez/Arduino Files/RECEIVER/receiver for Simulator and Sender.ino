
#include <mcp_can.h>
#include <SPI.h>

long unsigned int rxId;
long unsigned int aPePos;
unsigned char len = 0;
unsigned char rxBuf[8];
String mystring = "";
long unsigned int APP;
long unsigned int BPP;
String dir="";
unsigned char idTest;
unsigned char inputData[8] = {0x25, 0x42, 0xa3, 0x22, 0x86, 0x61, 0xA7, 0xf8};

String engine="0000000000000000";
String brake="0000000000000000";
String airbag="0000000000000000";
String steering="0000000000000000";
String exhaust="0000000000000000";
String tachometer="0000000000000000";
String climate="0000000000000000";



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
    

char charToHex(unsigned char c) {
  if (c <= '9')
    return c - '0';
  if (c <= 'F')
    return c - 'A' + 10;
  if (c <= 'f')
    return c - 'a' + 10;
  return 0;
}


String CTH(unsigned char f) {

  if (f <= 10){
    return "0a";
  }
  if (f <= 11){
    return "0b";}
  if (f <= 12){
    return "0c";}
  if (f <= 13){
    return "0d";}
  if (f <= 14){
    return "0e";}

  if (f <= 15){
    return "0f";}
  
  

}


String adder(unsigned char input){
 
  if(input<=9){
   String z = "";
   String x="0";
      x.concat(input);
      z = x;
      return z;
    
    
    }
    else{
      String z = CTH(input);
   
      return z;
      }
  
  
  
  }

void filter(unsigned char rxBuf[], long unsigned int rxId){ 
  if (rxId==0x100){
    
      for (int i = 0; i < 8; i++) {
          if(rxBuf[i]<16){
            mystring=mystring+adder(rxBuf[i]);
            }
        
         else{
          mystring = mystring + String(rxBuf[i], HEX);
          } 
  }
     engine=mystring;
     mystring="";
     
    }


  if (rxId==0x001){
    
    for (int i = 0; i < 8; i++) {
          if(rxBuf[i]<16){
            mystring=mystring+adder(rxBuf[i]);
            }
        
         else{
          mystring = mystring + String(rxBuf[i], HEX);
          } 
  }
     airbag=mystring;
     mystring="";
  }


    if (rxId==0x101){
    for (int i = 0; i < 8; i++) {
          if(rxBuf[i]<16){
            mystring=mystring+adder(rxBuf[i]);
            }
        
         else{
          mystring = mystring + String(rxBuf[i], HEX);
          } 
  }
     brake=mystring;
     mystring="";
     
     
    }


if (rxId==0x102){
    
for (int i = 0; i < 8; i++) {
          if(rxBuf[i]<16){
            mystring=mystring+adder(rxBuf[i]);
            }
        
         else{
          mystring = mystring + String(rxBuf[i], HEX);
          } 
  }
     steering=mystring;
     mystring="";
     
    }


if (rxId==0x103){
    
for (int i = 0; i < 8; i++) {
          if(rxBuf[i]<16){
            mystring=mystring+adder(rxBuf[i]);
            }
        
         else{
          mystring = mystring + String(rxBuf[i], HEX);
          } 
  }
     exhaust=mystring;
     mystring="";
          
    }


if (rxId==0x104){
    
for (int i = 0; i < 8; i++) {
          if(rxBuf[i]<16){
            mystring=mystring+adder(rxBuf[i]);
            }
        
         else{
          mystring = mystring + String(rxBuf[i], HEX);
          } 
  }
     tachometer=mystring;
     mystring="";
     
    }


    
if (rxId==0x105){
    
     for (int i = 0; i < 8; i++) {
          if(rxBuf[i]<16){
            mystring=mystring+adder(rxBuf[i]);
            }
        
         else{
          mystring = mystring + String(rxBuf[i], HEX);
          } 
  }
     climate=mystring;
     mystring="";
     
     
    }












    
  
  }


void loop() {
  // put your main code here, to run repeatedly:

 Serial.println(engine+brake+airbag+steering+exhaust+tachometer+climate);
 delay(1000);



 if (CAN_MSGAVAIL == CAN0.checkReceive())           // check if data coming
  {
    CAN0.readMsgBuf(&rxId, &len, rxBuf); // Read data: len = data length, buf = data byte(s)
    filter(rxBuf, rxId);
  }














  
  
}
