float kp = 1.2, ki = 0.02, kd = 0.5;

float target = 0;
float current = 0;

float prev_error = 0;
float i_error = 0;

bool input_done = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Enter target and initial speed:");
}

void loop() {

  if (!input_done) {
    if (Serial.available() > 0) {
      target = Serial.parseFloat();
      while (Serial.available() == 0);
      current = Serial.parseFloat();
      input_done = true;
      Serial.println("=== PID SPEED CONTROL ===");
    }
    return;
  }

  float p_error = target - current;
  i_error += p_error;
  float d_error = p_error - prev_error;

  float output = kp*p_error + ki*i_error + kd*d_error;

  current += output * 0.1;

  current += (rand()%5 - 2);

  Serial.print("Target: ");
  Serial.print(target);
  Serial.print(" | Current: ");
  Serial.print(current);
  Serial.print(" | Error: ");
  Serial.print(p_error);
  Serial.print(" | Output: ");
  Serial.println(output);

  prev_error = p_error;

  delay(500);
}