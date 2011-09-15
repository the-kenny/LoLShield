/*
 LoLShield Binary Clock
 
 Author: Moritz Ulrich <ulrich.moritz@googlemail.com>
 
 It would be nice if someone would adapt this code to a RTC chip
 like the ChronoDot.
 
 
 Writen for the LoL Shield, designed by Jimmie Rodgers:
 http://jimmieprodgers.com/kits/lolshield/
 
 This needs the Charliplexing library, which you can get at the
 LoL Shield project page: http://code.google.com/p/lolshield/
 
 License:
 This is free software; you can redistribute it and/or
 modify it under the terms of the GNU Version 3 General Public
 License as published by the Free Software Foundation; 
 or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 
 */

#include <Charliplexing.h>

void setup() {
  LedSign::Init();
}

void drawLine(uint8_t x, uint8_t val) {
  LedSign::Set(x, 6, val&B0001);
  LedSign::Set(x, 5, val&B0010);
  LedSign::Set(x, 4, val&B0100);
  LedSign::Set(x, 3, val&B1000);
}

long last = 0;
void loop() {
  const long ms = millis();
  const long now = ms/1000;

  if(ms-last >= 1000) {
    uint8_t hours   = (now/3600) % 24;
    uint8_t minutes = (now/60)   % 60;
    uint8_t seconds = now        % 60;

    drawLine(3, hours/10);
    drawLine(4, hours%10);

    drawLine(6, minutes/10);
    drawLine(7, minutes%10);

    drawLine(9, seconds/10);
    drawLine(10, seconds%10);

    last = ms;
  }
}




