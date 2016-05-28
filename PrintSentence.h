/*
  Library for automatically adding line breaks to sentences and paragraphs and, printing
  them to fit  OLED screens. To be used with Espert Library (for now).
*/

#ifndef PrintSentence_h
#define PrintSentence_h

#include "Arduino.h"
#include "Espert.h"

class PrintSentence
{
  public:
    void splitSn();
    void printSn();
  private:
};

#endif
