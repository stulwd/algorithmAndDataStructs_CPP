#ifndef COMPARABLE_H
#define COMPARABLE_H

class Comparable
{
private:
    /* data */
public:
    Comparable(/* args */);
    virtual bool compare(Comparable* ) = 0;
    ~Comparable();
};


#endif
