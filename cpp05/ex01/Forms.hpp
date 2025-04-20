#include <string>

class Form
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _reqSign;
        const int           _reqExec;
    public:
        Form();
        Form(std::string name);
}
