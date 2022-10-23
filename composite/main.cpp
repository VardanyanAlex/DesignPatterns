
#include "drawables.h"

int main()
{
    using namespace DesignPatterns;

    GraphicsPtr pRect = std::make_shared<CRectangle>(1, 2);
    pRect->Draw();

    PicturePtr pPicture = std::make_shared<CPicture>();

    pPicture->Add(pRect);

    pPicture->Draw();

    PicturePtr pFinalPicture = std::make_shared<CPicture>();
    pFinalPicture->Add(pPicture);

    GraphicsPtr pLine = std::make_shared<CLine>(11, 7);

    pFinalPicture->Add(pLine);

    pFinalPicture->Draw();

}
