#pragma once

enum lightSaberType { SINGLE_BLADED, DOUBLE_BLADED, CROSS_GUARD };

struct LightSaber
{
	char* color;
	lightSaberType type;
};
