#include <cstdio>
#include <cstdlib>

#include "gtest/gtest.h"
#include "types.h"
#include "CameraPerspective.h"

using ::testing::EmptyTestEventListener;
using ::testing::InitGoogleTest;
using ::testing::Test;
using ::testing::TestEventListeners;
using ::testing::TestInfo;
using ::testing::TestPartResult;
using ::testing::UnitTest;

double TOLERANCE = 1.0e-3;

void assertVec(Vec3f a, Vec3f b, double tolerance)
{
    EXPECT_NEAR(a[0], b[0], tolerance);
    EXPECT_NEAR(a[1], b[1], tolerance);
    EXPECT_NEAR(a[2], b[2], tolerance);
};

// Tests factorial of 0.
TEST(CameraPerspective, RayCorners) {
    const Size resolution(800, 600);
    CCameraPerspective cam1(resolution, Vec3f(0, 0, 10), Vec3f(0, 0, -1), Vec3f(0, 1, 0), 60);
    Ray actual;
    Ray expected;
    // Top left corner
    cam1.InitRay(actual, 0, resolution.height);
    expected.dir = Vec3f(-0.5543, -0.415508, -0.721183);
    assertVec(actual.dir, expected.dir, TOLERANCE);

    // Bottom left corner
    cam1.InitRay(actual, 0, 0);
    expected.dir = Vec3f(-0.5543, 0.415508, -0.721183);
    assertVec(actual.dir, expected.dir, TOLERANCE);

    // Bottom right corner
    cam1.InitRay(actual, resolution.width, 0);
    expected.dir = Vec3f(0.5543, 0.415508, -0.721183);
    assertVec(actual.dir, expected.dir, TOLERANCE);

    // Top right corner
    cam1.InitRay(actual, resolution.width, resolution.height);
    expected.dir = Vec3f(0.5543, -0.415508, -0.721183);
    assertVec(actual.dir, expected.dir, TOLERANCE);
}


