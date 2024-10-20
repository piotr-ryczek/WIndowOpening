#include <EEPROM.h>
#include <memoryValue.h>

MemoryValue::MemoryValue(int setAddress, int valueAddress): setAddress(setAddress), valueAddress(valueAddress) {}

void MemoryValue::setValue(uint8_t newValue) {
    EEPROM.writeByte(valueAddress, newValue);

    if (!isSet()) {
        EEPROM.writeBool(setAddress, false); // Reversed logic
    }

    EEPROM.commit();
}

uint8_t MemoryValue::readValue() {
    return EEPROM.readByte(valueAddress);
}

bool MemoryValue::isSet() {
    return EEPROM.readBool(setAddress) == false; // Reversing, 1 = Uninitialized / 0 = Initialized
}

void MemoryValue::unset() {
    EEPROM.writeBool(setAddress, true); // Reversed logic
    EEPROM.commit();
}