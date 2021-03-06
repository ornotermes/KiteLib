/*
   KiteLib XBee API Receive Example

   This example receives packets using XBee API mode.
   In API mode, many XBee modules can form a mesh network.

   IMPORTANT: Before uploading this example, make sure that the XBee module
   is running API ROUTER/ENDPOINT firmware!
*/

// include the library
#include <KiteLib.h>

// XBee module is in slot A on the shield
XBee bee = Kite.ModuleA;

void setup() {
  Serial.begin(9600);

  // initialize XBee module with baudrate 9600
  Serial.print(F("[XBee] Initializing ... "));
  int state = bee.begin(9600);
  if (state == ERR_NONE) {
    Serial.println(F("success!"));
  } else {
    Serial.print(F("failed, code "));
    Serial.println(state);
    while (true);
  }

  // set PAN ID to 0x0123456789ABCDEF
  Serial.print(F("[XBee] Setting PAN ID ... "));
  uint8_t panId[] = {0x01, 0x23, 0x45, 0x67,
                     0x89, 0xAB, 0xCD, 0xEF};
  state = bee.setPanId(panId);
  if (state == ERR_NONE) {
    Serial.println(F("success!"));
  } else {
    Serial.print(F("failed, code "));
    Serial.println(state);
    while (true);
  }
}

void loop() {
  // check if XBee received some data
  if (bee.available() > 0) {
    // print source address
    Serial.print("[XBee] Packet source:\t");
    Serial.println(bee.getPacketSource());
    
    // print data
    Serial.print("[XBee] Packet data:\t");
    Serial.println(bee.getPacketData());
  }
}
