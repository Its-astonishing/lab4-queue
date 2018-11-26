#include "Proc.h"

int main(int argc, char **argv)
{
    proc h(10.0, 0.8, 4, 1000, 2);
    h.start();
    h.print();
    system("pause");
}
