#include <cglm/cglm.h>

typedef struct {
	vec3 c;
	float r;
	float xy;
	float p;
} Camcon();

void camcon(compute)(Camcon()* cc, mat4 result);
void camcon(translate)(Camcon()* cc, vec3 dp);
void camcon(obpos)(Camcon()* cc, vec3 result);
void camcon(lookn)(Camcon()* cc, vec3 result);
void camcon(rotate)(Camcon()* cc, float dx, float dy);
void camcon(init)(Camcon()* cc);
