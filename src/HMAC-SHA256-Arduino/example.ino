#include <Arduino.h>


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  uint8_t outdata[128] = {0};
  uint8_t md[SHA256_DIGESTLEN] = {0};
  uint8_t secret[] = {"helloarduino"};  //密钥
  uint8_t indata[] = {"helloword"};  //数据
  int len1 = strlen((char *)secret);
  int len2 = strlen((char *)indata);
  
  HMAC_SHA256_CTX hmac;
  hmac_sha256_init(&hmac, secret, len1);
  hmac_sha256_update(&hmac, indata, len2);
  hmac_sha256_final(&hmac, md);
  memcpy(outdata, md, SHA256_DIGESTLEN);
  while(1)
  {
    for(int i = 0; i < SHA256_DIGESTLEN; i++)
    {
      Serial.printf("%02x",outdata[i]);   //输出密文到串口 
    }
    Serial.println("\n");
    delay(3000);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
