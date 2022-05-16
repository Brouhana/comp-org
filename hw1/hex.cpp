/**
  CSCE 312 Spring 2022, Homework 1
  https://people.engr.tamu.edu/djimenez/classes/312/hw1/index.html

  @file hex.cpp
  @author Brennan Rouhana
  @date Jan 26 2022
  @note Compile: g++ -o hex hex.cpp
        Usage: ./hex [b|d|b] [b|d|b] [val]
*/

#include <iostream>
#include <sstream>
#include <string>

int dec(char from, std::string val);
std::string dec2hex(int val);
std::string dec2bin(int val);
std::string display(char from, char to, std::string val_str,
                    std::string conv_str);

int main(int argc, char **argv) {
  // Get arguments
  char *from = argv[1], *to = argv[2];
  std::string val = argv[3];

  // Validate arguments (must be b, d, h); terminate if invalid
  if (!(*from == 'b' || *from == 'd' || *from == 'h') ||
      !(*to == 'b' || *to == 'd' || *to == 'h')) {
    std::cout << "Usage: ./hex [ h | d | b ] [ h | d | b]" << std::endl;
    exit(1);
  }

  // Convert value to decimal
  // See dec() function
  int dec_conv = dec(*from, val);

  // Determine, based on 'to' value, to convert to desired representation
  // and display the string output. See dec2bin(), dec2hex(), and display()
  // functions
  std::string output = "";

  switch (*to) {
  case 'b':
    output = display(*from, *to, val, dec2bin(dec_conv));
    break;
  case 'h':
    output = display(*from, *to, val, dec2hex(dec_conv));
    break;
  case 'd':
    // Convert int to string
    std::stringstream ss;
    ss << dec_conv;
    output = display(*from, *to, val, ss.str());
    break;
  }

  std::cout << output << std::endl;

  return 0;
}

std::string dec2hex(int val) {
  /**
    Converts decimal to hexadecimal

    @param val decimal integer value
    @return a hexadecimal representation
  */

  // Use stringstream and standard hex function to convert integer to a hex
  // value as a string
  std::stringstream ss;
  ss << std::hex << val;
  return ss.str();
}

std::string dec2bin(int val) {
  /**
    Converts decimal to binary

    @param val decimal integer value
    @return a binary representation
  */

  // Similar paradigm in dec2hex(). Uses standard bitset function to return a
  // binary 2's complement
  std::stringstream ss;
  ss << std::bitset<64>(val);
  std::string bin_str = ss.str();

  // Remove leading zeros present in bin_str
  while (bin_str[0] == '0') {
    bin_str.erase(0, 1);
  }
  return bin_str;
}

int dec(char from, std::string val) {
  /**
    Converts a value to decimal. This covers x -> decimal conversions,
    and serves as an intermediary (e.g: b -> h == b -> d then d -> h)

    @param from character of what to convert from
    @param val string of digits that represent from
    @return a decimal representation
  */

  switch (from) {
  case 'b':
    // Binary to decimal
    return stoi(val, 0, 2);
  case 'h':
    // Hexadecimal to decimal
    return stoi(val, nullptr, 16);
  }

  // Decimal to decimal; return value
  return stoi(val);
}

std::string display(char from, char to, std::string val_str,
                    std::string conv_str) {
  /**
    Handles string output

    @param from character of what was converted
    @param to character of what was converted to
    @param val_str string of the value to convert
    @param conv_str string of the computed conversion
    @return complete output
  */
  std::string from_str, to_str = "";

  switch (from) {
  case 'b':
    from_str = "binary";
    break;
  case 'h':
    from_str = "hexadecimal";
    break;
  case 'd':
    from_str = "decimal";
    break;
  }

  switch (to) {
  case 'b':
    to_str = "binary";
    break;
  case 'h':
    to_str = "hexadecimal";
    break;
  case 'd':
    to_str = "decimal";
    break;
  }

  return from_str + " " + val_str + " is " + to_str + " " + conv_str;
}