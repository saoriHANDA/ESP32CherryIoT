const int litsnsrPin = 3; //3:ConnectorA 4:ConnectorB

void setup() { //void setup()変数がないときは()かっこのみ
  Serial.begin(115200);
  pinMode(litsnsrPin, INPUT);
}

void loop() {
  float litsnsr_ad = analogRead(litsnsrPin); // Read analog data　アナログ値を読むセンサー
  float litsnsr_v = litsnsr_ad * 3.3 / 4096; // Calculation of voltage value　分解能　
  float lux = 10000 * litsnsr_v / (3.3 - litsnsr_v) / 1000; // Calculation of lux value　LUXの計算

  //Look at the serial monitor
  Serial.print(lux);//変数 lux に格納された明るさの値をシリアルモニタに表示します。
  Serial.print(" Lux : ");//: 文字列 Lux : をその後に続けて表示し、単位を見やすくします。 
  
  // Change the threshold to suit your environment
  if (lux > 70) { //luxが20より大きいとき
    Serial.println("Bright");//Bright と表示します。　　printlnのlnは改行
    delay(500);
  } else {//そうじゃなければ
    Serial.println("Dark");//Dark と表示します。
    delay(500);
  }
}
