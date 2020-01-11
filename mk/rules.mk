$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

test_runner:
	cxxtestgen --error-printer -o $@.cpp $(TESTS)
	$(CXX) $(CXXFLAGS) -o $@ $@.cpp -Icxxtest

test_runner_debug:
	cxxtestgen --error-printer -o $@.cpp $(TESTS)
	$(CXX) -std=c++2a -g -o $@ $@.cpp -Icxxtest

test: test_runner
	-./test_runner
	$(RM) test_runner test_runner.cpp

testDebug: test_runner_debug
	-gdb ./test_runner_debug
	$(RM) test_runner_debug test_runner_debug.cpp

clean:
	$(RM) -r $(BUILD_DIR) test_runner*
