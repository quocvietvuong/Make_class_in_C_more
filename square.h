#include "stdlib.h"
#include "shape.h"

struct Square;
struct Shape* Square__to_shape(struct Square* square);
struct Square* Square__from_shape(struct Shape* shape);
struct Square* Square__create(int x, int y, int width, int height);
void Square__destroy(struct Square* square);

// Similar to the accessors in the prior case
int Square__x(struct Square* self);    
int Square__y(struct Square* self);    
int Square__width(struct Square* self);    
int Square__height(struct Square* self);

static struct ShapeType* square_type; // an extra object that represents the type of shape, performing dynamic dispatch

struct SquareData {
   int x;
   int y;
   int width;
   int height;
};

const char* Square__name_override(struct Shape* self);

int Square__sides_override(struct Shape* self);

void Square__destroy_override(struct Shape* square);

struct Shape* Square__to_shape(struct Square* square);

struct Square* Square__from_shape(struct Shape* shape);

struct SquareData* Square__square_data(struct Square* self);

struct Square* Square__create(int x, int y, int width, int height);

void Square_print(struct Square* square);

void Square__destroy(struct Square* square);

int Square__x(struct Square* self);

int Square__y(struct Square* self);

int Square__width(struct Square* self);

int Square__height(struct Square* self);