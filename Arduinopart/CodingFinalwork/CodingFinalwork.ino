const int BUTTON = 2;
const int LED = 13;
const int SOUND_PIN = A0;
int BUTTONstate = 0;

int val = 0;
int old_val = 0;
int state = 0;

void setup() {
    // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
    pinMode(BUTTON, INPUT);
     Serial.begin(9600);
}

void loop() {
    // put your main code here, to run repeatedly:
   
digitalWrite(LED, LOW);
    
    // 读取A0模拟信号
  int value = analogRead(SOUND_PIN);
  // 输出信号值
 
  if(value > 200){
    // 大于阈值，则想引脚13输出低电平，LED灭
    digitalWrite(LED, HIGH);
    Serial.println(value);
    //Serial.write("b");
// 大于阈值，向openframework发送"b"
    delay(100);
  }
  else{
    //Serial.println(value);
    // 小于阈值，则想引脚13输出高电平，LED亮
    //digitalWrite(LED, HIGH);
    delay(100);
  }
}
    
  
