#include "error.hh"



void Terryn::Error::SetError(const std::string &error)
{
    if(_inError)
    {
        return;
    }
    _inError = true;
    _errorString = error;
}

void Terryn::Error::SetError(std::string &&error)
{
    if(_inError)
    {
        return;
    }
    _inError = true;
    _errorString = std::move(error);
}

void Terryn::Error::AppendError(const std::string &error)
{
    if(_inError)
    {
        _errorString += "\n";
    }
    else
    {
        _inError = true;
        _errorString = "";
    }
    _errorString += error;
}

void Terryn::Error::Reset()
{
    _inError = false;
    _errorString = DEFAULT_ERROR;
}

std::optional<std::string> Terryn::Error::GetError()
{
    if(!_inError)
    {
        return std::nullopt;
    }
    if((_errorString.size() <= 0 || _errorString == DEFAULT_ERROR))
    {
        Reset();
        return { "No Error String for attached error" };
    }
    auto tmpString = _errorString;
    Reset();
    return tmpString;
}

bool Terryn::Error::InError() const
{
    return _inError;
}
