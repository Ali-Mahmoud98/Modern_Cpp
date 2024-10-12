# Message Passing
## Introduction
Message Passing is a key concept in object-oriented programming (OOP) that refers to the process of objects communicating with each other by sending and receiving information (messages). In OOP, objects interact by calling each other’s methods, passing data as arguments, and potentially receiving results. This approach promotes modularity, as it allows objects to be designed independently, focusing on the messages they send and receive rather than the internal details of other objects.

Message Passing enables objects to interact and collaborate by sending and receiving messages. It promotes modularity, encapsulation, and flexibility in software design, making it easier to build, maintain, and extend complex systems. By focusing on the interfaces for communication rather than internal details, message passing helps in creating decoupled and robust object-oriented systems.


### Understanding Message Passing
In the context of OOP, a message typically refers to a method call. When one object sends a message to another, it is essentially invoking a method on that object, often with certain arguments (data). The receiving object then processes the message according to its method definition.

Message passing encapsulates the idea that objects can communicate with each other through well-defined interfaces (methods), without needing to know the specifics of how the other object is implemented.

### Example of Message Passing
Consider we have two classes, `Calculator` and `Display`. The `Calculator` class performs arithmetic operations and sends the result as a message to the `Display` class to show the output.

```cpp
#include <iostream>

// Class responsible for displaying results
class Display {
public:
    void showMessage(const std::string& message) {
        std::cout << message << std::endl;
    }

    void showResult(int result) {
        std::cout << "Result: " << result << std::endl;
    }
};

// Class responsible for performing calculations
class Calculator {
private:
    Display display;

public:
    void add(int a, int b) {
        int result = a + b;
        display.showMessage("Adding numbers...");
        display.showResult(result);
    }

    void subtract(int a, int b) {
        int result = a - b;
        display.showMessage("Subtracting numbers...");
        display.showResult(result);
    }
};

int main() {
    Calculator calc;
    calc.add(10, 5);       // Sends message to Display to show addition result
    calc.subtract(10, 3);  // Sends message to Display to show subtraction result

    return 0;
}
```

#### Code Explanation:
1. **Message Sending**: The `Calculator` class sends messages to the `Display` class using method calls like `display.showMessage()` and `display.showResult()`.
2. **Message Receiving**: The `Display` class receives these messages and processes them by executing the corresponding methods.
3. **Encapsulation of Communication**: The `Calculator` and `Display` classes communicate without needing to know the internal workings of each other, only relying on the methods they expose.

### Benefits of Message Passing
1. **Modularity**: By focusing on messages rather than internal details, objects can be designed and implemented independently, promoting a modular and maintainable codebase.
2. **Encapsulation**: Message passing reinforces encapsulation by hiding the internal workings of objects and exposing only the necessary interfaces for communication.
3. **Flexibility**: Objects can be easily replaced or modified without affecting other parts of the system, as long as the message interfaces remain consistent.
4. **Decoupling**: Message passing reduces the dependencies between objects, making the system more robust and easier to modify or extend.

### Real-World Analogy
Message passing in OOP can be compared to communication between people. When you send a message to someone (e.g., ask a question), you don’t need to know exactly how they will process it (think it over). You only care about the response (the answer) you receive. Similarly, in OOP, objects send messages (method calls) to each other and process the received messages independently.

## Use Cases of Message Passing
### 1. Inter-object Communication
* Message passing is fundamental for communication between objects in any OOP system, enabling interactions and collaboration among various components.
* In an OOP system, objects often need to communicate with each other to perform tasks or share information. For instance, consider a simple simulation where a `Thermostat` object communicates with a `Heater` object to maintain a desired temperature.

#### Example:
```cpp
#include <iostream>

// Heater class
class Heater {
public:
    void turnOn() {
        std::cout << "Heater is turned ON." << std::endl;
    }

    void turnOff() {
        std::cout << "Heater is turned OFF." << std::endl;
    }
};

// Thermostat class
class Thermostat {
private:
    Heater& heater; // Reference to Heater object
    int temperature;

public:
    Thermostat(Heater& h) : heater(h), temperature(20) {}

    void setTemperature(int temp) {
        temperature = temp;
        controlHeater();
    }

    void controlHeater() {
        if (temperature < 22) {
            heater.turnOn();
        } else {
            heater.turnOff();
        }
    }
};

int main() {
    Heater myHeater;
    Thermostat thermostat(myHeater);

    thermostat.setTemperature(20); // Heater is turned ON
    thermostat.setTemperature(23); // Heater is turned OFF

    return 0;
}
```

**Explanation:**
- The `Thermostat` object communicates with the `Heater` object by calling its methods (`turnOn()` and `turnOff()`) based on the temperature set. This demonstrates inter-object communication where objects work together to achieve a common goal.
- **Inter-object Communication:** Objects interact with each other through method calls, allowing them to work together and achieve functionality (e.g., a `Thermostat` controlling a `Heater`).


### 2. Event Handling
* In event-driven programming, message passing is used to handle events like user inputs or system signals. For example, consider a simple graphical user interface (GUI) where a `Button` object sends a message to a `Handler` object when clicked.
* In event-driven programming, message passing is used to handle events like user inputs or system signals, where one object sends a message to another to trigger a response.

#### Example:
```cpp
#include <iostream>

// Handler class
class ButtonHandler {
public:
    void onClick() {
        std::cout << "Button clicked!" << std::endl;
    }
};

// Button class
class Button {
private:
    ButtonHandler& handler; // Reference to ButtonHandler object

public:
    Button(ButtonHandler& h) : handler(h) {}

    void click() {
        handler.onClick(); // Sending a message to the handler
    }
};

int main() {
    ButtonHandler myHandler;
    Button myButton(myHandler);

    myButton.click(); // Triggers the onClick event

    return 0;
}
```

**Explanation:**
- The `Button` object sends a message to the `ButtonHandler` object when the `click()` method is called. The `ButtonHandler` then processes this message by executing the `onClick()` method. This illustrates event handling where actions (events) are handled by specific methods.
- **Event Handling:** In event-driven systems, objects send messages to handle events like user actions (e.g., a `Button` notifying a `ButtonHandler` when clicked).


### 3. Distributed Systems
* In distributed systems, message passing can be used for communication between different systems or services over a network. For example, consider a client-server scenario where a `Client` sends a request to a `Server`, and the `Server` processes the request and sends a response back.
* In distributed systems, message passing can be used for communication between different systems or services, where messages are sent across networks to invoke actions on remote objects.


#### Example (simplified to illustrate the concept):
```cpp
#include <iostream>
#include <string>

// Server class
class Server {
public:
    std::string processRequest(const std::string& request) {
        std::cout << "Server processing request: " << request << std::endl;
        return "Response to: " + request;
    }
};

// Client class
class Client {
private:
    Server& server; // Reference to Server object

public:
    Client(Server& s) : server(s) {}

    void sendRequest(const std::string& request) {
        std::string response = server.processRequest(request);
        std::cout << "Client received: " << response << std::endl;
    }
};

int main() {
    Server myServer;
    Client myClient(myServer);

    myClient.sendRequest("Hello Server"); // Client sends request, Server processes it

    return 0;
}
```

**Explanation:**
- The `Client` object sends a message to the `Server` object by calling `processRequest()`. The `Server` processes this request and sends a response back to the `Client`. This example demonstrates message passing in a distributed system where communication occurs over a network (though simplified in this example).
- **Distributed Systems:** Messages are exchanged between systems or services over a network to perform tasks or share information (e.g., a `Client` sending a request to a `Server`).
