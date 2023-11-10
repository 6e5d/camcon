#include <cglm/cglm.h>

typedef struct {
	vec3 c;
	float r;
	float xy;
	float p;
} Camcon;

void camcon_compute(Camcon* cc, mat4 result);
void camcon_rotate(Camcon* cc, float dx, float dy);
void camcon_init(Camcon* cc);
