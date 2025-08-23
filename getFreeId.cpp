#include"getFreeId.h"
int get_free_id(){
    static int id = 0;
    return id++;
}
