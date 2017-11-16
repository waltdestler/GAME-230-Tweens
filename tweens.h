#pragma once

template<typename T>
T lerp(T start, T end, float t)
{
	return start + (end - start) * t;
}

template<typename T>
T easeIn(T start, T end, float t)
{
	return start + (end - start) * t * t * t;
}

template<typename T>
T easeOut(T start, T end, float t)
{
	--t;
	return start + (end - start) * (t * t * t + 1);
}

template<typename T>
T easeInOut(T start, T end, float t)
{
	return start + (end - start) * (t * t * (3.0f - 2.0f * t));
}

template<typename T>
T easeOutBack(T start, T end, float t)
{
	const float s = 1.70158f;
	--t;
	return start + (end - start) * (t * t * ((s + 1) * t + s) + 1);
}

template<typename T>
T easeOutBounce(T start, T end, float t)
{
	if (t < (1 / 2.75f)) {
		return start + (end - start) * (7.5625f*t*t);
	}
	else if (t < (2 / 2.75f)) {
		float postFix = t -= (1.5f / 2.75f);
		return start + (end - start) * (7.5625f*(postFix)*t + .75f);
	}
	else if (t < (2.5 / 2.75)) {
		float postFix = t -= (2.25f / 2.75f);
		return start + (end - start) * (7.5625f*(postFix)*t + .9375f);
	}
	else {
		float postFix = t -= (2.625f / 2.75f);
		return start + (end - start) * (7.5625f*(postFix)*t + .984375f);
	}
}