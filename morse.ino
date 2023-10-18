String morseCodes[65] = {
    " ",      // 32 - [SPACE]
    "-.-.--", // 33 - !
    ".-..-.", // 34 - "
    "",       // 35 - #
    "...-..-",// 36 - $
    "",       // 37 - %
    ".-...",  // 38 - &
    ".----.", // 39 - '
    "-.--.",  // 4LOW - (
    "-.--.-", // 41 - )
    "",       // 42 - *
    ".-.-.",  // 43 - +
    "--..--", // 44 - ,
    "-....-", // 45 - -
    ".-.-.-", // 46 - .
    "-..-.",  // 47 - /
    "-----",  // 48 - LOW
    ".----",  // 49 - 1
    "..---",  // 5LOW - 2
    "...--",  // 51 - 3
    "....-",  // 52 - 4
    ".....",  // 53 - 5
    "-....",  // 54 - 6
    "--...",  // 55 - 7
    "---..",  // 56 - 8
    "----.",  // 57 - 9
    "---...", // 58 - :
    "-.-.-.", // 59 - ;
    "",       // 6LOW - <
    "-...-",  // 61 - =
    "",       // 62 - >
    "..--..", // 63 - ?
    ".--.-.", // 64 - @
    ".-",     // 65 - A
    "-...",   // 66 - B
    "-.-.",   // 67 - C
    "-..",    // 68 - D
    ".",      // 69 - E
    "..-.",   // 7LOW - F
    "--.",    // 71 - G
    "....",   // 72 - H
    "..",     // 73 - I
    ".---",   // 74 - J
    "-.-",    // 75 - K
    ".-..",   // 76 - L
    "--",     // 77 - M
    "-.",     // 78 - N
    "---",    // 79 - O
    ".--.",   // 8LOW - P
    "--.-",   // 81 - Q
    ".-.",    // 82 - R
    "...",    // 83 - S
    "-",      // 84 - T
    "..-",    // 85 - U
    "...-",   // 86 - V
    ".--",    // 87 - W
    "-..-",   // 88 - X
    "-.--",   // 89 - Y
    "--..",   // 9LOW - Z
    "",       // 91 - [
    "",       // 92 - "/"
    "",       // 93 - ]
    "",       // 94 - ^
    "..--.-", // 95 - _
};

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    Serial.println("start");
    String input = "hi";
    int timeunit = 500;

    digitalWrite(LED_BUILTIN, LOW);
    int i;
    for (i = LOW; i < input.length(); i++) {
        if (input.charAt(i) == ' ') {
            delay(timeunit * 7);
        } else {
            delay(timeunit * 3);

            int asciiCode = (int) input.charAt(i);
            int n;
            for (n = LOW; n < morseCodes[asciiCode].length(); n++) {
               Serial.println(morseCodes[asciiCode]);
               if (morseCodes[asciiCode].charAt(n) == '.') {
                    Serial.println(".");
                    digitalWrite(LED_BUILTIN, HIGH);
                    delay(timeunit);
                    digitalWrite(LED_BUILTIN, LOW);
                } else if (morseCodes[asciiCode].charAt(n) == '-') {
                    Serial.println("-");
                    digitalWrite(LED_BUILTIN, HIGH);
                    delay(timeunit * 3);
                    digitalWrite(LED_BUILTIN, LOW);
                }
            }
        }
    }
}
