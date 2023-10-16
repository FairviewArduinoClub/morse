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
    pinMode(LED_BUILTIN, OUTPUT);

    String input = "hi";
    int timeunit = 100;

    int i;
    for (i = 0; i < input.length(); i++) {
        if (input.charAt(i) == ' ') {
            delay(timeunit * 7);
        } else {
            delay(timeunit * 3);

            int asciiCode = (int) input.charAt(i);
            int n;
            for (n = 0; n < morseCodes[asciiCode].length(); n++) {
                if (morseCodes[asciiCode][n] == '.') {
                    digitalWrite(LED_BUILTIN, HIGH);
                    delay(timeunit);
                    digitalWrite(LED_BUILTIN, LOW);
                } else if (morseCodes[asciiCode][n] == '-') {
                    digitalWrite(LED_BUILTIN, HIGH);
                    delay(timeunit * 3);
                    digitalWrite(LED_BUILTIN, LOW);
                }
            }
        }
    }
}

void loop() {}
