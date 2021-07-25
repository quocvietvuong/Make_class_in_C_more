#include "square.h"
#include "stdio.h"

const char* Square__name_override(struct Shape* self) {
   return "Square";
}

int Square__sides_override(struct Shape* self) {
   return 4;
}

void Square__destroy_override(struct Shape* square) {
   free(square);
}
 

struct Shape* Square__to_shape(struct Square* square) {
   return ((struct Shape*) square);
}

struct Square* Square__from_shape(struct Shape* shape) {
    if (!shape)  {
        return ((struct Square*) 0);
    }

    struct ShapeType* type = Shape__type(shape);
        if (type != square_type) {
        return ((struct Square*) 0);
    }

    return ((struct Square*) shape);
}

struct SquareData* Square__square_data(struct Square* self) {
   struct Shape* shape = (struct Shape*) self;
   return (struct SquareData*) Shape__buffer(shape);
}

struct Square* Square__create(int x, int y, int width, int height) {
    if (!square_type) {
        square_type = ShapeType__create(
        sizeof(struct SquareData),
        &Square__name_override,
        &Square__sides_override,
        &Square__destroy_override);
    }
   
   struct Square* result = (struct Square*) Shape__create(square_type); // use this only square_type object to create every square
   struct SquareData* square_data = Square__square_data(result);
   square_data->x = x;
   square_data->y = y;
   square_data->width = width;
   square_data->height = height;
   return result;
}

void Square_print(struct Square* square) {
    struct SquareData* squaredata = Square__square_data(square);
    printf("width: %d\n", squaredata->width);
    printf("height: %d\n", squaredata->height);
    printf("x: %d\n", squaredata->x);
    printf("y: %d\n", squaredata->y);
}

void Square__destroy(struct Square* square) {
   Shape__destroy(Square__to_shape(square));
}

int Square__x(struct Square* self) {
   return Square__square_data(self)->x;
}

int Square__y(struct Square* self) {
   return Square__square_data(self)->y;
}   

int Square__width(struct Square* self) {
   return Square__square_data(self)->width;
}

int Square__height(struct Square* self) {
   return Square__square_data(self)->height;
}