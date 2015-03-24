#ifndef IRENDERER
#define IRENDERER

#include <string>

using std::string;


class IRenderer
{
    public:
    	virtual ~IRenderer() {}
        virtual void renderBoard() = 0;
        virtual string ask(string question) = 0;
};


#endif
