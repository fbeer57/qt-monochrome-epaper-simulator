// ImageItem.cpp
#include "ImageItem.h"
#include <QImage>
#include <QBitmap>
#include "epaper.h"
#include "StaticImage.h"
#include "EmbeddedFonts.h"

ImageItem::ImageItem(QQuickItem *parent) : QQuickPaintedItem(parent)
{    
    this->current_image = QBitmap::fromData(QSize(400,300), framebuffer, QImage::Format_Mono).toImage();
    srand(clock());
}

void ImageItem::paint(QPainter *painter)
{
    QRectF bounding_rect = boundingRect();
    QImage scaled = this->current_image.scaledToHeight(bounding_rect.height());
    QPointF center = bounding_rect.center() - scaled.rect().center();

    if(center.x() < 0)
        center.setX(0);
    if(center.y() < 0)
        center.setY(0);
   painter->drawImage(center, scaled);
}

QImage ImageItem::image() const
{    return this->current_image;
}

void ImageItem::setImage(const QImage &image)
{
    this->current_image = image;
    update();
}

void ImageItem::refresh() 
{
    QImage img = QBitmap::fromData(QSize(400,300), framebuffer, QImage::Format_Mono).toImage();
    img.invertPixels();
    setImage(img);
}

void ImageItem::demo() 
{
    ::demo();
    refresh();
}

void ImageItem::hLines() 
{
    static int off = 0;
    static int color = 0;
    ::clear(1-color);

    for(int cx = 32+off; cx < EPD_WIDTH; cx += 65)
    {
        for(int cy = 32; cy < EPD_HEIGHT; cy += 65)
        {
            for(int i = 0; i < 32; ++i)
            {
                draw_line(cx-i, cy-i, cx+i, cy-i, color);
                draw_line(cx-i, cy+i, cx+i, cy+i, color);
            }
        }
    }
    
    refresh();
    color = (color + 1) & 0x01;
    ++off;
}

void ImageItem::vLines() 
{
    ::clear(1);
    
    draw_line(0, 0, 0, EPD_HEIGHT-1, 0);
    draw_line(EPD_WIDTH-1, 0, EPD_WIDTH-1, EPD_HEIGHT-1, 0);
    refresh();
}

void ImageItem::fonts() 
{
    ::clear(1);

    static int x0 = -15;
    static int y0 = rand() % EPD_HEIGHT;
    draw_text2("The quick brown fox ÄÖÜ", x0, y0, 0, &lv_font_dejavu_40, 1, 1);
    refresh();
    ++x0;
}
