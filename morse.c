#define LED_PIN 12

String morseCodes[65] = {
  " ",      // 32 - [SPACE]
  "-.-.--", // 33 - !
  ".-..-.", // 34 - "
  "",       // 35 - #
  "...-..-",// 36 - $
  "",       // 37 - %
  ".-...",  // 38 - &
  ".----.", // 39 - '
  "-.--.",  // 40 - (
  "-.--.-", // 41 - )
  "",       // 42 - *
  ".-.-.",  // 43 - +
  "--..--", // 44 - ,
  "-....-", // 45 - -
  ".-.-.-", // 46 - .
  "-..-.",  // 47 - /
  "-----",  // 48 - 0
  ".----",  // 49 - 1
  "..---",  // 50 - 2
  "...--",  // 51 - 3
  "....-",  // 52 - 4
  ".....",  // 53 - 5
  "-....",  // 54 - 6
  "--...",  // 55 - 7
  "---..",  // 56 - 8
  "----.",  // 57 - 9
  "---...", // 58 - :
  "-.-.-.", // 59 - ;
  "",       // 60 - <
  "-...-",  // 61 - =
  "",       // 62 - >
  "..--..", // 63 - ?
  ".--.-.", // 64 - @
  ".-",     // 65 - A
  "-...",   // 66 - B
  "-.-.",   // 67 - C
  "-..",    // 68 - D
  ".",      // 69 - E
  "..-.",   // 70 - F
  "--.",    // 71 - G
  "....",   // 72 - H
  "..",     // 73 - I
  ".---",   // 74 - J
  "-.-",    // 75 - K
  ".-..",   // 76 - L
  "--",     // 77 - M
  "-.",     // 78 - N
  "---",    // 79 - O
  ".--.",   // 80 - P
  "--.-",   // 81 - Q
  ".-.",    // 82 - R
  "...",    // 83 - S
  "-",      // 84 - T
  "..-",    // 85 - U
  "...-",   // 86 - V
  ".--",    // 87 - W
  "-..-",   // 88 - X
  "-.--",   // 89 - Y
  "--..",   // 90 - Z
  "",       // 91 - [
  "",       // 92 - "/"
  "",       // 93 - ]
  "",       // 94 - ^
  "..--.-", // 95 - _
};

void setup() {
    pinMode(LED_PIN, OUTPUT);

    String input = "hi";

    int i;
    for (i = 0; i < length(input); i++) {
        if (input.charAt(i) == ' ') {
            delay(2000);
        } else {
            delay(1000);

            int asciiCode = (int) input.charAt(i);
            int n;
            for (n = 0; n < length(morseCodes[asciiCode]); n++) {
                if (morseCodes[asciiCode][n] == '.') {
                    delay(1000);
                    digitalWrite(LED_PIN, HIGH);
                } else if (morseCodes[asciiCode][n] == '-') {
                    delay(1000);
                    digitalWrite(LED_PIN, HIGH);
                }
            }
        }
    }
}

void loop() {
    String input = "hi";

    int i;
    for (i = 0; i < length(input); i++) {
        if (input.charAt(i) == ' ') {
            delay(2000);
        } else {
            delay(1000);

            int asciiCode = (int) input.charAt(i);
            int n;
            for (n = 0; n < length(morseCodes[asciiCode]); n++) {
                if (morseCodes[asciiCode][n] == '.') {
                    delay(1000);
                    //output to led
                } else if (morseCodes[asciiCode][n] == '-') {
                    delay(1000);
                    //output to led
                }
            }
        }
    }
}