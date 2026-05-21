//https://www.haruirosoleil.com/entry/2020/02/02/101937
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <DHT20.h> //DHT20 by RobTillaart
#include <Wire.h>

DHT20 DHT;

// 接続先のSSIDとパスワード
const char* ssid = "XXXXXXXXX"; //無線ルーターのssidを入力
const char* password = "XXXXXXXX"; //無線ルーターのパスワードを入力

const int litsnsrPin = 3; //3:ConnectorA 4:ConnectorB
const int ledPin = 4; //3:ConnectorA 4:ConnectorB

void setup() {
  Serial.begin(115200);
  Wire.begin(1, 3); //1,3:ConnectorA 5,4:ConnectorB //温度・湿度計に対して
  
  pinMode(ledPin, OUTPUT);
  
}

void loop() { 
  DHT.read();
  float Temperature = DHT.getTemperature();
  float Humidity = DHT.getHumidity();
  //シリアルモニタに表示
  Serial.print(String(Temperature) + "℃");
  Serial.print(" / ");
  Serial.println(String(Humidity) + "％");
  delay(500);

if (Humidity >= 60) {
  digitalWrite(ledPin, HIGH);
  Serial.println("💧湿度高め！くせ毛警告ライトON");
} else {
  digitalWrite(ledPin, LOW);
  Serial.println("✅湿度正常");  }
  delay(500);

  // スプレッドシートへ送信
  sendData();
  delay(20000);// 次の計測まで20秒待機

}


//WiFiに接続
void connectWiFi(){

  Serial.print("ssid:");
  Serial.print(ssid);
  Serial.println(" に接続します。");

  WiFi.begin(ssid, password);

  Serial.print("WiFiに接続中");
  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("接続しました。");

  //IPアドレスの表示
  Serial.print("IPアドレス:");
  Serial.println(WiFi.localIP());
}

 

//測定データの送信
void sendData(){

  WiFiClientSecure sslclient;

  const char* server = "script.google.com";
  String url = "//googlescript web appのurlを入力//"; 

  //測定値を準備
  DHT.read();
  float Temperature = DHT.getTemperature();//温度データ
  float Humidity = DHT.getHumidity();//湿度データ

  float sensor_data1= Temperature; 
  float sensor_data2= Humidity;
  
  //wifiに接続
  connectWiFi();

  //測定値の表示
  //Serial.println(sensor_data1);
  //Serial.println(sensor_data2);
  //Serial.println(sensor_data3);

  //urlの末尾に測定値を加筆
  url += "?";
  url += "&1_cell=";
  url += sensor_data1;
  url += "&2_cell=";
  url += sensor_data2;
  //url += "&3_cell=";
  //url += sensor_data3;
 

  // サーバーにアクセス
  Serial.println("サーバーに接続中...");
  sslclient.setInsecure(); //skip verification
  //データの送信
  if (!sslclient.connect(server, 443)) {
    Serial.println("接続に失敗しました");
    Serial.println("");//改行
    return;
  }

  Serial.println("サーバーに接続しました");

  sslclient.println("GET " + url);
  delay(1000); //私の環境ではここに待ち時間を入れないとデータが送れないことがある
  sslclient.stop();

  Serial.println("データ送信完了");
  Serial.println("");//改行

  //WiFiを切断
  WiFi.mode(WIFI_OFF);
}
