#ifndef CELL_H
#define CELL_H

/*!
 * Définition des constantes permettant de colorer la cellule.
 */
#define BLACK 0x000000
#define WHITE 0xF5F5F5
#define RED 0xFF0000
#define BLUE 0x0000FF
#define GREEN 0x008000
#define PURPLE 0x800080
#define ORANGE 0xFFA500
#define YELLOW 0xFFFF00
#define PINK 0xFFC0CB
#define GREY 0x808080
#define WHITE 0xF5F5F5


class Cell{

private:

    unsigned color;
    bool empty;


public:

Cell(const unsigned color,const bool empty);
Cell (const Cell & cell);

unsigned getColor() const;
void clear();
bool isEmpty() const;
void colorize(const unsigned);
void fill();


};

inline unsigned Cell::getColor() const
{
    return color;
}

inline bool Cell::isEmpty() const
{
    return empty;
}

#endif // CELL_H
