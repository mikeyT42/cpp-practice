#include <cstdlib>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <variant>

#define SENTINEL '\n'

// -----------------------------------------------------------------------------
enum class loop_control {
  CONTINUE,
  STOP,
};

enum class validation_code {
  NO_INPUT,
  TOO_MANY,
  NOT_ENOUGH,
  INPUT_ERR,
};

using validation_result = std::variant<std::tuple<int, int>, validation_code>;

// -----------------------------------------------------------------------------
class point {
public:
  int x;
  int y;

  point(const int x, const int y) : x(x), y(y) {}
  std::string to_string() const;
};

// -----------------------------------------------------------------------------
std::string point::to_string() const {
  std::ostringstream ss;
  ss << "point {\n"
     << "  x = " << this->x << '\n'
     << "  y = " << this->y << '\n'
     << '}' << std::endl;
  return ss.str();
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
loop_control input_loop();
validation_result validate(std::string_view input);

// -----------------------------------------------------------------------------
int main(void) {
  std::system("clear");
  std::cout
      << "====================================================================="
      << '\n'
      << "\tWelcome the Point Inputter\n"
      << "====================================================================="
      << '\n'
      << std::endl;

  loop_control l;
  do {
    l = input_loop();
  } while (l == loop_control::CONTINUE);

  std::cout
      << "====================================================================="
      << '\n'
      << "\t\t\tThank you\n"
      << "====================================================================="
      << '\n'
      << std::endl;

  return EXIT_SUCCESS;
}

// -----------------------------------------------------------------------------
loop_control input_loop() {
  std::cout
      << "Please input 2 integers, an x and y value, for a point in space.\n"
      << std::endl;
  std::string input;
  std::getline(std::cin, input);

  auto result = validate(input);

  if (auto *error = std::get_if<validation_code>(&result)) {
    switch (*error) {
    case validation_code::NO_INPUT:
      return loop_control::STOP;
    case validation_code::NOT_ENOUGH:
      std::cout << "You did not input enough points, please try again.\n"
                << std::endl;
      return loop_control::CONTINUE;
    case validation_code::TOO_MANY:
      std::cout << "You input too many numbers to create a point,\n"
                << "please try again.\n"
                << std::endl;
      return loop_control::CONTINUE;
    case validation_code::INPUT_ERR:
      std::cout << "Some input error. Did you enter any numbers? Please\n"
                << "try again.\n"
                << std::endl;
      return loop_control::CONTINUE;
    };
  }

  const auto [x, y] = std::get<std::tuple<int, int>>(result);
  const std::unique_ptr<point> p = std::make_unique<point>(x, y);

  std::cout << p->to_string() << std::endl;

  return loop_control::CONTINUE;
}

// -----------------------------------------------------------------------------
validation_result validate(std::string_view input) {
  if (input.empty())
    return validation_code::NO_INPUT;

  std::istringstream line(input.data());
  std::string token;
  const short MAX_POINTS = 2;
  int points[MAX_POINTS];
  short num_points = 0;

  while (line >> token) {
    std::istringstream token_stream(token);
    int parsed_number;
    if (token_stream >> parsed_number) {
      if (num_points >= MAX_POINTS)
        return validation_code::TOO_MANY;
      points[num_points] = parsed_number;
      num_points++;
    }
  }

  if (num_points == 0)
    return validation_code::INPUT_ERR;
  if (num_points < MAX_POINTS)
    return validation_code::NOT_ENOUGH;

  return std::make_tuple(points[0], points[1]);
}
