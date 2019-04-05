#ifndef ERROR_HH
#define ERROR_HH

#include <string>
#include <optional>

namespace Terryn
{
static std::string DEFAULT_ERROR = "";

class Error
{
private:
    bool _inError = false;
    std::string _errorString = DEFAULT_ERROR;
    void Reset();

public:
    Error() = default;

    void SetError(const std::string &error);
    void SetError(std::string &&error);
    void AppendError(const std::string &error);
    std::optional<std::string> GetError();
    bool InError() const;

};

}


#endif // ERROR_HH
