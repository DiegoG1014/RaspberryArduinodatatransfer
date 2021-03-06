#include "codec.h"

char decoder[99] {
  "SIGNAL",
  "START",
  " ",
  "!",
  "\"",
  "#",
  "$",
  "%",
  "&",
  "'",
  "(",
  ")",
  "*",
  "+",
  ",",
  "-",
  ".",
  "/",
  "0",
  "1",
  "2",
  "3",
  "4",
  "5",
  "6",
  "7",
  "8",
  "9",
  ":",
  ";",
  "<",
  "=",
  ">",
  "?",
  "@",
  "A",
  "B",
  "C",
  "D",
  "E",
  "F",
  "G",
  "H",
  "I",
  "J",
  "K",
  "L",
  "M",
  "N",
  "O",
  "P",
  "Q",
  "R",
  "S",
  "T",
  "U",
  "V",
  "W",
  "X",
  "Y",
  "Z",
  "[",
  "\\",
  "]",
  "^",
  "?",
  "_",
  "`",
  "a",
  "b",
  "c",
  "d",
  "e",
  "f",
  "g",
  "h",
  "i",
  "j",
  "k",
  "l",
  "m",
  "n",
  "o",
  "p",
  "q",
  "r",
  "s",
  "t",
  "u",
  "v",
  "w",
  "x",
  "y",
  "z",
  "{",
  "|",
  "}",
  "~",
  "END"
};

int encoder[99][8] {
  {1,0,1,1,0,1,0,1},
  {0,0,1,0,0,0,0,0},
  {0,0,1,0,0,0,0,1},
  {0,0,1,0,0,0,1,0},
  {0,0,1,0,0,0,1,1},
  {0,0,1,0,0,1,0,0},
  {0,0,1,0,0,1,0,1},
  {0,0,1,0,0,1,1,0},
  {0,0,1,0,0,1,1,1},
  {0,0,1,0,1,0,0,0},
  {0,0,1,0,1,0,0,1},
  {0,0,1,0,1,0,1,0},
  {0,0,1,0,1,0,1,1},
  {0,0,1,0,1,1,0,0},
  {0,0,1,0,1,1,0,1},
  {0,0,1,0,1,1,1,0),
  {0,0,1,0,1,1,1,1),
  {0,0,1,1,0,0,0,0),
  {0,0,1,1,0,0,0,1),
  {0,0,1,1,0,0,1,0),
  {0,0,1,1,0,0,1,1),
  {0,0,1,1,0,1,0,0),
  {0,0,1,1,0,1,0,1),
  {0,0,1,1,0,1,1,0),
  {0,0,1,1,0,1,1,1),
  {0,0,1,1,1,0,0,0),
  {0,0,1,1,1,0,0,1),
  {0,0,1,1,1,0,1,0},
  {0,0,1,1,1,0,1,1},
  {0,0,1,1,1,1,0,0},
  {0,0,1,1,1,1,0,1},
  {0,0,1,1,1,1,1,0},
  {0,0,1,1,1,1,1,1},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,1},
  {0,1,0,0,0,0,1,0},
  {0,1,0,0,0,0,1,1},
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,1},
  {0,1,0,0,0,1,1,0},
  {0,1,0,0,0,1,1,1},
  {0,1,0,0,1,0,0,0},
  {0,1,0,0,1,0,0,1},
  {0,1,0,0,1,0,1,0},
  {0,1,0,0,1,0,1,1},
  {0,1,0,0,1,1,0,0},
  {0,1,0,0,1,1,0,1},
  {0,1,0,0,1,1,1,0},
  {0,1,0,0,1,1,1,1},
  {0,1,0,1,0,0,0,0},
  {0,1,0,1,0,0,0,1},
  {0,1,0,1,0,0,1,0},
  {0,1,0,1,0,0,1,1},
  {0,1,0,1,0,1,0,0},
  {0,1,0,1,0,1,0,1},
  {0,1,0,1,0,1,1,0},
  {0,1,0,1,0,1,1,1},
  {0,1,0,1,1,0,0,0},
  {0,1,0,1,1,0,0,1},
  {0,1,0,1,1,0,1,0},
  {0,1,0,1,1,0,1,1},
  {0,1,0,1,1,1,0,0},
  {0,1,0,1,1,1,0,1},
  {0,1,0,1,1,1,1,0},
  {0,0,1,1,1,1,1,1},
  {0,1,0,1,1,1,1,1},
  {0,1,1,0,0,0,0,0},
  {0,1,1,0,0,0,0,1},
  {0,1,1,0,0,0,1,0},
  {0,1,1,0,0,0,1,1},
  {0,1,1,0,0,1,0,0},
  {0,1,1,0,0,1,0,1},
  {0,1,1,0,0,1,1,0},
  {0,1,1,0,0,1,1,1},
  {0,1,1,0,1,0,0,0},
  {0,1,1,0,1,0,0,1},
  {0,1,1,0,1,0,1,0},
  {0,1,1,0,1,0,1,1},
  {0,1,1,0,1,1,0,0},
  {0,1,1,0,1,1,0,1},
  {0,1,1,0,1,1,1,0},
  {0,1,1,0,1,1,1,1},
  {0,1,1,1,0,0,0,0},
  {0,1,1,1,0,0,0,1},
  {0,1,1,1,0,0,1,0},
  {0,1,1,1,0,0,1,1},
  {0,1,1,1,0,1,0,0},
  {0,1,1,1,0,1,0,1},
  {0,1,1,1,0,1,1,0},
  {0,1,1,1,0,1,1,1},
  {0,1,1,1,1,0,0,0},
  {0,1,1,1,1,0,0,1},
  {0,1,1,1,1,0,1,0},
  {0,1,1,1,1,0,1,1},
  {0,1,1,1,1,1,0,0},
  {0,1,1,1,1,1,0,1},
  {0,1,1,1,1,1,1,0},
  {1,0,0,1,1,0,0,1}
};
