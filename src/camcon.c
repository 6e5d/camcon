#include <math.h>
#include <cglm/cglm.h>

#include "../include/camcon.h"

static const float S1 = 0.01f;
static const float S2 = 0.01f;
static const float S3 = 0.002f;
static const float PI = (float)M_PI;
static const float MAX_PITCH = PI * 0.4999f;

static void picap(float* x) {
	while (*x < -PI) {
		*x += PI * 2;
	}
	while (*x >= PI) {
		*x -= PI * 2;
	}
}

static void piblock(float* x) {
	if (*x < -MAX_PITCH) {
		*x = -MAX_PITCH;
	}
	if (*x >= MAX_PITCH) {
		*x = MAX_PITCH;
	}
}

// observer's position
void camcon_obpos(Camcon* cc, vec3 result) {
	float rpc = cc->r * cosf(cc->p);
	vec3 t = {
		rpc * cosf(cc->xy),
		cc->r * sinf(cc->p),
		rpc * sinf(cc->xy),
	};
	glm_vec3_add(t, cc->c, result);
}

void camcon_compute(Camcon* cc, mat4 result) {
	vec3 obpos;
	camcon_obpos(cc, obpos);
	vec3 up = {0.0f, -1.0f, 0.0f};
	glm_lookat(obpos, cc->c, up, result);
}

void camcon_init(Camcon* cc) {
	*cc = (Camcon) {
		.c = {0.0f, 1.0f, 0.0f},
		.r = 5.0f,
		.xy = 0.0f,
		.p = 0.1f,
	};
}

void camcon_rotate(Camcon* cc, float dx, float dy) {
	cc->xy += dx;
}
