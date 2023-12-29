#ifndef INCLUDEGUARD_CAMCON
#define INCLUDEGUARD_CAMCON

#include <cglm/cglm.h>
#define CglmMat4 mat4
#define CglmMat3 mat3
#define CglmVec3 vec3

typedef struct {
	CglmVec3 c;
	float r;
	float xy;
	float p;
} Camcon();

void camcon(compute)(Camcon()* cc, CglmMat4 result);
void camcon(translate)(Camcon()* cc, CglmVec3 dp);
void camcon(obpos)(Camcon()* cc, CglmVec3 result);
void camcon(lookn)(Camcon()* cc, CglmVec3 result);
void camcon(rotate)(Camcon()* cc, float dx, float dy);
void camcon(init)(Camcon()* cc);

#endif
