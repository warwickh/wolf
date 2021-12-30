#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <moonlight/protocol.hpp>

TEST_CASE("LocalState load JSON", "[LocalState]") {
  auto state = new LocalState("local_state.json");
  REQUIRE(state->hostname() == "test_wolf");
  REQUIRE(state->get_uuid() == "uid-12345");
  REQUIRE(state->external_ip() == "192.168.99.1");
  REQUIRE(state->local_ip() == "192.168.1.1");
  REQUIRE(state->mac_address() == "AA:BB:CC:DD");

  SECTION("Port mapping") {
    REQUIRE(state->map_port(LocalState::HTTP_PORT) == 3000);
    REQUIRE(state->map_port(LocalState::HTTPS_PORT) == 2995);
  }
}
