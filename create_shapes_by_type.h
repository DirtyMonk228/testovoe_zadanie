#pragma once
#include"IShape.h"
#include"circle.h"
#include"rectangle.h"
#include"triangle.h"
#include"getFreeId.h"
std::unique_ptr<IShape> create_shapes_by_type(QString type);
