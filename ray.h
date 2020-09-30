// Basic ray structure
// Written by Sergey Kosov in 2005 for Rendering Competition

// Work with Kristian Sterjo

#pragma once

#include "types.h"

/// Basic ray structure
struct Ray
{
	Vec3f	org;		///< Origin
	Vec3f	dir;		///< Direction
	float	t;			///< Current/maximum hit distance
};
