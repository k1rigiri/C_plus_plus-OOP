#include "new_fig.h"

int main() {
    Circle c1(2), c2(4), c3(6);
    Rectangle r1(2, 2), r2(5, 2), r3(8, 1);
    Triangle t1(2, 4, 5), t2(11, 9, 8);

    Figure *f[] = { &c1, &r1, &t1, &c2, &r2, &c3, &t2, &r3 };
    for (int i = 0; i < 8; i++) {
        f[i]->show();
    }

    return 0;
}
