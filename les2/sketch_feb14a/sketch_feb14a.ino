void setup() {
  Serial.begin(115200);
  pinMode(D3, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
}

void loop() {  
  int A = random(999);
  Serial.println(A);
  int B = random(999);
  Serial.println(B);
  int C = random(999);
  Serial.println(C);
  int D = random(999);
  Serial.println(D);

  digitalWrite(D3, LOW);
  digitalWrite(D5, LOW);
  digitalWrite(D6, LOW);
  
  Serial.println("\n");

  if (A > B || A < C)
  {
    digitalWrite(D3, HIGH);
    Serial.println("D3: High");
  }

  if (C > A && A < B)
  {
    digitalWrite(D5, HIGH);
    Serial.println("D5: High");
  }

  if (B > C && B > A && A < C)
  {
    digitalWrite(D6, HIGH);
    Serial.println("D6: High");
  }

  if (B > A && B > C && B > D)
  {
    digitalWrite(D3, HIGH);
    digitalWrite(D5, HIGH);
    digitalWrite(D6, HIGH);
    Serial.println("All: High");
    
  }
  
   delay(100);
  Serial.println("\n");
  }
