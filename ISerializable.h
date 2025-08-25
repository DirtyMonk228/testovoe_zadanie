#pragma once
#include<QDataStream>
class ISerializable{
public:
    virtual void serialize(QDataStream& out) const = 0;
    virtual void deserialize(QDataStream& in)  = 0;
    virtual ~ISerializable() = default;
};
