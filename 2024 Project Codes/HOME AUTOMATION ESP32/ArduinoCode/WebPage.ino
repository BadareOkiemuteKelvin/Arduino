
String SendHTML(uint8_t fanStatus,uint8_t socketStatus,uint8_t bulbStatus,uint8_t acStatus,uint8_t pumpStatus){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>HOME AUTOMATION SYSTEM</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr +=".button {display: block;width: 80px;background-color: #3498db;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr +=".button-on {background-color: #3498db;}\n";
  ptr +=".button-on:active {background-color: #2980b9;}\n";
  ptr +=".button-off {background-color: #34495e;}\n";
  ptr +=".button-off:active {background-color: #2c3e50;}\n";
  ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>SMART</h1>\n";
  ptr +="<h2>HOME AUTOMATION SYSTEM</h2>\n";
 
   if(fanStatus)
  {ptr +="<p>FAN Status : ON</p><a class=\"button button-off\" href=\"/fanoff\">OFF</a>\n";}
  else
  {ptr +="<p>FAN Status: OFF</p><a class=\"button button-on\" href=\"/fanon\">ON</a>\n";}

  if(socketStatus)
  {ptr +="<p>Socket Status: ON</p><a class=\"button button-off\" href=\"/socketoff\">OFF</a>\n";}
  else
  {ptr +="<p>Socket Status: OFF</p><a class=\"button button-on\" href=\"/socketon\">ON</a>\n";}

  if(bulbStatus)
  {ptr +="<p>Bulb Status : ON</p><a class=\"button button-off\" href=\"/bulboff\">OFF</a>\n";}
  else
  {ptr +="<p>Bulb Status: OFF</p><a class=\"button button-on\" href=\"/bulbon\">ON</a>\n";}

  if(acStatus)
  {ptr +="<p>AC Status: ON</p><a class=\"button button-off\" href=\"/acoff\">OFF</a>\n";}
  else
  {ptr +="<p>AC Status: OFF</p><a class=\"button button-on\" href=\"/acon\">ON</a>\n";}


   if(pumpStatus)
  {ptr +="<p>Pump Status: ON</p><a class=\"button button-off\" href=\"/pumpoff\">OFF</a>\n";}
  else
  {ptr +="<p>Pump Status: OFF</p><a class=\"button button-on\" href=\"/pumpon\">ON</a>\n";}


  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}