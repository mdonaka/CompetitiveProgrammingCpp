#pragma once

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

class Table {
  std::string title;
  std::vector<std::pair<std::string, bool>> table;

public:
  Table(const std::string& title) : title(title) {}

  auto add(const std::string& name, bool b) { table.emplace_back(name, b); }
  auto print() const {
    auto size =
        std::ranges::max(table | std::views::transform(
                                     [](const std::pair<std::string, bool>& p) {
                                       return p.first.size();
                                     }));

    std::cout << std::string(size + 12, '_') << std::endl;
    std::cout << "| " << title << std::string(size + 9 - title.size(), ' ')
              << "|" << std::endl;
    std::cout << "|" << std::string(size + 10, '-') << "|" << std::endl;
    for (const auto& [s, b] : table) {
      std::cout << "| " << std::left << std::setw(size) << s << " | "
                << (b ? "True " : "False") << " |" << std::endl;
    }
  }
};
