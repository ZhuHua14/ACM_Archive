#include<stdio.h>

typedef struct Point{
    int x,y;
} Point;

bool isequal(Point a,Point b){
    return a.x == b.x && a.y == b.y;
}

typedef struct Vector{
    int x,y;
} Vector;

Vector create(Point a,Point b){
    Vector ret;
    ret.x = b.x - a.x;
    ret.y = b.y - a.y;
    return ret;
}

int main(){
    
    return 0;
}