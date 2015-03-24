#ifndef LINERENDERER
#define LINERENDERER

#include <iostream>
#include "IRenderer.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;


class LineRenderer : public IRenderer {
public:
	virtual void renderBoard() override;
	virtual string ask(string question) override;
};


#endif
