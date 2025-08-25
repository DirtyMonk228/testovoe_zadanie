#include "create_shapes_by_type.h"

std::unique_ptr<IShape> create_shapes_by_type(QString type){
    std::unique_ptr<IShape> shape;
    if(type == "Circle"){
        shape = std::make_unique<Circle>(get_free_id());
    }
    else if(type == "Rectangle"){
        shape = std::make_unique<Rectangle>(get_free_id());
    }
    else if(type == "Triangle"){
        shape = std::make_unique<Triangle>(get_free_id());
    }
    return shape;
}
