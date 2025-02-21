#ifndef SAMPLY_GUI_H
#define SAMPLY_GUI_H

struct sampler;
struct report;

struct gui {

	sampler* sampler;
	report* report = 0;

	gui(struct sampler* s, struct report* r);

	// Return exit code
	int show();

	// Display our application
	int main();
};

#endif // SAMPLY_GUI_H
