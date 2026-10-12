#include <iostream>
#include <NKFont/NkFont.h>
#include <NKImage/NKImage.h>
int main()
{
    nkentseu::NkFontAtlas atlas18;

  nkentseu::NkFont* font18 =
    atlas18.AddFontFromFile(
        "C:/Windows/Fonts/arial.ttf",
        18.f
    );

    if (font18 == nullptr)
    {
        std::cout << "Erreur lors du chargement de la police.\n";
        return 1;
    }

    atlas18.Build();

    unsigned char* pixels18 = nullptr;
    int largeur18 = 0;
    int hauteur18 = 0;

    atlas18.GetTexDataAsRGBA32(
        &pixels18,
        &largeur18,
        &hauteur18
    );

    nkentseu::NkImage image =
        nkentseu::NkImage::Wrap(
            pixels18,
            largeur18,
            hauteur18,
            nkentseu::NkImagePixelFormat::NK_RGBA32
        );

    image.SavePNG("atlas18.png");

    std::cout << "Taille : 18\n";
    std::cout << "Glyphes : " << font18->glyphCount << "\n";
    std::cout << "Texture : "
              << largeur18 << " " << hauteur18 << "\n";

    nkentseu::NkFontAtlas atlas48;

    nkentseu::NkFont* font48 =
    atlas48.AddFontFromFile(
        "C:/Windows/Fonts/arial.ttf",
        48.f
    );
    if (font48 == nullptr)
    {
        return 1;
    }

    atlas48.Build();

    unsigned char* pixels48 = nullptr;
    int largeur48 = 0;
    int hauteur48 = 0;

    atlas48.GetTexDataAsRGBA32(
        &pixels48,
        &largeur48,
        &hauteur48
    );

    image.SavePNG("atlas48.png");

    std::cout << "Taille : 48\n";
    std::cout << "Glyphes : " << font48->glyphCount << "\n";
    std::cout << "Texture : "
              << largeur48 << " " << hauteur48 << "\n";

    return 0;
}

