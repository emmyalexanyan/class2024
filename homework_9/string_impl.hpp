#include <iostream>
#include <algorithm>

class String {

public:
    String() : length(0), isLarge(false) {
        data.smallString[0] = '\0';
    }

    String(const char* str) : length(0), isLarge(false) {
        while (str[length] != '\0' && length < SMALL_STRING_SIZE - 1) {
            data.smallString[length] = str[length];
            ++length;
        }
        data.smallString[length] = '\0';
        if (str[length] != '\0') {
            data.largeString = new char[strlen(str) - length + 1];
            for (size_t i = 0; str[length + i] != '\0'; ++i) {
                data.largeString[i] = str[length + i];
            }
            data.largeString[strlen(str) - length] = '\0';
            isLarge = true;
        }
    }

    String(const String& other) : length(other.length), isLarge(other.isLarge) {
        if (isLarge) {
            data.largeString = new char[strlen(other.data.largeString) + 1];
            for (size_t i = 0; other.data.largeString[i] != '\0'; ++i) {
                data.largeString[i] = other.data.largeString[i];
            }
            data.largeString[strlen(other.data.largeString)] = '\0';
        } else {
            for (size_t i = 0; i <= length; ++i) {
                data.smallString[i] = other.data.smallString[i];
            }
        }
    }

    ~String() {
        if (isLarge) {
            delete[] data.largeString;
        }
    }

    String& operator=(const String& other) {
        if (this != &other) {
            if (isLarge) {
                delete[] data.largeString;
            }
            length = other.length;
            isLarge = other.isLarge;
            if (isLarge) {
                data.largeString = new char[strlen(other.data.largeString) + 1];
                for (size_t i = 0; other.data.largeString[i] != '\0'; ++i) {
                    data.largeString[i] = other.data.largeString[i];
                }
                data.largeString[strlen(other.data.largeString)] = '\0';
            } else {
                for (size_t i = 0; i <= length; ++i) {
                    data.smallString[i] = other.data.smallString[i];
                }
            }
        }
        return *this;
    }

    size_t size() const { return length; }
    const char* c_str() const { return isLarge ? data.largeString : data.smallString; }

    String operator+(const String& other) const {
        String result;
        size_t totalLength = length + other.length;
        if (totalLength >= SMALL_STRING_SIZE) {
            result.isLarge = true;
            result.data.largeString = new char[totalLength + 1];
            for (size_t i = 0; i < length; ++i) {
                result.data.largeString[i] = c_str()[i];
            }
            for (size_t i = 0; i < other.length; ++i) {
                result.data.largeString[length + i] = other.c_str()[i];
            }
            result.data.largeString[totalLength] = '\0';
        } else {
            for (size_t i = 0; i < length; ++i) {
                result.data.smallString[i] = c_str()[i];
            }
            for (size_t i = 0; i < other.length; ++i) {
                result.data.smallString[length + i] = other.c_str()[i];
            }
            result.data.smallString[totalLength] = '\0';
        }
        result.length = totalLength;
        return result;
    }

    friend std::ostream& operator<<(std::ostream& out, const String& str) {
        out << str.c_str();
        return out;
    }

private:
   static const size_t SMALL_STRING_SIZE = 16;

    union Data {
        char smallString[SMALL_STRING_SIZE];
        char* largeString;
    };

    Data data;
    size_t length;
    bool isLarge;
};


