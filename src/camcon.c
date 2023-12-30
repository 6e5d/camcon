#include <math.h>

#include "../include/camcon.h"

const static float math_pi = 3.14159265359f;

static void picap(float* x) {
	while (*x < -math_pi) {
		*x += math_pi * 2;
	}
	while (*x >= math_pi) {
		*x -= math_pi * 2;
	}
}

static void piblock(float* x) {
	float max_pitch = math_pi * 0.4999f;
	if (*x < -max_pitch) {
		*x = -max_pitch;
	}
	if (*x >= max_pitch) {
		*x = max_pitch;
	}
}

// the ray of looking(normalized)
void camcon(lookn)(Camcon()* cc, vec3 result) {
	float rpc = cc->r * cosf(cc->p);
	result[0] = rpc * cosf(cc->xy);
	result[1] = cc->r * sinf(cc->p);
	result[2] = rpc * sinf(cc->xy);
	glm_vec3_normalize(result);
}

// observer's position
void camcon(obpos)(Camcon()* cc, vec3 result) {
	float rpc = cc->r * cosf(cc->p);
	vec3 t = {
		rpc * cosf(cc->xy),
		cc->r * sinf(cc->p),
		rpc * sinf(cc->xy),
	};
	glm_vec3_add(t, cc->c, result);
}

void camcon(compute)(Camcon()* cc, mat4 result) {
	vec3 obpos;
	camcon(obpos)(cc, obpos);
	vec3 up = {0.0f, -1.0f, 0.0f};
	glm_lookat(obpos, cc->c, up, result);
}

// relative to view coordinate
void camcon(translate)(Camcon()* cc, vec3 dp) {
	mat4 iview;
	mat3 irot;
	camcon(compute)(cc, iview);
	glm_mat4_inv(iview, iview);
	for (size_t i = 0; i < 3; i += 1) {
		for (size_t j = 0; j < 3; j += 1) {
			irot[i][j] = iview[i][j];
		}
	}
	glm_mat3_mulv(irot, dp, dp);
	glm_vec3_add(dp, cc->c, cc->c);
}

void camcon(init)(Camcon()* cc) {
	*cc = (Camcon()) {
		.c = {0.0f, 0.1f, 0.0f},
		.r = 1.5f,
		.xy = 0.0f,
		.p = 0.2f,
	};
}

void camcon(rotate)(Camcon()* cc, float dx, float dy) {
	cc->xy += dx;
	picap(&cc->xy);
	cc->p += dy;
	piblock(&cc->p);
}
