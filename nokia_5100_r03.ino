#include <SPI.h>


/* 84x48 LCD Defines: */
#define WHITE       0  // For drawing pixels. A 0 draws white.
#define BLACK       1  // A 1 draws black.

class NokiaLCDChar {
  public:
    constexpr static size_t dataCount = 5;

  public:
    NokiaLCDChar()
      : data_()
    {
    }
    
    NokiaLCDChar(byte b0, byte b1, byte b2, byte b3, byte b4)
    {
      data_[0] = b0;
      data_[1] = b1;
      data_[2] = b2;
      data_[3] = b3;
      data_[4] = b4;
    }

    NokiaLCDChar(const NokiaLCDChar &) = default;

    byte operator[](size_t index) const {
      return data_[index];
    }

    static NokiaLCDChar generate(char c) {
      switch (c) {
        case ' ': return {0x00, 0x00, 0x00, 0x00, 0x00};
        case '!': return {0x00, 0x00, 0x5f, 0x00, 0x00};
        case '"': return {0x00, 0x07, 0x00, 0x07, 0x00};
        case '#': return {0x14, 0x7f, 0x14, 0x7f, 0x14};
        case '$': return {0x24, 0x2a, 0x7f, 0x2a, 0x12};
        case '%': return {0x23, 0x13, 0x08, 0x64, 0x62};
        case '&': return {0x36, 0x49, 0x55, 0x22, 0x50};
        case '\'': return {0x00, 0x05, 0x03, 0x00, 0x00};
        case '(': return {0x00, 0x1c, 0x22, 0x41, 0x00};
        case ')': return {0x00, 0x41, 0x22, 0x1c, 0x00};
        case '*': return {0x14, 0x08, 0x3e, 0x08, 0x14};
        case '+': return {0x08, 0x08, 0x3e, 0x08, 0x08};
        case ',': return {0x00, 0x50, 0x30, 0x00, 0x00};
        case '-': return {0x08, 0x08, 0x08, 0x08, 0x08};
        case '.': return {0x00, 0x60, 0x60, 0x00, 0x00};
        case '/': return {0x20, 0x10, 0x08, 0x04, 0x02};
        case '0': return {0x3e, 0x51, 0x49, 0x45, 0x3e};
        case '1': return {0x00, 0x42, 0x7f, 0x40, 0x00};
        case '2': return {0x42, 0x61, 0x51, 0x49, 0x46};
        case '3': return {0x21, 0x41, 0x45, 0x4b, 0x31};
        case '4': return {0x18, 0x14, 0x12, 0x7f, 0x10};
        case '5': return {0x27, 0x45, 0x45, 0x45, 0x39};
        case '6': return {0x3c, 0x4a, 0x49, 0x49, 0x30};
        case '7': return {0x01, 0x71, 0x09, 0x05, 0x03};
        case '8': return {0x36, 0x49, 0x49, 0x49, 0x36};
        case '9': return {0x06, 0x49, 0x49, 0x29, 0x1e};
        case ':': return {0x00, 0x36, 0x36, 0x00, 0x00};
        case ';': return {0x00, 0x56, 0x36, 0x00, 0x00};
        case '<': return {0x08, 0x14, 0x22, 0x41, 0x00};
        case '=': return {0x14, 0x14, 0x14, 0x14, 0x14};
        case '>': return {0x00, 0x41, 0x22, 0x14, 0x08};
        case '?': return {0x02, 0x01, 0x51, 0x09, 0x06};
        case '@': return {0x32, 0x49, 0x79, 0x41, 0x3e};
        case 'A': return {0x7e, 0x11, 0x11, 0x11, 0x7e};
        case 'B': return {0x7f, 0x49, 0x49, 0x49, 0x36};
        case 'C': return {0x3e, 0x41, 0x41, 0x41, 0x22};
        case 'D': return {0x7f, 0x41, 0x41, 0x22, 0x1c};
        case 'E': return {0x7f, 0x49, 0x49, 0x49, 0x41};
        case 'F': return {0x7f, 0x09, 0x09, 0x09, 0x01};
        case 'G': return {0x3e, 0x41, 0x49, 0x49, 0x7a};
        case 'H': return {0x7f, 0x08, 0x08, 0x08, 0x7f};
        case 'I': return {0x00, 0x41, 0x7f, 0x41, 0x00};
        case 'J': return {0x20, 0x40, 0x41, 0x3f, 0x01};
        case 'K': return {0x7f, 0x08, 0x14, 0x22, 0x41};
        case 'L': return {0x7f, 0x40, 0x40, 0x40, 0x40};
        case 'M': return {0x7f, 0x02, 0x0c, 0x02, 0x7f};
        case 'N': return {0x7f, 0x04, 0x08, 0x10, 0x7f};
        case 'O': return {0x3e, 0x41, 0x41, 0x41, 0x3e};
        case 'P': return {0x7f, 0x09, 0x09, 0x09, 0x06};
        case 'Q': return {0x3e, 0x41, 0x51, 0x21, 0x5e};
        case 'R': return {0x7f, 0x09, 0x19, 0x29, 0x46};
        case 'S': return {0x46, 0x49, 0x49, 0x49, 0x31};
        case 'T': return {0x01, 0x01, 0x7f, 0x01, 0x01};
        case 'U': return {0x3f, 0x40, 0x40, 0x40, 0x3f};
        case 'V': return {0x1f, 0x20, 0x40, 0x20, 0x1f};
        case 'W': return {0x3f, 0x40, 0x38, 0x40, 0x3f};
        case 'X': return {0x63, 0x14, 0x08, 0x14, 0x63};
        case 'Y': return {0x07, 0x08, 0x70, 0x08, 0x07};
        case 'Z': return {0x61, 0x51, 0x49, 0x45, 0x43};
        case '[': return {0x00, 0x7f, 0x41, 0x41, 0x00};
        case '\\': return {0x02, 0x04, 0x08, 0x10, 0x20};
        case ']': return {0x00, 0x41, 0x41, 0x7f, 0x00};
        case '^': return {0x04, 0x02, 0x01, 0x02, 0x04};
        case '_': return {0x40, 0x40, 0x40, 0x40, 0x40};
        case '`': return {0x00, 0x01, 0x02, 0x04, 0x00};
        case 'a': return {0x20, 0x54, 0x54, 0x54, 0x78};
        case 'b': return {0x7f, 0x48, 0x44, 0x44, 0x38};
        case 'c': return {0x38, 0x44, 0x44, 0x44, 0x20};
        case 'd': return {0x38, 0x44, 0x44, 0x48, 0x7f};
        case 'e': return {0x38, 0x54, 0x54, 0x54, 0x18};
        case 'f': return {0x08, 0x7e, 0x09, 0x01, 0x02};
        case 'g': return {0x0c, 0x52, 0x52, 0x52, 0x3e};
        case 'h': return {0x7f, 0x08, 0x04, 0x04, 0x78};
        case 'i': return {0x00, 0x44, 0x7d, 0x40, 0x00};
        case 'j': return {0x20, 0x40, 0x44, 0x3d, 0x00};
        case 'k': return {0x7f, 0x10, 0x28, 0x44, 0x00};
        case 'l': return {0x00, 0x41, 0x7f, 0x40, 0x00};
        case 'm': return {0x7c, 0x04, 0x18, 0x04, 0x78};
        case 'n': return {0x7c, 0x08, 0x04, 0x04, 0x78};
        case 'o': return {0x38, 0x44, 0x44, 0x44, 0x38};
        case 'p': return {0x7c, 0x14, 0x14, 0x14, 0x08};
        case 'q': return {0x08, 0x14, 0x14, 0x18, 0x7c};
        case 'r': return {0x7c, 0x08, 0x04, 0x04, 0x08};
        case 's': return {0x48, 0x54, 0x54, 0x54, 0x20};
        case 't': return {0x04, 0x3f, 0x44, 0x40, 0x20};
        case 'u': return {0x3c, 0x40, 0x40, 0x20, 0x7c};
        case 'v': return {0x1c, 0x20, 0x40, 0x20, 0x1c};
        case 'w': return {0x3c, 0x40, 0x30, 0x40, 0x3c};
        case 'x': return {0x44, 0x28, 0x10, 0x28, 0x44};
        case 'y': return {0x0c, 0x50, 0x50, 0x50, 0x3c};
        case 'z': return {0x44, 0x64, 0x54, 0x4c, 0x44};
        case '{': return {0x00, 0x08, 0x36, 0x41, 0x00};
        case '|': return {0x00, 0x00, 0x7f, 0x00, 0x00};
        case '}': return {0x00, 0x41, 0x36, 0x08, 0x00};
        case '~': return {0x10, 0x08, 0x08, 0x10, 0x08};
        case 0x7f: return {0x78, 0x46, 0x41, 0x46, 0x78}; //DEL
    }
    return {};
  }
    
  private:
    byte data_[dataCount];
};

class NokiaLCD {
  public:
    enum Mode {
      COMMAND = 0,
      DATA = 1
    };

  public:
    NokiaLCD (
      char chipEnablePin,    // SCE - Chip select
      char resetPin,         // RST - Reset
      char dataCommandPin,   // DC - Data/Command
      char dataInPin,        // DN(MOSI) - Serial data
      char clockPin,         // SCLK - Serial clock
      char backlightPin = -1 // LED - Backlight LED
    )
      : chipEnablePin(chipEnablePin)
      , resetPin(resetPin)
      , dataCommandPin(dataCommandPin)
      , dataInPin(dataInPin)
      , clockPin(clockPin)
      , backlightPin(backlightPin)
    {
    }

      //This sends the magical commands to the PCD8544
    void initialize()
    {
      //Configure control pins
      pinMode(chipEnablePin, OUTPUT);
      pinMode(resetPin, OUTPUT);
      pinMode(dataCommandPin, OUTPUT);
      pinMode(dataInPin, OUTPUT);
      pinMode(clockPin, OUTPUT);
      if (backlightPin >= 0) {
        pinMode(backlightPin, OUTPUT);
        analogWrite(backlightPin, 255);
      }
    
      SPI.begin();
      SPI.setDataMode(SPI_MODE0);
      SPI.setBitOrder(MSBFIRST);
      
      //Reset the LCD to a known state
      digitalWrite(resetPin, LOW);
      digitalWrite(resetPin, HIGH);
    
      LCDWrite(COMMAND, 0x21); //Tell LCD extended commands follow
      LCDWrite(COMMAND, 0xB0); //Set LCD Vop (Contrast)
      LCDWrite(COMMAND, 0x04); //Set Temp coefficent
      LCDWrite(COMMAND, 0x14); //LCD bias mode 1:48 (try 0x13)
      //We must send 0x20 before modifying the display control mode
      LCDWrite(COMMAND, 0x20); 
      LCDWrite(COMMAND, 0x0C); //Set display control, normal mode.
      clear();
    }

    // There are two memory banks in the LCD, data/RAM and commands.
    // This function sets the DC pin high or low depending, and then 
    // sends the data byte
    void LCDWrite(byte data_or_command, byte data) 
    {
      //Tell the LCD that we are writing either to data or a command
      digitalWrite(dataCommandPin, data_or_command); 
    
      //Send the data
      digitalWrite(chipEnablePin, LOW);
      SPI.transfer(data); //shiftOut(sdinPin, sclkPin, MSBFIRST, data);
      digitalWrite(chipEnablePin, HIGH);
    }

    // Set contrast can set the LCD Vop to a value between 0 and 127.
    // 40-60 is usually a pretty good range.
    void setContrast(byte contrast)
    {
      LCDWrite(NokiaLCD::COMMAND, 0x21); //Tell LCD that extended commands follow
      LCDWrite(NokiaLCD::COMMAND, 0x80 | contrast); //Set LCD Vop (Contrast): Try 0xB1(good @ 3.3V) or 0xBF if your display is too dark
      LCDWrite(NokiaLCD::COMMAND, 0x20); //Set display mode
    }

    // Because I keep forgetting to put bw variable in when setting...
    void setPixel(int x, int y)
    {
      setPixel(x, y, BLACK); // Call setPixel with bw set to Black
    }
    
    void clearPixel(int x, int y)
    {
      setPixel(x, y, WHITE); // call setPixel with bw set to white
    }
    
    // This function sets a pixel on displayMap to your preferred
    // color. 1=Black, 0= white.
    void setPixel(int x, int y, boolean bw)
    {
      // First, double check that the coordinate is in range.
      if (x >= 0 && x < NokiaLCD::width_ && y >= 0 && y < NokiaLCD::height_)
      {
        byte shift = y % 8;
      
        if (bw) // If black, set the bit.
          displayMap[x + (y/8)*NokiaLCD::width_] |= 1<<shift;
        else   // If white clear the bit.
          displayMap[x + (y/8)*NokiaLCD::width_] &= ~(1<<shift);
      }
    }
    
    // This function will draw a char (defined in the ASCII table
    // near the beginning of this sketch) at a defined x and y).
    // The color can be either black (1) or white (0).
    void setChar(char character, int x, int y, boolean bw)
    {
      const NokiaLCDChar &symbol = NokiaLCDChar::generate(character);
      for (int i=0; i<5; i++) // 5 columns (x) per character
      {
        const byte column = symbol[i];
        for (int j=0; j<8; j++) // 8 rows (y) per character
        {
          if (column & (0x01 << j)) // test bits to set pixels
            setPixel(x+i, y+j, bw);
          else
            setPixel(x+i, y+j, !bw);
        }
      }
    }
    
    // This function clears the entire display either white (0) or
    // black (1).
    // The screen won't actually clear until you call updateDisplay()!
    void clearDisplay(boolean bw)
    {
      for (int i=0; i < NokiaLCD::blockCount_; i++)
      {
        if (bw)
          displayMap[i] = 0xFF;
        else
          displayMap[i] = 0;
      }
    }

    void clear() {
      gotoXY(0, 0);
      for (size_t i = 0; i < blockCount_; i++)
      {
        LCDWrite(DATA, 0);
      }
    }
    
    // Helpful function to directly command the LCD to go to a 
    // specific x,y coordinate.
    void gotoXY(int x, int y)
    {
      LCDWrite(0, 0x80 | x);  // Column.
      LCDWrite(0, 0x40 | y);  // Row.  ?
    }
    
    // This will actually draw on the display, whatever is currently
    // in the displayMap array.
    void updateDisplay()
    {
      gotoXY(0, 0);
      for (int i=0; i < NokiaLCD::blockCount_; i++)
      {
        LCDWrite(NokiaLCD::DATA, displayMap[i]);
      }
    }
    
    /* There are two ways to do this. Either through direct commands
    to the display, or by swapping each bit in the displayMap array.
    We'll leave both methods here, comment one or the other out if 
    you please. */
    void invertDisplay()
    {
      /* Direct LCD Command option
      LCDWrite(LCD_COMMAND, 0x20); //Tell LCD that extended commands follow
      LCDWrite(LCD_COMMAND, 0x08 | 0x05); //Set LCD Vop (Contrast): Try 0xB1(good @ 3.3V) or 0xBF if your display is too dark
      LCDWrite(LCD_COMMAND, 0x20); //Set display mode  */
      
      /* Indirect, swap bits in displayMap option: */
      for (int i=0; i < NokiaLCD::blockCount_; i++)
      {
        displayMap[i] = ~displayMap[i] & 0xFF;
      }
      updateDisplay();
    }

  public:
    constexpr static size_t width_ = 84;
    constexpr static size_t height_ = 48;
    constexpr static size_t pixelsCount_ = width_ * height_;
    constexpr static size_t blockCount_ = pixelsCount_ / 8;

  private:
    const char chipEnablePin;
    const char resetPin;
    const char dataCommandPin;
    const char dataInPin;
    const char clockPin;
    const char backlightPin;

    /* The displayMap variable stores a buffer representation of the
    pixels on our display. There are 504 total bits in this array,
    same as how many pixels there are on a 84 x 48 display.
    
    Each byte in this array covers a 8-pixel vertical block on the 
    display. Each successive byte covers the next 8-pixel column over
    until you reach the right-edge of the display and step down 8 rows.
    
    To update the display, we first have to write to this array, then
    call the updateDisplay() function, which sends this whole array
    to the PCD8544.
    
    Because the PCD8544 won't let us write individual pixels at a 
    time, this is how we can make targeted changes to the display. */
    byte displayMap[blockCount_] = {};
};

NokiaLCD lcd(7, 6, 5, 11, 13);

void setup()
{
  Serial.begin(9600);

  lcd.initialize(); // This will setup our pins, and initialize the LCD
  lcd.setContrast(40); // Good values range from 40-60
}

// Loop turns the display into a local serial monitor echo.
// Type to the Arduino from the serial monitor, and it'll echo
// what you type on the display. Type ~ to clear the display.
void loop()
{
  static int cursorX = 0;
  static int cursorY = 0;
  
  if (Serial.available())
  {
    char c = Serial.read();
    
    switch (c)
    {
    case '\n': // New line
      cursorY += 8;
      break;
    case '\r': // Return feed
      cursorX = 0;
      break;
    case '~': // Use ~ to clear the screen.
      lcd.clearDisplay(WHITE);
      lcd.updateDisplay();
      cursorX = 0; // reset the cursor
      cursorY = 0;
      break;
    default:
      lcd.setChar(c, cursorX, cursorY, BLACK);
      lcd.updateDisplay();
      cursorX += 6; // Increment cursor
      break;
    }
    // Manage cursor
    if (cursorX >= (NokiaLCD::width_ - 4)) 
    { // If the next char will be off screen...
      cursorX = 0; // ... reset x to 0...
      cursorY += 8; // ...and increment to next line.
      if (cursorY >= (NokiaLCD::height_ - 7))
      { // If the next line takes us off screen...
        cursorY = 0; // ...go back to the top.
      }
    }
  }
}

