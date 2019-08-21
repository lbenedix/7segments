#define MAX_RAND 0xFFFFFF
#define MIN_RAND 0x666666

void turn_off() {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0, 0, 0);
  }
  strip.show();
}

void glitter(int d) {
  for (int i = 0; i < strip.numPixels(); i++) {
    uint32_t color = strip.Color(random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND));
    strip.setPixelColor(i, color);
  }
  strip.show();
  delay(d);
}


void print_number(int number, uint32_t color, bool rnd, bool more_rnd) {
  String s = String(number);
  print_number(s, color, rnd, more_rnd);
}

void print_number(String number, uint32_t color, bool rnd, bool more_rnd) {
  uint32_t old_color = color;
  for (int i = 0; i < 4; i++) {
    // See ascii table
    if (i == 0 && number[i] - 48 == 0) {
      print_digit(i, number[i] - 48, strip.Color(0, 0, 0), rnd, more_rnd);
    } else {
      print_digit(i, number[i] - 48, color, rnd, more_rnd);
    }
  }
  strip.show();
}

void print_digit(int segment, int number, uint32_t color, bool rnd, bool more_rnd) {
  int offset = segment * 21;

  for (int i = offset; i <= offset + 20; i++) {
    strip.setPixelColor(i, 0, 0, 0);
  }

  if (number == 4 || number ==  5 || number ==  6 || number ==  8 || number ==  9 || number ==  0) {
    if (rnd || more_rnd) {
      color = strip.Color(random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND));
    }
    strip.setPixelColor(offset + 0, color);
    if (more_rnd) {
      color = strip.Color(random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND));
    }
    strip.setPixelColor(offset + 1, color);
    if (more_rnd) {
      color = strip.Color(random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND));
    }
    strip.setPixelColor(offset + 2, color);
  }

  if ( number == 2 || number ==  3 || number ==  5 || number ==  6 || number ==  7 || number ==  8 || number ==  9 || number ==  0) {
    if (rnd || more_rnd) {
      color = strip.Color(random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND));
    }
    strip.setPixelColor(offset + 3, color);
    if (more_rnd) {
      color = strip.Color(random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND));
    }
    strip.setPixelColor(offset + 4, color);
    if (more_rnd) {
      color = strip.Color(random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND));
    }
    strip.setPixelColor(offset + 5, color);
  }

  if ( number == 1 || number ==  2 || number == 4 || number ==  3 || number ==  7 || number ==  8 || number ==  9 || number ==  0) {
    if (rnd || more_rnd) {
      color = strip.Color(random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND));
    }
    strip.setPixelColor(offset + 6, color);
    if (more_rnd) {
      color = strip.Color(random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND));
    }
    strip.setPixelColor(offset + 7, color);
    if (more_rnd) {
      color = strip.Color(random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND));
    }
    strip.setPixelColor(offset + 8, color);
  }

  if ( number == 2 || number ==  3 || number ==  4 || number ==  5 || number ==  6 || number ==  8 || number ==  9) {
    if (rnd || more_rnd) {
      color = strip.Color(random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND));
    }
    strip.setPixelColor(offset + 9, color);
    if (more_rnd) {
      color = strip.Color(random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND));
    }
    strip.setPixelColor(offset + 10, color);
    if (more_rnd) {
      color = strip.Color(random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND));
    }
    strip.setPixelColor(offset + 11, color);
  }

  if (number == 2 || number ==  6 || number ==  8 || number == 0) {
    if (rnd || more_rnd) {
      color = strip.Color(random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND));
    }
    strip.setPixelColor(offset + 12, color);
    if (more_rnd) {
      color = strip.Color(random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND));
    }
    strip.setPixelColor(offset + 13, color);
    if (more_rnd) {
      color = strip.Color(random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND));
    }
    strip.setPixelColor(offset + 14, color);
  }

  if (number == 2 || number == 3 || number == 5 || number == 6 || number == 8 || number == 9 || number == 0) {
    if (rnd || more_rnd) {
      color = strip.Color(random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND));
    }
    strip.setPixelColor(offset + 15, color);
    if (more_rnd) {
      color = strip.Color(random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND));
    }
    strip.setPixelColor(offset + 16, color);
    if (more_rnd) {
      color = strip.Color(random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND));
    }
    strip.setPixelColor(offset + 17, color);
  }

  if (number == 1 || number == 3 || number == 4 || number == 5 || number == 6 || number == 7 || number == 8 || number == 9 || number == 0) {
    if (rnd || more_rnd) {
      color = strip.Color(random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND));
    }
    strip.setPixelColor(offset + 18, color);
    if (more_rnd) {
      color = strip.Color(random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND));
    }
    strip.setPixelColor(offset + 19, color);
    if (more_rnd) {
      color = strip.Color(random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND), random(MIN_RAND, MAX_RAND));
    }
    strip.setPixelColor(offset + 20, color);
  }
}
