
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = "805b94d7-1881-4f2f-9eed-faee28c4c522";

const char SSID[]               = SECRET_SSID;    // Network SSID (name)
const char PASS[]               = SECRET_OPTIONAL_PASS;    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = SECRET_DEVICE_KEY;    // Secret device password

void onLedChange();
void onViberateChange();
void onVibratorButtonChange();

bool Led;
bool viberate;
bool Vibrator_Button;
CloudTime time_read;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(Led, READWRITE, ON_CHANGE, onLedChange);
  ArduinoCloud.addProperty(viberate, READWRITE, ON_CHANGE, onViberateChange);
  ArduinoCloud.addProperty(Vibrator_Button, READWRITE, ON_CHANGE, onVibratorButtonChange);
  ArduinoCloud.addProperty(time_read, READ, ON_CHANGE, NULL);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
