#ifndef TLOG_TINY_H
#define TLOG_TINY_H

#include <Arduino.h>

void printT(unsigned char logLevel, const char *format, ...) {
  va_list args;
  va_start(args, format);

  Serial.print(logLevel);
  Serial.print(": ");

  char ch;
  while ((ch = *format++) != '\0') {
    if (ch == '%') {
      ch = *format++;
      if (ch == '\0') break;
      switch(ch) {
        case '%':
          Serial.print('%');
          break;
        case 'd':
        case 'i':
          Serial.print(va_arg(args, int));
          break;
        case 'f':
          Serial.print(va_arg(args, double));
          break;
        case 's':
          Serial.print(va_arg(args, char*));
          break;
        case 'b':
          Serial.print(va_arg(args, int), BIN);
          break;
        case 'c':
          char value = (char) va_arg(args, int);
          Serial.print(value);
          break;
        case 'o':
          Serial.print(va_arg(args, unsigned int), OCT);
          break;
        case 'x':
        case 'X':
          Serial.print(va_arg(args, unsigned int), HEX);
          break;
      }
    } else {
      Serial.print(ch);
    }
  }

  va_end(args);
  Serial.println(); // 添加换行符
}


#if defined(DEBUG) || defined(INFO) || defined(ERROR)
  #define errorT(...) printT('E', __VA_ARGS__)
#else
  #define errorT(...) // nothing
#endif

#if defined(DEBUG) || defined(INFO) || (!defined(DEBUG) && !defined(INFO) && !defined(ERROR))
  #define infoT(...) printT('I', __VA_ARGS__)
#else
  #define infoT(...) // nothing
#endif

#ifdef DEBUG
  #define debugT(...) printT('D', __VA_ARGS__)
#else
  #define debugT(...) // nothing
#endif

#endif // TLOG_TINY_H
