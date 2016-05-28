#include "Arduino.h"
#include "Espert.h"
#include "PrintSentence.h"

PrintSentence::PrintSentence()
{

}

void PrintSentence::splitSn()
{
  int j = 0;
  int index = text.indexOf(del);
  while (text.length() > 0 && index > 0) {
    words[j] = text.substring(0, index);
    text = text.substring(index + 1);
    j++;
    index = text.indexOf(del);
  }
}

void PrintSentence::printSn()
{
  const int arrayLength = width * height;
  String words[arrayLength];
  String del = " ";
  splitSn(text, words, del);
  int j = 0;
  int sum = 0;
  String lines[height];
  for (int i = 0; i < 200; i++) {
    if (words[i] == NULL) {
      break;
    }
    else if (lines[j] == NULL) {
      lines[j] = words[i] + " ";
    }
    else if (lines[j].length() + words[i].length() < width) {
      lines[j] = lines[j] + words[i] + " ";
    }
    else if (lines[j].length() + words[i].length() == width) {
      lines[j] = lines[j] + words[i];
    }
    else {
      espert.oled.println(lines[j]);
      Serial.println(lines[j]);
      j++;
      lines[j] = lines[j] + words[i] + " ";
    }
  }
  espert.oled.println(lines[j]);
  Serial.println(lines[j]);
  espert.oled.update();
}
