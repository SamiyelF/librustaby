#ifndef _KIPR_ANALOG_ANALOG_HPP_
#define _KIPR_ANALOG_ANALOG_HPP_

#include "../../kipr/sensor/sensor.hpp"

namespace kipr {
namespace analog {
class Analog : public sensor::Sensor<unsigned short> {
public:
  Analog(unsigned char port);
  virtual ~Analog();

  virtual unsigned short value() const;

  virtual void setPullup(bool pullup);
  bool pullup() const;

  unsigned char port() const;

private:
  unsigned char m_port;
};

class Analog8 : public Analog {
public:
  Analog8(unsigned char port);
  virtual ~Analog8();

  unsigned short value() const;
};

class Analog10 : public Analog {
public:
  Analog10(unsigned char port);
  virtual ~Analog10();

  virtual unsigned short value() const;
};
} // namespace analog
} // namespace kipr

#endif
