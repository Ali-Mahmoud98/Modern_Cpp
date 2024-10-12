#include <iostream>
#include <functional>
#include <vector>

class Button {
public:
    using CallbackFunction = std::function<void()>;

    // Register a callback function for the "pressed" event
    void registerCallback(CallbackFunction callback) {
        callbacks.push_back(callback);
    }

    // Simulate the button being pressed
    void press() {
        std::cout << "Button Pressed!" << std::endl;

        // Notify all registered callback functions
        for (const auto& callback : callbacks) {
            callback();
        }
    }

private:
    std::vector<CallbackFunction> callbacks;
};

// Example callback functions
void onButtonClick() {
    std::cout << "Button Click Event Handled!" << std::endl;
}

void onButtonPress() {
    std::cout << "Button Press Event Handled!" << std::endl;
}

int main() {
    // Create a button
    Button myButton;

    // Register callback functions for the button
    myButton.registerCallback(onButtonClick);
    myButton.registerCallback(onButtonPress);

    // Simulate the button being pressed
    myButton.press();

    return 0;
}
