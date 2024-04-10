extern "C" int printf(const char*, ...);

struct B {
    void foo() { printf("B::foo(): this = 0x%p\n", this); }
};
struct D : public B {
    void bar() { printf("D::bar(): this = 0x%p\n", this); }
};
void (B::*pbfoo)() = &B::foo; // ptr: points to _ZN1B3fooEv, adj: 0
void (D::*pdfoo)() = &D::foo; // ptr: points to _ZN1B3fooEv, adj: 0
void (D::*pdbar)() = &D::bar; // ptr: points to _ZN1D3barEv, adj: 0

extern "C" void _ZN1B3fooEv(B*);
extern "C" void _ZN1D3barEv(D*);
#define PART1_OF_PTR(p)     (((long*)&p)[0])
#define PART2_OF_PTR(p)     (((long*)&p)[1])

int main() {
    printf("&B::foo->ptr: 0x%lX\n", PART1_OF_PTR(pbfoo));
    printf("&B::foo->adj: 0x%lX\n", PART2_OF_PTR(pbfoo));    // 0
    printf("&D::foo->ptr: 0x%lX\n", PART1_OF_PTR(pdfoo));
    printf("&D::foo->adj: 0x%lX\n", PART2_OF_PTR(pdfoo));    // 0
    printf("&D::bar->ptr: 0x%lX\n", PART1_OF_PTR(pdbar));
    printf("&D::bar->adj: 0x%lX\n", PART2_OF_PTR(pdbar));    // 0

    D* d = new D();
    d->foo();
    _ZN1B3fooEv(d); // equal to d->foo()
    d->bar();
    _ZN1D3barEv(d); // equal to d->bar()
    return 0;
}