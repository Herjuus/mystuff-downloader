#include <wiisprite.h>

using namespace wsp;

int main() {
  // Initialize graphics
  WSRuntime::init();
  WSDisplay::setDisplayMode(WSDisplay::MODE_4, WSDisplay::RESOLUTION_640x480, WSDisplay::DEPTH_32, 60);

  // Create a screen
  WSScreen *screen = new WSScreen();
  screen->SetBackground(CColor::White);

  // Create a text element
  WSText text("Hello, World!");
  text.SetPosition(100, 100); // Set position
  text.SetFontSize(24); // Set font size

  // Add text to screen
  screen->AddElement(&text);

  // Main loop
  while (true) {
    // Handle events
    WSRuntime::handleEvents();

    // Update display
    WSDraw::StartRender();
    screen->Tick();
    screen->Render();
    WSDraw::FinishRender();
  }

  // Clean up
  delete screen;
  WSRuntime::shutdown();
  return 0;
}
