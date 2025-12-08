#include <algorithm>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

// ----------------------------------------------------------------------------: path
void ScanCppSources(const std::string& folder_path) {
  for (const auto& entry : fs::directory_iterator(folder_path)) {
    if (entry.path().extension() == ".cpp") {
      std::cout << "Found cpp source filie: " << entry.path().string() << '\n';
    }
  }
}

void TestSearchCppSources() {
  std::filesystem::path current_filepath(__FILE__);
  std::filesystem::path current_dir = current_filepath.parent_path();
  std::cout << "Scanning directory: " << current_dir.string() << '\n';
  ScanCppSources(current_dir.string());
}

void TestComposition() {
  std::cout << "\n==== TestComposition =====\n";
  std::filesystem::path root_dir = "C:/projects/ck-engine";
  std::filesystem::path texture_path = root_dir / "assts" / "textures" / "cat.png";
  std::cout << "Full Path: " << texture_path.string() << '\n';
}

void TestDecomposition() {
  std::filesystem::path filepath(__FILE__);
  std::cout << "\n==== TestDecomposition =====\n";

  std::cout << "current filename:\t" << filepath.filename().string() << '\n';
  std::cout << "current filepath:\t" << filepath.string() << '\n';
  std::cout << "current directory:\t" << filepath.root_directory().string() << '\n';
  std::cout << "parent path:\t" << filepath.parent_path().string() << '\n';
}

// Recursively print directory tree
void PrintTree(const fs::path& path, const std::string& prefix = "", bool is_last = true) {
  // Print current item
  std::cout << prefix;
  std::cout << (is_last ? "├──" : "─ ");
  std::cout << path.filename().string() << '\n';

  // If it's a directory, recursively print sub-items
  if (fs::is_directory(path)) {
    try {
      std::vector<fs::path> entries;
      for (const auto& entry : fs::directory_iterator(path)) {
        entries.push_back(entry.path());
      }

      // Sort for consistent output
      std::sort(entries.begin(), entries.end());

      for (size_t i = 0; i < entries.size(); ++i) {
        bool is_last_entry = (i == entries.size() - 1);
        std::string new_prefix = prefix + (is_last ? "    " : "│   ");
        PrintTree(entries[i], new_prefix, is_last_entry);
      }
    } catch (const fs::filesystem_error& e) {
      // Handle errors like insufficient permissions
      std::cout << prefix << (is_last ? "    " : "│   ") << "[Error: " << e.what() << "]" << '\n';
    }
  }
}

void TestPrintTree() {
  std::string root_dir = PROJECT_ROOT_DIR;

  std::cout << "Project Root Directory: " << root_dir << "\n\n";

  // Print directory tree
  fs::path root_path(root_dir);
  std::cout << root_path.filename().string() << '\n';

  try {
    std::vector<fs::path> entries;
    for (const auto& entry : fs::directory_iterator(root_path)) {
      entries.push_back(entry.path());
    }

    std::sort(entries.begin(), entries.end());

    for (size_t i = 0; i < entries.size(); ++i) {
      bool is_last = (i == entries.size() - 1);
      PrintTree(entries[i], "", is_last);
    }
  } catch (const fs::filesystem_error& e) {
    std::cerr << "Error: " << e.what() << '\n';
  }
}

int main() {
  TestComposition();
  TestDecomposition();
  TestSearchCppSources();
}
