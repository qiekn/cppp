
#include <filesystem>
#include <fstream>
#include <iostream>
#include <optional>
#include <string>

std::filesystem::path current_source_dir = std::filesystem::path(__FILE__).parent_path();

// ----------------------------------------------------------------------------: Without std::optional

/**
 * @brief Case of without using std::optional
 *
 * @param filepath 
 * @param is_success (out parameter)
 * @return
 */
std::string ReadFileAsString(const std::string& filepath, bool* is_success) {
  std::ifstream stream(filepath);

  if (stream) {
    std::string result((std::istreambuf_iterator<char>(stream)),
                       (std::istreambuf_iterator<char>()));
    stream.close();
    *is_success = true;
    return result;
  }

  *is_success = false;
  return std::string();
}

void TestCase_1(const char* filename) {
  bool is_file_open_successfully;
  std::filesystem::path filepath = current_source_dir / filename;
  std::string data = ReadFileAsString(filepath.string(), &is_file_open_successfully);
  if (is_file_open_successfully) {
    std::cout << "testcase_1 " << filename << ": " << data;
  } else {
    std::cout << "testcase_1 " << filename << ": Open file failed!\n";
  }
}

// ----------------------------------------------------------------------------: Use std::optional (= v =)

std::optional<std::string> ReadFileAsString(const std::string& filepath) {
  std::ifstream stream(filepath);
  if (stream) {
    // Read file
    std::string result((std::istreambuf_iterator<char>(stream)),
                       (std::istreambuf_iterator<char>()));
    stream.close();
    return result;
  }
  return std::nullopt;  // or you can just write `return {};`
}

void TestCase_2(const char* filename) {
  std::filesystem::path filepath = current_source_dir / filename;
  std::optional<std::string> data = ReadFileAsString(filepath.string());
  if (data.has_value()) {
    std::cout << "testcase_1 " << filename << ": " << data.value();
  } else {
    std::cout << "testcase_2 " << filename << ": Open file failed!\n";
  }
}

// ----------------------------------------------------------------------------: main

int main() {
  TestCase_1("data.txt");
  TestCase_1("non-existent");
  TestCase_2("data.txt");
  TestCase_2("non-existent");

  return 0;
}
