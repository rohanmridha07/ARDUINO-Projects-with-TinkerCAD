// C++ code
// Author: Rohan Mridha
// EEE-23, KUET
#include <Adafruit_NeoPixel.h>

#define PIN 6
#define N_LEDS 4

// Initialize the Neopixel strip object
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

// Function prototype for the chase effect
static void chase(uint32_t c);

void setup()
{
  strip.begin();           // Prepare the data pin for output
  strip.show();            // Initialize all LEDs to 'off'
}

void loop()
{
  chase(strip.Color(255, 0, 0)); // Red
  chase(strip.Color(0, 255, 0)); // Green
  chase(strip.Color(0, 0, 255)); // Blue
}

// Creates a chasing light effect
static void chase(uint32_t c)
{
  // The loop runs longer than the number of pixels
  // to make the chase "run off" the end of the strip.
  for (uint16_t i = 0; i < strip.numPixels() + 4; i++)
  {
    strip.setPixelColor(i, c);         // Turn on the current LED
    strip.setPixelColor(i - 4, 0);     // Turn off the trailing LED
    strip.show();                      // Update the strip to show changes
    delay(25);                         // A short pause to control the speed
  }
}
