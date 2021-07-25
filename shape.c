#include "shape.h"
#include "stdlib.h"
struct Shape {
    char buffer_start; 
    struct ShapeType* type;
};

struct ShapeType { // class to represent the Shape Type info
    int buffer_size; 
    const char* (*name)(struct Shape*);
    int (*sides)(struct Shape*); // the number of sides
    void (*destroy)(struct Shape*);
}; // polymorphism and dynamic dispatch is implemented here...

struct ShapeType* ShapeType__create(
      int buffer_size,
      const char* (*name)(struct Shape*),
      int (*sides)(struct Shape*),
      void (*destroy)(struct Shape*)) {    
    struct ShapeType* result = (struct ShapeType*) malloc(sizeof(struct ShapeType));
    result->buffer_size = buffer_size;
    result->name = name;
    result->sides = sides;
    result->destroy = destroy;
   return result;
}

struct Shape* Shape__create(struct ShapeType* type) {
  int size = sizeof(struct Shape) + type->buffer_size; // buffer_size: the actual size of the shape data (square_data)
  struct Shape* result = (struct Shape*) malloc(size);
  result->type = type;
  return result;
}

struct ShapeType* Shape__type(struct Shape* self) {
  return self->type; // return the type of shape
}

void* Shape__buffer(struct Shape* self) {
   return (void*) &(self->buffer_start); // return the start position of the Shape
}

int Shape__sides(struct Shape* self) {
  return self->type->sides(self); // return the number of sides
}

void Shape__destroy(struct Shape* shape) {
   if (shape) {
      shape->type->destroy(shape); // when to destroy...
   }
}

