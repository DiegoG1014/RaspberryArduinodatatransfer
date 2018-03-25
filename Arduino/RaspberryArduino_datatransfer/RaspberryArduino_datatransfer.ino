#include "codec.h"
#include "bytearray.h"

const int dataIn  = 7;
const int dataOut = 8;

struct codec {
  int binary[8];
  char ascii;
};

float     readtime  = 0.0;
boolean   reading   = false;
boolean   readready = false;
bytearray readdata;
int       tempreaddata[8];

float     writetime = 0.0;
boolean   writing   = false;
bytearray writedata;

int freq = 16;

float dt = millis();
float prevTime = dt;

void setup() {
  pinMode(dataIn,INPUT);
  pinMode(dataOut,OUTPUT);
}

void loop() {
  dt = millis() - prevTime
  
  if (1/freq >= readtime) {
    if (reading) {
      readdata.add(digitalRead(dataIn),-1);
      if (readdata.isValid) {
        if (decode(readata.get(readdata.len-8,-1)) == "END") {
          readtime = 0;
          reading  = false;
          readdata.reset();
        };
      };
    } else { //check for START
      if (readready) {
        tempreaddata.add(digitalRead(dataIn),-1);
        if (tempreaddata.isValid) {
          if (decode(tempreaddata.get(0,-1)) == "START") {
            reading = true;
          } else {
            tempreaddata.reset();
          };
        };
      } else {
        tempreaddata.add(digitalRead(dataIn),-1);
        if (tempreaddata.isValid) {
          if (decode(tempreaddata.get(0,-1)) == "READY") {
            readready = true;
            writing   = true;
            writedata.set(encode("READY"));
          } else {
            tempreaddata.reset();
          };
        };
      };
    readtime = 0;
    };
  };
};
