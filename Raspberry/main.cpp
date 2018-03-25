#include <iostream>
#include <string>
using namespace std;

int main() {
    #include "codec.h"
    #include "bytearray.h"

    const short int dataIn  = 7;
    const short int dataOut = 8;

    long double     readtime  = 0.0;
    bool            reading   = false;
    bool            readready = false;
    bytearray       readdata;
    short int       tempreaddata[8];

    long double     writetime = 0.0;
    bool            writing   = false;
    bytearray       writedata;

    short int freq = 16;

    long double dt = millis();
    long double prevTime = dt;

    pinMode(dataIn,INPUT);
    pinMode(dataOut,OUTPUT);
    

    while(true) {
        dt = millis() - prevTime;
        
        if (1/freq >= readtime) {
            if (reading) {
            readdata.add(digitalRead(dataIn),-1);
            if (readdata.isValid) {
                if (decode(readata.get(readdata.len-8,-1)) == "END") {
                readtime = 0;
                reading  = false;
                readdata.reset();
                }
            }
            } else { //check for START
            if (readready) {
                tempreaddata.add(digitalRead(dataIn),-1);
                if (tempreaddata.isValid) {
                    if (decode(tempreaddata.get(0,-1)) == "START") {
                        reading = true;
                    } else {
                        tempreaddata.reset();
                    }
                }
            } else {
                tempreaddata.add(digitalRead(dataIn),-1);
                if (tempreaddata.isValid) {
                    if (decode(tempreaddata.get(0,-1)) == "READY") {
                        readready = true;
                        writing   = true;
                        writedata.set(encode("READY"));
                    } else {
                        tempreaddata.reset();
                    }
                }
            }
            readtime = 0;
            }
        }
    }
}