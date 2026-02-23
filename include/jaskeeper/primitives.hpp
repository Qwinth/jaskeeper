#include <string>
#include <vector>
#include <variant>

using JStringPrimitive = std::string;
using JNumberPrimitive = double;
using JBooleanPrimitive = bool;

class JUndefined {};
class JNull {};

using JPrimitive = std::variant<JStringPrimitive, JNumberPrimitive, JBooleanPrimitive, JUndefined, JNull>;