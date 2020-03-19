class simple {
    public:
	int do_it(int i) { return (i*2); }
	float do_it(float f) { return (f*2);}
};
class derived: public simple {
    public:
	int do_it(int i, int j) { return (i +j); }
};

int main()
{
    derived var;
    float f;
    int i;

    i = var.do_it(3, 5);	// Works
    f = var.do_it(3.0);		// Fails
    return (0);
}
