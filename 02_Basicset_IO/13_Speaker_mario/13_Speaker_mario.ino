const int spkrPin = 3; //3:ConnectorA 4:ConnectorB

#define DO 261.6
#define _DO 277.18
#define RE 293.665
#define _RE 311.127
#define MI 329.63
#define FA 349.228
#define _FA 369.994
#define SO 391.995
#define _SO 415.305
#define RA 440
#define _RA 466.164
#define TI 493.883
#define octDO 523.251
#define octRE 587.33
#define octME 659.26
#define octFA 698.456
#define octSO 783.99
#define octRA 880


void playmusic(){

// --- イントロ ---
ledcWriteTone(spkrPin, octME); 
delay(150);
ledcWriteTone(spkrPin, octME);
delay(150);
ledcWriteTone(spkrPin, 0);
delay(150);
ledcWriteTone(spkrPin, octME);
delay(150);
ledcWriteTone(spkrPin, 0);
delay(150);
ledcWriteTone(spkrPin, octDO);
delay(150);
ledcWriteTone(spkrPin, octME);
delay(150);
ledcWriteTone(spkrPin, 0);
delay(150);
ledcWriteTone(spkrPin, octSO);
delay(150);
ledcWriteTone(spkrPin, 0);
delay(300);
ledcWriteTone(spkrPin, SO);
delay(150);
ledcWriteTone(spkrPin, 0);
delay(300);


// --- メインテーマの出だし ---
ledcWriteTone(spkrPin, octDO);
delay(100);
ledcWriteTone(spkrPin, 0);
delay(250);
ledcWriteTone(spkrPin, SO);
delay(100);
ledcWriteTone(spkrPin, 0);
delay(250);  
ledcWriteTone(spkrPin, MI);
delay(100);
ledcWriteTone(spkrPin, 0);
delay(250);

ledcWriteTone(spkrPin, RA);
delay(150);
ledcWriteTone(spkrPin, 0);
delay(150);
ledcWriteTone(spkrPin, TI);
delay(150);
ledcWriteTone(spkrPin, _RA);
delay(150);
ledcWriteTone(spkrPin, RA);
delay(200);

ledcWriteTone(spkrPin, 0); 
delay(250);

ledcWriteTone(spkrPin, SO);
delay(100);
ledcWriteTone(spkrPin, 0);
delay(250);
ledcWriteTone(spkrPin, octME);
delay(100);
ledcWriteTone(spkrPin, 0);
delay(300);
ledcWriteTone(spkrPin, octSO);
delay(100);
ledcWriteTone(spkrPin, 0);
delay(250);
ledcWriteTone(spkrPin, octRA);
delay(100);
ledcWriteTone(spkrPin, 0);
delay(300);
ledcWriteTone(spkrPin, octSO);
delay(100);

ledcWriteTone(spkrPin, octME); 
delay(100);
ledcWriteTone(spkrPin, 0);     
delay(30);
ledcWriteTone(spkrPin, octDO); 
delay(100);
ledcWriteTone(spkrPin, 0);     
delay(30);
ledcWriteTone(spkrPin, octRE); 
delay(100);
ledcWriteTone(spkrPin, 0);     
delay(30);
ledcWriteTone(spkrPin, TI);    
delay(100);
ledcWriteTone(spkrPin, 0);     
delay(300);




}

void setup() {
  pinMode(spkrPin, OUTPUT);
  ledcAttach(spkrPin, 12000, 8); //Pin setting(Pin num, Max frequency, Resolution)
}

void loop() {
  playmusic();
  delay(3000);
}
