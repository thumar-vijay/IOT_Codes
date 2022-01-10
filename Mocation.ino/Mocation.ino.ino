int led=12; // the pin that the LED is atteched to
int sensor=2; // the pin that the sensor is atteched to
int state=LOW; // by default, no motion detected
int val=0; // variable to store the sensor status (value)

void setup() {
    pinMode(led, OUTPUT); // initalize LED as an output
    pinMode(sensor, INPUT); // initialize sensor as an input
    Serial.begin(9600); // initialize serial
}

void loop() {
    val=digitalRead(sensor); // read sensor value

    if (val==HIGH) {
        // check if the sensor is HIGH
        digitalWrite(led, LOW); // turn LED ON
        Serial.println("*********Magic Motion detected!*********");
        int dtime=20;

        while (dtime !=0) {

            for (dtime; dtime>0; dtime--) {
              Serial.print("Countdown: ");
                Serial.println(dtime);

                if(dtime <=10) {
                    Serial.print("Action ");
                    val=digitalRead(sensor); // read sensor value

                    if(val==1) {
                        dtime=20;
                        Serial.println(val);
                    }
                }

                delay(1000);
            }
        }

        //        Timer and count down end

        if (state==LOW) {
            state=HIGH; // update variable state to HIGH
        }
    }

    else {
        digitalWrite(led, HIGH); // turn LED OFF
        delay(500); // delay 200 milliseconds 

        if (state==HIGH) {
            Serial.println("Motion stopped!");
            state=LOW; // update variable state to LOW
        }
    }
}
