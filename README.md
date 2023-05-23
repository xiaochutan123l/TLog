# TLogTiny
A simple, lightweight log library for MCU applications based on Arduino plattform. Output to serial. Support basic `%d, %i, %b, %c, %f(default precision 2), %s, %o, %x`. (Date width and presicion not support)

## Features
- A Arduino Log library, provides 3 levels `Info, Debug and Error`.

- C `printf()` style API, no need to use multiple `Serial.print()` for a single string output.

- Lightweight, using Macro to avoid compiling unneccesary logging code. Only slight more flash usage for the lib code and dynamic memory usage.

- Fast, almost same print speed as using `Serial.print/ln()`.

## Usage
1. define log level, default Info.
2. Set serial begin.
3. log

```c
#define T_INFO
//#define T_DEBUG
//#define T_ERROR

void setup() {
  Serial.begin(9600);
}

void loop() {
  //Serial.print("I: heiheiahunssrsgsgsdsdhthsdhsh ");
  //Serial.print(30.523);
  //Serial.println(" dsdhthsdhsh");
  infoT("heiheiahunssrsgsgsdsdhthsdhsh %f dsdhthsdhsh", 30.523);
  delay(1000);
}
```

## TODO
- support timestamp prefix
