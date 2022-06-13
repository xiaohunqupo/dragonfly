// Copyright 2022, Roman Gershman.  All rights reserved.
// See LICENSE for licensing terms.
//

#include <jsoncons/json.hpp>

#include "base/gtest.h"
#include "base/logging.h"

namespace dfly {
using namespace std;
using namespace jsoncons;

class JsonTest : public ::testing::Test {
 protected:
  JsonTest() {
  }
};

TEST_F(JsonTest, Basic) {
  string data = R"(
    {
       "application": "hiking",
       "reputons": [
       {
           "rater": "HikingAsylum",
           "assertion": "advanced",
           "rated": "Marilyn C",
           "rating": 0.90,
           "confidence": 0.99
         }
       ]
    }
)";

  json j = json::parse(data);
  EXPECT_TRUE(j.contains("reputons"));
}

}  // namespace dfly