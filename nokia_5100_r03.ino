#include <SPI.h>

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
  private:
    enum InstructionSet {
      BasicInstructionSet = 0,
      ExtendedInstructionSet = 1
    };

    enum PowerDownMode {
      PowerUp = 0,
      PowerDown = 1
    };

    enum TemperatureCoef {
      TemperatureCoef0 = 0b00,
      TemperatureCoef1 = 0b01,
      TemperatureCoef2 = 0b10,
      TemperatureCoef3 = 0b11      
    };

  public:
    enum Mode {
      COMMAND = 0,
      DATA = 1
    };

    enum AddressingMode {
      HorizontalAddressing = 0,
      VerticalAddressing = 1
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
      , powerDown_(true)
      , verticalAddressing_(false)
      , extendedInstructionSet_(false)
      , x_(0)
      , y_(0)
      , vop_(0)
      , temperatureCoef_(TemperatureCoef0)
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

      reset();

      powerUp();

      setVOp(48);
      setTemperatureCoef(TemperatureCoef0);
      LCDWrite(COMMAND, 0x14); //LCD bias mode 1:48 (try 0x13)

      use(BasicInstructionSet);
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
      setVOp(contrast);
      use(BasicInstructionSet);
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
    void gotoXY(byte x, byte y)
    {
      if (x != x_) {
        x_ = x;
        writeXPos();
      }
      if (y != y_) {
        y_ = y;
        writeYPos();
      }
    }
    
    void print(char c) {
      if (c == '\n') {
        goToNewLine();
        return;
      }
      
      const NokiaLCDChar &symbol = NokiaLCDChar::generate(c);
      for (size_t i = 0; i < 5; ++i) {
        LCDWrite(DATA, symbol[i]);
      }
      LCDWrite(DATA, 0);
      shiftPos(6);
    }

    void print(const char *text) {
      while (*text) {
        print(*text);
        ++text;
      }
    }

  InstructionSet instructionSet() const {
    return static_cast<InstructionSet>(extendedInstructionSet_);
  }

  AddressingMode addressingMode() const {
    return static_cast<AddressingMode>(verticalAddressing_);
  }

  void use(AddressingMode mode) {
    if (mode == addressingMode()) {
      return;
    }

    verticalAddressing_ = !verticalAddressing_;
    writeFunctionSet();
  }

  void setVOp(byte value) {
    if (vop_ == value) {
      return;
    }
    
    use(ExtendedInstructionSet);
    constexpr byte commandMask = 0b10000000;
    LCDWrite(COMMAND, commandMask | value);
    vop_ = value;
  }

  void setTemperatureCoef(TemperatureCoef value) {
    if (temperatureCoef_ == value) {
      return;
    }

    use(ExtendedInstructionSet);
    constexpr byte commandMask = 0b00000100;
    LCDWrite(COMMAND, commandMask | value);
    temperatureCoef_ = value;
  }

  NokiaLCD &operator<<(char c) {
    print(c);
    return *this;
  }
  
  NokiaLCD &operator<<(const char *text) {
    print(text);
    return *this;
  }
  
  private:
    void reset() {
      // resets chip to known state
      digitalWrite(resetPin, LOW);
      // need delay min. 100 ns
      // for 8MHz delay is not needed
      digitalWrite(resetPin, HIGH);
    }
    
    void powerUp() {
      powerDown_ = false;      
      writeFunctionSet();
    }
    
    void use(InstructionSet set) {
      if (set == instructionSet()) {
        return;
      }

      extendedInstructionSet_ = !extendedInstructionSet_;      
      writeFunctionSet();
    }

    void writeFunctionSet() {
      constexpr byte command = 0b00100000;
      LCDWrite(COMMAND, command | 
                        (powerDown_ << 2) |
                        (verticalAddressing_ << 1) |
                        extendedInstructionSet_);
    }

    size_t pos() const {
      return verticalAddressing_ ?
              x_ * height_ + y_ :
              y_ * width_ + x_;
    }

    void shiftPos(size_t count) {
      const size_t newPos = (count + pos()) % blockCount_;
      if (verticalAddressing_) {
        x_ = newPos / height_;
        y_ = newPos % height_;
      }
      else {
        x_ = newPos % width_;
        y_ = newPos / width_;
      }
    }

    void goToNewLine() {
      if (x_ != 0) {
        x_ = 0;
        writeXPos();
      }
      
      ++y_;
      if (y_ == height_) {
        y_ = 0;
      }
      writeYPos();
    }

    void writeXPos() {
      LCDWrite(0, 0x80 | x_);
    }

    void writeYPos() {
      LCDWrite(0, 0x40 | y_);      
    }

  public:
    constexpr static size_t width_ = 84;
    constexpr static size_t height_ = 6;
    constexpr static size_t blockCount_ = width_ * height_;

  private:
    const char chipEnablePin;
    const char resetPin;
    const char dataCommandPin;
    const char dataInPin;
    const char clockPin;
    const char backlightPin;
    bool powerDown_: 1;
    bool verticalAddressing_: 1;
    bool extendedInstructionSet_: 1;
    byte x_: 7;
    byte y_: 3;
    byte vop_: 7;
    TemperatureCoef temperatureCoef_: 2;
};

NokiaLCD lcd(7, 6, 5, 11, 13);

void setup()
{
  Serial.begin(9600);

  lcd.initialize(); // This will setup our pins, and initialize the LCD
  lcd.setContrast(40); // Good values range from 40-60

  lcd << "Send message\nto serial\n";
}

void loop()
{
  if (!Serial.available())
  {
    return;
  }

  const char c = Serial.read();
  Serial.println(c, HEX);  
  
  lcd << c;
}

