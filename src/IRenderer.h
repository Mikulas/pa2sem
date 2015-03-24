#ifndef IRENDERER
#define IRENDERER


class IRenderer
{
    public:
    	virtual ~IRenderer() {}
        virtual void renderBoard() = 0;
};


#endif
