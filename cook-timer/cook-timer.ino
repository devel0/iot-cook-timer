#define SERIAL_DEBUG
#define SERIAL_SPEED 57600
#define TR_PIN 5
#define MIN_PIN 6
#define SEC_PIN 8
#define START_PIN 7
#define BUZ_PIN 9
#define AUTOPOWEROFF_TIMEOUT_SEC 10

// set to 0 in release
#define TEST_BUZ 0

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h>

// EDIT DebugMacros to set SERIAL_SPEED and enable/disable DPRINT_SERIAL
#include <DPrint.h>
#include <Util.h>
using namespace SearchAThing::Arduino;

#ifndef SSD1306_128_64
#error "set display on Adafruit_SSD1306.h"
#endif

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void TR_HIGH()
{
  DPrintStrln("TR HIGH");
  digitalWrite(TR_PIN, HIGH);
}

void TR_LOW()
{
  DPrintStrln("TR LOW");
  digitalWrite(TR_PIN, LOW);
}

void shutdown()
{
  TR_LOW();
}

void beep()
{
  tone(BUZ_PIN, 1500, 5);
}

void beep2()
{
  tone(BUZ_PIN, 2000, 50);
}

void drawTime(int mm, int ss, int progress)
{
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(4, 13);
  display.print("Min.");

  if (mm > 0)
  {
    display.setTextSize(3);
    display.setCursor(4, 56);
    if (mm < 10)
    {
      display.setTextColor(BLACK);
      display.print('0');
      display.setTextColor(WHITE);
    }
    display.print(mm);
  }

  display.setTextSize(1);
  display.setCursor(4, 80);
  display.print("Sec.");

  if (ss > 0)
  {
    display.setTextSize(2);
    display.setCursor(24, 111);
    if (ss < 10)
    {
      display.setTextColor(BLACK);
      display.print('0');
      display.setTextColor(WHITE);
    }
    display.print(ss);
  }

  display.fillRect(0, 120, 63 * progress / 100, 127, WHITE);
  display.drawLine(0, 120, 63, 120, WHITE);
  display.drawLine(0, 127, 63, 127, WHITE);
  display.drawLine(63, 120, 63, 127, WHITE);
  display.display();
}

/*-----------*/
/* VARIABLES */
/*-----------*/

int mm = 0;
int ss = 0;
int progress = 100;

#define STATE_IDLE 0
#define STATE_STARTED 1
#define STATE_TIMEOUT 2

#define TIMEOUT_BEEP_SEC 15

int state = STATE_IDLE;
long int start_time = 0;
long int timeout_start_time = 0;
long int last_activity_time = 0;

/*-----------*/
/* SETUP     */
/*-----------*/

void setup()
{
  pinMode(TR_PIN, OUTPUT);
  TR_HIGH();

  pinMode(MIN_PIN, INPUT_PULLUP);
  pinMode(SEC_PIN, INPUT_PULLUP);
  pinMode(START_PIN, INPUT_PULLUP);

  pinMode(BUZ_PIN, OUTPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  //display.begin(SSD1306_EXTERNALVCC, 0x3C);

  display.setRotation(3);

  display.setTextColor(WHITE);
  display.setFont(&FreeSans9pt7b);

  DPrintStr("display width = ");
  DPrintInt16ln(display.width());
  DPrintStr("display height = ");
  DPrintInt16ln(display.height());
  last_activity_time = millis();
}

/*-----------*/
/* LOOP      */
/*-----------*/

// return false if expired
bool drawElapsed()
{
  int totsec = 60 * mm + ss;
  int totsec_elapsed = TimeDiff(start_time, millis()) / 1000;
  int totsec_diff = totsec - totsec_elapsed;
  if (totsec_elapsed < totsec)
  {
    int mm_diff = totsec_diff / 60;
    int ss_diff = totsec_diff - (60 * mm_diff);

    drawTime(mm_diff, ss_diff, 100 - totsec_elapsed * 100 / totsec);

    return true;
  }
  else
    return false;
}

int tone_test = 440;

int min_press_cnt = 0;
unsigned long min_press_accepted_timestamp; // uninitialized until min_press_cnt==0

void loop()
{
  bool min_pressed = digitalRead(MIN_PIN) == LOW;
  bool sec_pressed = digitalRead(SEC_PIN) == LOW;
  bool start_pressed = digitalRead(START_PIN) == LOW;

  if (!min_pressed)
    min_press_cnt = 0;

  if (state == STATE_IDLE && (TimeDiff(last_activity_time, millis()) / 1000 > AUTOPOWEROFF_TIMEOUT_SEC))
  {
    beep();
    shutdown();
  }

  if (min_pressed || sec_pressed || start_pressed)
  {
    last_activity_time = millis();
    if (min_pressed)
      DPrintStrln("min pressed");
    if (sec_pressed)
      DPrintStrln("sec pressed");
    if (start_pressed)
      DPrintStrln("start pressed");
  }

  if (TEST_BUZ == 1)
  {
    if (min_pressed)
    {
      tone_test += 10;
    }
    else if (sec_pressed)
    {
      tone_test -= 10;
    }

    for (int i = 0; i < 4; ++i)
    {
      tone(BUZ_PIN, tone_test, 50);
      delay(150);
    }
    delay(500);

    display.clearDisplay();

    display.setTextSize(1);
    display.setCursor(4, 13);
    display.print(tone_test);

    display.display();

    return;
  }

  if (
      (min_pressed && sec_pressed) ||
      (min_pressed && start_pressed) ||
      (start_pressed && sec_pressed) ||
      (state == STATE_TIMEOUT && (min_pressed || sec_pressed || start_pressed)))
  {
    mm = ss = 0;
    progress = 100;
    drawTime(mm, ss, progress);
    state = STATE_IDLE;
    beep2();
    delay(500);
  }
  else if (min_pressed)
  {
    if (
        min_press_cnt == 0 ||
        (min_press_cnt == 1 && TimeDiff(min_press_accepted_timestamp, millis()) > 2500) ||
        (min_press_cnt > 1 && TimeDiff(min_press_accepted_timestamp, millis()) > 50))
    {
      min_press_accepted_timestamp = millis();
      ++min_press_cnt;
      beep();
      ++mm;
      if (mm > 60)
        mm = 0;
    }
  }
  else if (sec_pressed)
  {
    beep();
    ++ss;
    if (ss > 60)
      ss = 0;
  }
  else if (start_pressed)
  {
    beep2();
    if (state == STATE_STARTED)
    {
      state = STATE_IDLE;
      delay(500);
    }
    else
    {
      start_time = millis();
      state = STATE_STARTED;
    }
    delay(500);
  }

  if (state == STATE_STARTED)
  {
    if (!drawElapsed())
    {
      state = STATE_TIMEOUT;
      last_activity_time = timeout_start_time = millis();
      drawTime(mm, ss, progress);
    }
  }
  else
    drawTime(mm, ss, progress);

  if (state == STATE_TIMEOUT)
  {
    if (TimeDiff(timeout_start_time, millis()) < TIMEOUT_BEEP_SEC * 1000)
    {
      for (int i = 0; i < 4; ++i)
      {
        tone(BUZ_PIN, 1000, 40);
        delay(100);
      }
      delay(500);
    }
    else
    {
      state = STATE_IDLE;
    }
  }
}
