int morseCodes[96] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0, // 32 - [SPACE]
    212122, // 33 - !
    121121, // 34 - "
    0, // 35 - #
    1112112,// 36 - $
    0, // 37 - %
    12111, // 38 - &
    122221, // 39 - '
    21221, // 40 - (
    212212, // 41 - )
    1, // 42 - *
    12121, // 43 - +
    221122, // 44 - ,
    211112, // 45 - -
    121212, // 46 - .
    21121, // 47 - /
    22222, // 48 - 0
    12222, // 49 - 1
    11222, // 50 - 2
    11122, // 51 - 3
    11112, // 52 - 4
    11111, // 53 - 5
    21111, // 54 - 6
    22111, // 55 - 7
    22211, // 56 - 8
    22221, // 57 - 9
    222111, // 58 - :
    212121, // 59 - ;
    0, // 60 - <
    21112, // 61 - =
    0, // 62 - >
    112211, // 63 - ?
    122121, // 64 - @
    12, // 65 - A
    2111, // 66 - B
    2121, // 67 - C
    211, // 68 - D
    0, // 69 - E
    1121, // 70 - F
    221, // 7- - G
    1111, // 72 - H
    11, // 73 - I
    1222, // 74 - J
    212, // 75 - K
    1211, // 76 - L
    22, // 77 - M
    21, // 78 - N
    222, // 79 - O
    1221, // 80 - P
    2212, // 81 - Q
    121, // 82 - R
    111, // 83 - S
    0, // 84 - T
    112, // 85 - U
    1112, // 86 - V
    122, // 87 - W
    2112, // 88 - X
    2122, // 89 - Y
    2211, // 90 - Z
    0, // 91 - [
    0, // 92 -
    0, // 93 - ]
    0, // 94 - ^
    112212, // 95 - _
};

int ledPin = 12;

int count_digit(int number) {
   int count = 0;
   while(number != 0) {
      number = number / 10;
      count++;
   }
   return count;
}

int power(int base, int exponent) {
    int value = base;
    if (exponent == 0) {
    	return 1;
    }
    for (int b = 1; b < exponent; b++) {
        value *= base;
    }
    return value;
}

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    Serial.println("start");
    String input = "n0n";
    int timeunit = 100;

    digitalWrite(LED_BUILTIN, LOW);
    int i;
    for (i = 0; i < input.length(); i++) {
        if (input.charAt(i) == ' ') {
            delay(timeunit * 7);
        } else {
            delay(timeunit * 3);

            int n;
            int thisMorse = morseCodes[input.charAt(i)];
            Serial.println(morseCodes[input.charAt(i)]);

            if (thisMorse == 0) {
                Serial.println("continued");
                continue;
            }

            for (n = 0; n < count_digit(thisMorse); n++) {
                int d = (thisMorse / power(10, n)) % 10;
                if (d == 1) {
                    Serial.println("dit");
                    digitalWrite(ledPin, HIGH);
                    delay(timeunit);
                    digitalWrite(ledPin, LOW);
                } else if (d == 2) {
                    Serial.println("dah");
                    digitalWrite(ledPin, HIGH);
                    delay(timeunit * 3);
                    digitalWrite(ledPin, LOW);
                }
            }
        }
    }
    delay(100000000000000000000000000000);
}
