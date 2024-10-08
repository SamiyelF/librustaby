/*!
 * \file create.hpp
 * \author Braden McDorman
 * \copyright KISS Institute for Practical Robotics
 * \defgroup create iRobot (R) Create (TM)
 */

#ifndef _KIPR_CREATE_CREATE_HPP_
#define _KIPR_CREATE_CREATE_HPP_

#include <cstdio>
#include <cstdlib>
#include <vector>

#ifndef WIN32
#include <pthread.h>
#include <sys/time.h>
#include <termios.h>
#else
#include <time.h>
#include <winsock2.h>
typedef unsigned int speed_t;
#endif

#include "../../kipr/button/button.hpp"
#include "../../kipr/export/export.h"
#include "../../kipr/sensor/sensor.hpp"

#define PI 3.14159f

namespace kipr {
namespace create {
/*!
 * \class CreateScript
 * \ingroup create
 */
class EXPORT_SYM CreateScript {
public:
  CreateScript();
  CreateScript(const CreateScript &rhs);

  void append(const unsigned char &byte);
  void append(const unsigned char *data, const size_t &size);
  void append(const CreateScript &script);

  void remove(const size_t &i, const size_t &len = 1);

  const unsigned char *data() const;
  size_t size() const;

  unsigned char byte(const size_t &i);

  CreateScript &operator=(const CreateScript &rhs);

private:
  std::vector<unsigned char> m_script;
};

/*!
 * Locally stored state information
 */
struct CreateState {
  timeval timestamp;

  int distance;
  int angle;
  short radius;
  short rightVelocity;
  short leftVelocity;
};

/*!
 * See the create open interface documentation for more information about these
 * structures
 */
namespace CreatePackets {
/*!
 * Create OI Packet 1
 */
struct _1 {
  unsigned char bumpsAndWheelDrops;
  unsigned char wall;
  unsigned char cliffLeft;
  unsigned char cliffFrontLeft;
  unsigned char cliffFrontRight;
  unsigned char cliffRight;
  unsigned char virtualWall;
  unsigned char cargoBayDigitalInputs;
  unsigned char lowSideDriverAndWheelOvercurrents;
};

/*!
 * Create OI Packet 2
 */
struct _2 {
  unsigned char ir;
  unsigned char buttons;
  unsigned char distance[2];
  unsigned char angle[2];
};

/*!
 * Create OI Packet 3
 */
struct _3 {
  unsigned char chargingState;
  unsigned char voltage[2];
  char current[2];
  char batteryTemperature;
  unsigned char batteryCharge[2];
  unsigned char batteryCapacity[2];
};

/*!
 * Create OI Packet 4
 */
struct _4 {
  unsigned char wallSignal[2];
  unsigned char cliffLeftSignal[2];
  unsigned char cliffFrontLeftSignal[2];
  unsigned char cliffFrontRightSignal[2];
  unsigned char cliffRightSignal[2];
  unsigned char userDigitalInputs;
  unsigned char userAnalogInput[2];
  unsigned char chargingSourcesAvailable;
};

/*!
 * Create OI Packet 5
 */
struct _5 {
  unsigned char mode;
  unsigned char songNumber;
  unsigned char songPlaying;
  unsigned char numberOfStreamPackets;
  char velocity[2];
  char radius[2];
  char rightVelocity[2];
  char leftVelocity[2];
};

/*!
 * Create OI Packet 101
 */
struct _101 {
  unsigned char leftEncoderCounts[2];  // 43
  unsigned char rightEncoderCounts[2]; // 44

  unsigned char lightBumpBits;                 // 45
  unsigned char lightBumpLeftSignal[2];        // 46
  unsigned char lightBumpFrontLeftSignal[2];   // 47
  unsigned char lightBumpCenterLeftSignal[2];  // 48
  unsigned char lightBumpCenterRightSignal[2]; // 49
  unsigned char lightBumpFrontRightSignal[2];  // 50
  unsigned char lightBumpRightSignal[2];       // 51

  char leftMotorCurrent[2];      // 54
  char rightMotorCurrent[2];     // 55
  char mainBrushMotorCurrent[2]; // 56
  char sideBrushMotorCurrent[2]; // 57
  char stasis;                   // 58
};
} // namespace CreatePackets

namespace sensors {
class PlayButton;
class AdvanceButton;
class Wall;
class CliffLeft;
class CliffFrontLeft;
class CliffFrontRight;
class CliffRight;
class VirtualWall;
class WallSignal;
class CliffLeftSignal;
class CliffFrontLeftSignal;
class CliffFrontRightSignal;
class CliffRightSignal;
class CargoBayAnalogSignal;
class CargoBayDigitalInputs;
class IR;
class ChargingState;
class BatteryTemperature;
class BatteryCharge;
class BatteryCapacity;
class Angle;
class Distance;
class BumpLeft;
class BumpRight;
class WheelDropRight;
class WheelDropLeft;
class WheelDropCaster;

class LightBumpLeft;
class LightBumpFrontLeft;
class LightBumpFrontRight;
class LightBumpRight;
class LightBumpCenterLeft;
class LightBumpCenterRight;

class LightBumpLeftSignal;
class LightBumpFrontLeftSignal;
class LightBumpFrontRightSignal;
class LightBumpRightSignal;
class LightBumpCenterLeftSignal;
class LightBumpCenterRightSignal;

class SongPlaying;
class SongNumber;
} // namespace sensors

/*!
 * \class Create
 * \brief Facilitates communication with the iRobot (R) Create (TM)
 * \details Provides high level bindings for a significant majority of the
 * iRobot Open Interface specification. \author Braden McDorman \ingroup create
 */
class EXPORT_SYM Create {
public:
  /*!
   * The "Mode" of the create.
   * - PassiveMode: No movement allowed.
   * - SafeMode: Movement is allowed, but the Create will stop if it's safety
   * sensors are activated.
   * - FullMode: All movement is allowed, even if it is considered dangerous.
   * This mode is recommended for Botball.
   */
  enum Mode { OffMode, PassiveMode, SafeMode, FullMode };

  ~Create();

  /*!
   * Attempts to establish a connection to the create
   * \return true if connection succeeded, false if connection failed
   * \see disconnect
   * \see isConnected
   */
  bool connect();

  enum BaudRate { Baud57600 = 0, Baud115200 = 1 };

  /*!
   * Attempts to establish a connection to the create
   * \param baudRate The desired communication speed with the Create 1 or 2
   * \return true if connection succeeded, false if connection failed
   * \see disconnect
   * \see isConnected
   */
  bool connect(const BaudRate baudRate);

  /*!
   * Cleans up connection to the create
   * \return true if disconnected, false otherwise
   * \see connect
   * \see isConnected
   */
  bool disconnect();

  /*!
   * \return true if connected, false if not connected
   * \see connect
   * \see disconnect
   */
  bool isConnected() const;

  void setOffMode();
  void setPassiveMode();
  void setSafeMode();
  void setFullMode();

  void setMode(const Create::Mode &mode);
  Create::Mode mode();

  void send(const CreateScript &script);

  bool write(const unsigned char &c);

#ifndef SWIG
  bool write(const unsigned char *data, const size_t &len);
#endif

  void flush();

  /*!
   * Reads one byte.
   * \return The read byte, or less than zero on error.
   */
  short read();

  /*!
   * Reads a maximum of len bytes.
   * \param data Pointer to the buffer to read into.
   * \param len Maxiumum number of bytes to read. Should be less than or equal
   * to the size of data. \return The number of bytes actually read, or less
   * than zero on error.
   */
  int read(unsigned char *data, const size_t &len);

  /*!
   * Reads until the specified number of bytes have been read.
   * \param data Pointer to the buffer to read into
   * \param size Number of bytes to be read
   * \return true if reading succeeded, false if there was an error
   * \blocks
   */
  bool blockingRead(unsigned char *data, const size_t &size,
                    unsigned timeout = 25);

  template <typename T>
  inline bool blockingRead(T &data, unsigned timeout = 0) {
    return blockingRead(reinterpret_cast<unsigned char *>(&data), sizeof(T),
                        timeout ? timeout : sizeof(T) * 7);
  }

  void setLeds(const bool &advance, const bool &play,
               const unsigned char &color, const unsigned char &brightness);

  void drive(const short &velocity, const short &radius);
  void driveDirect(const short &left, const short &right);
  void driveStraight(const short &speed);
  void stop();

  /*!
   * A very accurate turn method based on time rather than the create's own
   * readings, which are often less than accurate. \param angle The angle to
   * turn, in degrees. Positive is counter-clockwise. \param speed The speed
   * each wheel should move at, in mm/s. The angular velocity will be double
   * this value. \blocks
   */
  void turn(const short &angle, const unsigned short &speed);

  /*!
   * A very accurate move method based on time rather than the create's own
   * readings, which are often less than accurate. \param millimeters The amount
   * to move, in millimeters. \param speed The speed each wheel should move at,
   * in mm/s. \blocks
   */
  void move(const short &millimeters, const unsigned short &speed);

  /*!
   * Spin the create at a constant velocity.
   * \param speed The speed each motor should move at. Positive is
   * counter-clockwise.
   */
  void spin(const short &speed);

  /*!
   * Returns the current angular velocity of the create. This value is positive
   * for counter-clockwise velocity and negative for clockwise velocity. \return
   * angular velocity of the create, between 0 and 1000 mm/s
   */
  short angularVelocity() const;

  void spinClockwise(const short &speed);
  void spinCounterClockwise(const short &speed);

  bool setBaudRate(const unsigned char &baudCode);

  void setDistance(const int distance);
  void setAngle(const int angle);

  // High level sensors
  button::AbstractButton *playButton() const;
  button::AbstractButton *advanceButton() const;

  sensor::Sensor<bool> *wall() const;
  sensor::Sensor<bool> *cliffLeft() const;
  sensor::Sensor<bool> *cliffFrontLeft() const;
  sensor::Sensor<bool> *cliffFrontRight() const;
  sensor::Sensor<bool> *cliffRight() const;
  sensor::Sensor<bool> *virtualWall() const;

  sensor::Sensor<unsigned short> *wallSignal() const;
  sensor::Sensor<unsigned short> *cliffLeftSignal() const;
  sensor::Sensor<unsigned short> *cliffFrontLeftSignal() const;
  sensor::Sensor<unsigned short> *cliffFrontRightSignal() const;
  sensor::Sensor<unsigned short> *cliffRightSignal() const;
  sensor::Sensor<unsigned short> *cargoBayAnalogSignal() const;
  sensor::Sensor<unsigned char> *cargoBayDigitalInputs() const;

  sensor::Sensor<unsigned char> *ir() const;

  sensor::Sensor<unsigned char> *chargingState() const;
  sensor::Sensor<char> *batteryTemperature() const;
  sensor::Sensor<unsigned short> *batteryCharge() const;
  sensor::Sensor<unsigned short> *batteryCapacity() const;

  sensor::Sensor<int> *angle() const;
  sensor::Sensor<int> *distance() const;

  sensor::Sensor<bool> *bumpLeft() const;
  sensor::Sensor<bool> *bumpRight() const;

  sensor::Sensor<bool> *wheelDropLeft() const;
  sensor::Sensor<bool> *wheelDropRight() const;
  sensor::Sensor<bool> *wheelDropCaster() const;

  sensor::Sensor<bool> *lightBumpLeft() const;
  sensor::Sensor<bool> *lightBumpFrontLeft() const;
  sensor::Sensor<bool> *lightBumpCenterLeft() const;
  sensor::Sensor<bool> *lightBumpCenterRight() const;
  sensor::Sensor<bool> *lightBumpFrontRight() const;
  sensor::Sensor<bool> *lightBumpRight() const;

  sensor::Sensor<unsigned short> *lightBumpLeftSignal() const;
  sensor::Sensor<unsigned short> *lightBumpFrontLeftSignal() const;
  sensor::Sensor<unsigned short> *lightBumpCenterLeftSignal() const;
  sensor::Sensor<unsigned short> *lightBumpCenterRightSignal() const;
  sensor::Sensor<unsigned short> *lightBumpFrontRightSignal() const;
  sensor::Sensor<unsigned short> *lightBumpRightSignal() const;

  sensor::Sensor<unsigned char> *songPlaying() const;
  sensor::Sensor<unsigned char> *songNumber() const;

  void setRefreshRate(const unsigned short &refreshRate);
  const unsigned short &refreshRate() const;

  /*!
   * Loads a song for playing on the create
   * \param song It should be an array of unsigned chars (positive integers
   * 0-255) The first value in a pair will be the midi value of the note the
   * second value in the pair will be the duration (in 64ths of a second) for
   * example, a song {88, 20, 91, 32, 70, 15} will play midi value 88 for
   * 20/64ths of a second, midi value 91 for 32/64ths of a second, and midi
   * value 70 for 15/64ths of a second. A full list of notes playable on the
   * create is found at
   * https://cdn-shop.adafruit.com/datasheets/create_2_Open_Interface_Spec.pdf
   * on page 34 \param length The length of the song. It is how many notes are
   * in the song, not how many items are in your song array. \param num The song
   * slot to load the song into; valid values are 0, 1, 2, and 3 \return 1 on
   * success, 0 on failure \note Example use: `unsigned char example_song[] =
   * {88, 20, 91, 32, 70, 15}; create_load_song(example_song, 3, 0);` \ingroup
   * create
   */
  bool loadSong(const unsigned char *song, const unsigned char length,
                const unsigned char songNum);

  /*!
   * Plays a song that has been loaded. Use create_load_song first.
   * \param num The song slot to play from; valid values are 0, 1, 2, and 3
   * \return 1 on success, 0 on failure
   * \see create_load_song
   * \ingroup create
   */
  bool playSong(const unsigned char songNum);

  /*!
   * The Create class is a singleton, which means that you cannot instantiate it
   * directly. To get an instance of the create, you must use this method.
   * \return The global instance of the Create class
   */
  static Create *instance();

  const CreateState *state();
  const CreatePackets::_1 *sensorPacket1();
  const CreatePackets::_2 *sensorPacket2();
  const CreatePackets::_3 *sensorPacket3();
  const CreatePackets::_4 *sensorPacket4();
  const CreatePackets::_5 *sensorPacket5();
  const CreatePackets::_101 *sensorPacket101();

  inline void beginAtomicOperation() {
#ifndef WIN32
    pthread_mutex_lock(&m_mutex);
#endif
  }

  inline void endAtomicOperation() {
#ifndef WIN32
    pthread_mutex_unlock(&m_mutex);
#endif
  }

  inline void setDefaultBaudRate(const BaudRate defaultBaudRate) {
    m_defaultBaudRate = defaultBaudRate;
  }
  inline BaudRate defaultBaudRate() const { return m_defaultBaudRate; }

private:
  Create();
  Create(const Create &rhs);
  Create &operator=(const Create &rhs);

  void setLocalBaudRate(const speed_t &baudRate);

  bool start();

  bool open();
  void close();

  template <typename T> inline void lazyDelete(T *&ptr) {
    if (ptr)
      delete ptr;
  }

  inline timeval timeOfDay() const {
#ifdef _WIN32
    FILETIME ft;
    GetSystemTimeAsFileTime(&ft);
    unsigned long t =
        (ULONGLONG)ft.dwLowDateTime + ((ULONGLONG)(ft.dwHighDateTime) << 32);

    timeval tv;
    tv.tv_usec = t % 1000L;
    tv.tv_sec = (t - tv.tv_usec) / 1000L;
    return tv;
#else
    timeval ret;
    gettimeofday(&ret, NULL);
    return ret;
#endif
  }

  inline bool hasRequiredTimePassed(const timeval &timestamp) const {
#ifndef WIN32
    timeval current = timeOfDay();
    timeval result;
    timersub(&current, &timestamp, &result);
    const long msecs = result.tv_sec * 1000 + result.tv_usec / 1000;
    return msecs > m_refreshRate;
#else
    return false;
#endif
  }

  inline double timevalToFloat(const timeval &tv) {
    return ((double)tv.tv_sec) + ((double)tv.tv_usec / 1000000.0);
  }

  inline float deg2rad(const float &deg) { return deg / 180.0 * PI; }

  void updateState();

  void updateSensorPacket1();
  void updateSensorPacket2(bool forceUpdate = false);
  void updateSensorPacket3();
  void updateSensorPacket4();
  void updateSensorPacket5();
  void updateSensorPacket101();

  CreateState m_state;

  unsigned short m_refreshRate;

  CreatePackets::_1 m_1;
  CreatePackets::_2 m_2;
  CreatePackets::_3 m_3;
  CreatePackets::_4 m_4;
  CreatePackets::_5 m_5;
  CreatePackets::_101 m_101;
  timeval timestamps[6];
  bool have_packet[6];

  // These are all marked mutable because they
  // are initialized lazily in a const accessor.
  mutable sensors::PlayButton *m_playButton;
  mutable sensors::AdvanceButton *m_advanceButton;

  mutable sensors::Wall *m_wall;
  mutable sensors::CliffLeft *m_cliffLeft;
  mutable sensors::CliffFrontLeft *m_cliffFrontLeft;
  mutable sensors::CliffFrontRight *m_cliffFrontRight;
  mutable sensors::CliffRight *m_cliffRight;
  mutable sensors::VirtualWall *m_virtualWall;

  mutable sensors::WallSignal *m_wallSignal;
  mutable sensors::CliffLeftSignal *m_cliffLeftSignal;
  mutable sensors::CliffFrontLeftSignal *m_cliffFrontLeftSignal;
  mutable sensors::CliffFrontRightSignal *m_cliffFrontRightSignal;
  mutable sensors::CliffRightSignal *m_cliffRightSignal;
  mutable sensors::CargoBayAnalogSignal *m_cargoBayAnalogSignal;
  mutable sensors::CargoBayDigitalInputs *m_cargoBayDigitalInputs;

  mutable sensors::LightBumpLeft *m_lightBumpLeft;
  mutable sensors::LightBumpFrontLeft *m_lightBumpFrontLeft;
  mutable sensors::LightBumpCenterLeft *m_lightBumpCenterLeft;
  mutable sensors::LightBumpCenterRight *m_lightBumpCenterRight;
  mutable sensors::LightBumpFrontRight *m_lightBumpFrontRight;
  mutable sensors::LightBumpRight *m_lightBumpRight;

  mutable sensors::LightBumpLeftSignal *m_lightBumpLeftSignal;
  mutable sensors::LightBumpFrontLeftSignal *m_lightBumpFrontLeftSignal;
  mutable sensors::LightBumpCenterLeftSignal *m_lightBumpCenterLeftSignal;
  mutable sensors::LightBumpCenterRightSignal *m_lightBumpCenterRightSignal;
  mutable sensors::LightBumpFrontRightSignal *m_lightBumpFrontRightSignal;
  mutable sensors::LightBumpRightSignal *m_lightBumpRightSignal;

  mutable sensors::IR *m_ir;

  mutable sensors::ChargingState *m_chargingState;
  mutable sensors::BatteryTemperature *m_batteryTemperature;
  mutable sensors::BatteryCharge *m_batteryCharge;
  mutable sensors::BatteryCapacity *m_batteryCapacity;

  mutable sensors::Angle *m_angle;
  mutable sensors::Distance *m_distance;

  mutable sensors::BumpLeft *m_bumpLeft;
  mutable sensors::BumpRight *m_bumpRight;

  mutable sensors::WheelDropLeft *m_wheelDropLeft;
  mutable sensors::WheelDropRight *m_wheelDropRight;
  mutable sensors::WheelDropCaster *m_wheelDropCaster;

  mutable sensors::SongPlaying *m_songPlaying;
  mutable sensors::SongNumber *m_songNumber;

  size_t m_i;
  CreateScript m_script;
  int m_tty;
#ifndef WIN32
  pthread_mutex_t m_mutex;
#endif

  BaudRate m_defaultBaudRate;
};
} // namespace create
} // namespace kipr

#endif /* INCLUDE_WALLABY_CREATE_HPP_ */
