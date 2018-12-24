#include "NokiaLCD.h"

using LCD = NokiaLCD<7, 6, 5, 11, 13>;
LCD lcd;

//  0000
// 0    0
// 0 00 0
// 0 00 0
// 0    0
//  0000


byte reverse(byte b) {
   b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
   b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
   b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
   return b;
}

//    |     |     |     |     |     |     |     |     |     |     |          
//  0b011110011110011110011110011110011110011110011110011110011110,
//    \      /\      /\      /\      /\      /\      /\      /\    
//      6 2     4 4      2 6     6 2
//    <<2 >>4  <<4 >>2  <<6 >>0
const byte element[] = {
  0b011110,
  0b100001,
  0b101101,
  0b101101,
  0b100001,
  0b011110
};

class Glass8x14 {  
  static constexpr size_t rowCount = 14;
  using Row = byte;
  using Fields = Row[rowCount];

public:
  explicit Glass8x14(LCD &lcd)
    : lcd(lcd)
    , fields({})
  {
  }
  
  void set(byte x, byte y) {
    Row &row = fields[y];
    row |= 1 << x;
  }
  
  void draw() {
    byte elementSet[6][6] = {};
    for (size_t i = 0; i < 6; ++i) {
      const byte b = element[i];
      for (size_t j = 0; j < 6; ++j) {
        const byte k = (j % 3) * 2 + 2;
        elementSet[i][j] = reverse((b << k) | (b >> (6 - k)));
      }
    }
    
    for (size_t i = 0; i < 6; ++i) {
      for (size_t j = 0; j < 6; ++j) {
        Serial.print(elementSet[i][j], BIN);
      }
      Serial.print('\n');
    }
    
    lcd.use(LCD::VerticalAddressing);
    lcd.gotoXY(0, 0);
//    lcd.LCDWrite(LCD::DATA, elementSet[0][0]);
//    lcd.LCDWrite(LCD::DATA, elementSet[0][1]);
//    lcd.LCDWrite(LCD::DATA, elementSet[0][2]);
//    lcd.LCDWrite(LCD::DATA, elementSet[0][3]);
//    lcd.LCDWrite(LCD::DATA, elementSet[0][4]);
//    lcd.LCDWrite(LCD::DATA, elementSet[0][5]);
//    lcd.LCDWrite(LCD::DATA, elementSet[1][0]);
//    lcd.LCDWrite(LCD::DATA, elementSet[1][1]);
//    lcd.LCDWrite(LCD::DATA, elementSet[1][2]);
//    lcd.LCDWrite(LCD::DATA, elementSet[1][3]);
//    lcd.LCDWrite(LCD::DATA, elementSet[1][4]);
//    lcd.LCDWrite(LCD::DATA, elementSet[1][5]);
//    return;

//    lcd.print("Fuck");
    for (size_t row = 0; row < 14; ++row) {
      for (size_t subrow = 0; subrow < 6; ++ subrow) {
        for (size_t j = 0; j < 6; ++j) {
          lcd.LCDWrite(LCD::DATA, elementSet[subrow][j]);
        }
      }
    }
  }
  
private:
  LCD &lcd;
  Fields fields = {};
};

Glass8x14 glass(lcd);

void setup()
{
  Serial.begin(9600);
  lcd.initialize(); // This will setup our pins, and initialize the LCD
  glass.draw();
}

void loop()
{
}

