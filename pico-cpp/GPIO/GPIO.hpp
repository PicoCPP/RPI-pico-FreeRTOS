#include "hardware/gpio.h"
namespace pico_cpp
{
    enum class PinType
    {
        Input,
        Output
    };
    class GPIO_Pin
    {
    public:
        GPIO_Pin(const int pinNumber, const PinType function) : pin_number(pinNumber),
                                                                pin_function(function)
        {
            gpio_init(pinNumber);
            if (function == PinType::Input)
            {
                gpio_set_dir(pinNumber, GPIO_IN);
            }
            else if (function == PinType::Output)
            {
                gpio_set_dir(pinNumber, GPIO_OUT);
            }
        }
        void toggle() const
        {
           const bool pinStatus = gpio_get (pin_number);
           gpio_put(pin_number,!pinStatus);
        }
           void set_high() const
        {
           gpio_put(pin_number,1);
        }
                   void set_low() const
        {
           gpio_put(pin_number,0);
        }


    private:
        const int pin_number;
        const PinType pin_function;
    };
}; // namespace pico_cpp