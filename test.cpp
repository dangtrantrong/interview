#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <atomic>
#include <memory>
#include <thread>
#include <chrono>


using namespace std;


class Base
{
public:
	Base() {};
	~Base() { cout << "Destructor Base\n"; };
};

class Derived : public Base
{
public:
	Derived() {};
	~Derived() { cout << "Destructor Derived\n"; }
};
// int main()
// {
//     int count = 0;
//     int n = 6;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= i; j++) {
//             cout << ++count << "\t";
//         }
        
//         for (int j = 1; j <= 2*(n - i); j++)
//         {
//             cout << "\t";
//         }

//         for (int j = 1; j <= i; j++) {
//             cout << ++count << "\t";
//         }
//         cout << "\n";
//     }

//     for (int i = n - 1; i >= 1; i--)
//     {
//         for (int j = 1; j <= i; j++) {
//             cout << ++count << "\t";
//         }
        
//         for (int j = 1; j <= 2*(n - i); j++)
//         {
//             cout << "\t";
//         }

//         for (int j = 1; j <= i; j++) {
//             cout << ++count << "\t";
//         }
//         cout << "\n";
//     }
// }

// struct Foo{
//     int *data = nullptr;  
//     Foo() = default; 

//         Foo(const Foo& f){
//             data = new int[sizeof(int)];
//             memcpy(data, f.data,sizeof(int) );
//         }
 
// };
 
// int main(){
//     Foo f1;
 
//     f1.data = new int[1];
     
//     Foo f2 = f1;
 
//     std::cout << "f1 addr: " << f1.data << std::endl;
//     std::cout << "f2 addr: " << f2.data << std::endl;
 
//     std::cout << "f1: " << *f1.data << std::endl;
//     std::cout << "f2: " << *f2.data << std::endl;
 
//     *f1.data = 2;
//     std::cout << "f2: " << *f2.data << std::endl;
 
//     return 0;
// }

#include <iostream>
#include <functional>
#include <unordered_map>
#include <vector>

// Event manager class
class EventManager {
public:
    using EventHandler = std::function<void()>;

    void subscribe(const std::string& event, EventHandler handler) {
        handlers[event].push_back(handler);
    }

    void notify(const std::string& event) {
        if (handlers.find(event) != handlers.end()) {
            for (auto& handler : handlers[event]) {
                handler();
            }
        }
    }

private:
    std::unordered_map<std::string, std::vector<EventHandler>> handlers;
};

class Application {
public:
    void onButtonClick() {
        std::cout << "Button was clicked in the application!" << std::endl;
    }

    void onWindowClose() {
        std::cout << "Window is closing!" << std::endl;
    }
};

int main() {
    EventManager eventManager;
    Application app;

    eventManager.subscribe("button_click", std::bind(&Application::onButtonClick, &app));
    eventManager.subscribe("window_close", std::bind(&Application::onWindowClose, &app));

    eventManager.notify("button_click");
    eventManager.notify("window_close");

    return 0;
}


