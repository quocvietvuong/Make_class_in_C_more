struct Shape;
struct ShapeType;

// typedef struct Shape Shape;
// typedef struct ShapeType ShapeType;

struct ShapeType* ShapeType__create(
    int buffer_size,  // for storing shape data
    const char* (*name)(struct Shape*), // function pointer - returns a string, take a Shape as a param
    int (*sides)(struct Shape*),
    void (*destroy)(struct Shape*)
); // generic type of shape

struct Shape* Shape__create(struct ShapeType* type);
struct ShapeType* Shape__type(struct Shape* self);
void* Shape__buffer(struct Shape* self); // return the shape data
int Shape__sides(struct Shape* self);
void Shape__destroy(struct Shape* shape);