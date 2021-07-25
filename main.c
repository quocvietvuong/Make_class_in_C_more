#include "square.h"
#include "stdio.h"

int main() {
    struct Square* mySquare = Square__create(1, 3, 4, 8);
    printf("Square info: \n");
    Square_print(mySquare);
    struct SquareData* data = Square__square_data(mySquare);
    printf("Print again: \n");
    printf("x: %d", data->x);
    printf("y: %d", data->y);
    printf("width: %d", data->width);
    printf("height: %d", data->height);

    Shape__destroy(Square__to_shape(mySquare));
}