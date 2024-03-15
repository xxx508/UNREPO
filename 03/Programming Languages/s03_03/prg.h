#include <stdio.h>
#include <utility>

class set_custom
{
private:
    bool itself[256];

public:
    set_custom()
    {
        bool itself[256];
        for (int i = 0; i < 256; i++)
        {
            itself[i] = 0;
        }
    }
    bool insert(int a)
    {
        if (itself[a])
        {
            printf("This is already in set!\n");
            return 0;
        }
        return itself[a] = 1;
    }
    bool set(int a, bool key)
    {
        itself[a] = key;
    }
    bool swap(int a)
    {
        if (itself[a])
            itself[a] = 0;
        else
            itself[a] = 1;
        return 1;
    }
    set_custom operator-(int a)
    {
        if (!itself[a])
        {
            printf("Element not in set!\n");
            return *this;
        }
        else
        {
            itself[a] = 0;
            return *this;
        }
    }
    bool get(int a)
    {
        return itself[a];
    }
    set_custom operator+(set_custom b)
    {
        set_custom tmp;
        for(int i=0;i<256;i++)
        {
            tmp.set(i, this->get(i) + b.get(i));
        }
        *this = tmp;
        return tmp;
    }
    set_custom operator*(set_custom b)
    {
        set_custom tmp;
        for(int i=0;i<256;i++)
        {
            tmp.set(i, this->get(i) * b.get(i));
        }
        *this = tmp;
        return tmp;
    }
    set_custom operator-(set_custom b)
    {
        set_custom tmp;
        for(int i=0;i<256;i++)
        {
            bool k = b.get(i);

        }
    }
};