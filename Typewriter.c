#include <stdio.h>
#include <windows.h>
#include <string.h>

#define MAX_INPUT_SIZE 2048  // Adjust the size as needed

void countdown() {
    for (int i = 3; i > 0; i--) {
        printf("Countdown: %d\n", i);
        Sleep(1000);  // Pause for 1 second (time in milliseconds)
    }
}

void simulateTyping(const char* text) {
    INPUT inputs[2] = { 0 };

    for (size_t i = 0; i < strlen(text); i++) {
        if (i % 20 == 0 && i != 0) {
            // Pause for 3 seconds every 20 characters (except for the first iteration)
            printf("Pausing for 3 seconds...\n");
            Sleep(3000);
        }

        inputs[0].type = INPUT_KEYBOARD;
        inputs[0].ki.wVk = 0;  // virtual key code
        inputs[0].ki.wScan = text[i];
        inputs[0].ki.dwFlags = KEYEVENTF_UNICODE;

        inputs[1].type = INPUT_KEYBOARD;
        inputs[1].ki.wVk = 0;  // virtual key code
        inputs[1].ki.wScan = text[i];
        inputs[1].ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;

        SendInput(2, inputs, sizeof(INPUT));
        Sleep(50);  // Small delay to simulate typing speed
    }
}

int main() {
    char input[MAX_INPUT_SIZE];



    printf("Enter text: ");
    fgets(input, sizeof(input), stdin);

    // Remove the newline character from the input
    input[strcspn(input, "\n")] = '\0';

    printf("Press Enter to start typing countdown...\n");
    getchar();  // Wait for Enter key

    countdown();

    printf("Typing...\n");
    Sleep(2000);  // Pause for 2 seconds before typing starts

    simulateTyping(input);

    return 0;
}
