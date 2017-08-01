#define LDR_PIN 0
#define LED1_PIN 5
#define LED2_PIN 6
#define LED3_PIN 10

byte value = 0;

void setup() {
  pinMode(LDR_PIN, INPUT);

  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
  value = analogRead(LDR_PIN);

  //writeValueToSerial(value);

  if (value < 150) {
    analogWrite(LED1_PIN, random(120)+135);
    analogWrite(LED2_PIN, random(120)+135);
    analogWrite(LED3_PIN, random(120)+135);
  } else {
    analogWrite(LED1_PIN, 0);
    analogWrite(LED2_PIN, 0);
    analogWrite(LED3_PIN, 0);
  }
  
  delay(random(100));
}

void writeValueToSerial(int value) {
  String text = String(value);
  for(int i = 0; i < text.length(); i++)
    Serial.write(text[i]);
  Serial.write(13);
  Serial.write(10);
}

