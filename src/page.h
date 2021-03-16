/*page.h*/
//define struct "ppage"
struct ppage {
	struct ppage *next;
	struct ppage *prev;
	void *physical_addr;
};
