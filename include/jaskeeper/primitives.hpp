#include <string>
#include <vector>
#include <variant>

using JStringPrimitive = std::string;
using JNumberPrimitive = double;
using JBooleanPrimitive = bool;

class JUndefined {};
class JNull {};

using JPrimitive = std::variant<JStringPrimitive, JNumberPrimitive, JBooleanPrimitive, JUndefined, JNull>;

bool isString(JPrimitive& v);
bool isNumber(JPrimitive& v);
bool isBoolean(JPrimitive& v);
bool isUndefined(JPrimitive& v);
bool isNull(JPrimitive& v);